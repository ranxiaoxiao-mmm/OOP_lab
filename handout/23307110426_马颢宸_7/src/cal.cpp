#include "cal.h"
#include <getopt.h>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fmt/core.h>
#include <algorithm> 

// CommandLineParser实现
CommandLineParser::Options CommandLineParser::parse(int argc, char* argv[]) {
    optind = 1; // 让 getopt 从头开始解析参数
    Options opts;
    // 使用 getopt 解析参数
    int opt;
    while ((opt = getopt(argc, argv, "A:B:d:r:m:")) != -1) {
        switch (opt) {
            case 'A': 
                opts.monthsAfter = std::stoi(optarg); 
                break;
            case 'B': 
                opts.monthsBefore = std::stoi(optarg); 
                break;
            case 'd': // 解析 -d yyyy-mm
                sscanf(optarg, "%d-%d", &opts.year, &opts.month);
                opts.isMonthSpecified = true;
                break;
            case 'r': 
                opts.rowMonths = std::stoi(optarg); 
                break;
            case 'm': 
                // 支持数字和英文月份
                std::string mstr(optarg);
                static const std::string monthNames[] = {
                    "january", "february", "march", "april", "may", "june",
                    "july", "august", "september", "october", "november", "december"
                };
                int monthNum = 0;
                // 判断是否为纯数字
                if (std::all_of(mstr.begin(), mstr.end(), ::isdigit)) {
                    monthNum = std::stoi(mstr);
                } else {
                    // 转小写
                    std::transform(mstr.begin(), mstr.end(), mstr.begin(), ::tolower);
                    for (int i = 0; i < 12; ++i) {
                        if (mstr == monthNames[i]) {
                            monthNum = i + 1;
                            break;
                        }
                    }
                }
                if (monthNum >= 1 && monthNum <= 12) {
                    opts.month = monthNum;
                    opts.isMonthSpecified = true;
                }
                break;

        }
    }
    
    // 处理单独的年份参数（如 `cal 2025`）
    for (int i = optind; i < argc; ++i) {
        opts.year = std::stoi(argv[i]);
        opts.isYearSpecified = true;
    }
    
    return opts;
}

// CalendarGenerator实现
std::vector<CalendarGenerator::MonthData> CalendarGenerator::generate(const CommandLineParser::Options& options) {
    std::vector<MonthData> result;
    
    // 确定起始月份
    int year = options.year ? options.year : getCurrentYear();
    int month = options.month ? options.month : getCurrentMonth();
    
    // 如果只指定了年份，显示全年
    if (options.isYearSpecified && !options.isMonthSpecified) {
        for (int m = 1; m <= 12; ++m) {
            MonthData data;
            data.year = year;
            data.month = m;
            data.title = getMonthName(m) + " " + std::to_string(year);
            data.weeks = generateWeekLines(year, m);
            result.push_back(data);
        }
    } else {
        // 生成指定范围的月份
        for (int i = -options.monthsBefore; i <= options.monthsAfter; ++i) {
            // 计算当前偏移量的年月
            int currentMonth = month + i;
            int currentYear = year;
            
            // 处理月份溢出
            while (currentMonth <= 0) {
                currentMonth += 12;
                currentYear--;
            }
            while (currentMonth > 12) {
                currentMonth -= 12;
                currentYear++;
            }
            
            MonthData data;
            data.year = currentYear;
            data.month = currentMonth;
            data.title = getMonthName(currentMonth) + " " + std::to_string(currentYear);
            data.weeks = generateWeekLines(currentYear, currentMonth);
            result.push_back(data);
        }
    }
    
    return result;
}

int CalendarGenerator::getFirstDayOfWeek(int year, int month) {
    // 使用Zeller公式计算某月第一天是星期几
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (1 + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
    
    // 转换为星期日为0的表示
    return (h + 6) % 7; //0=sunday, 1=monday, ..., 6=saturday  
}

bool CalendarGenerator::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CalendarGenerator::getDaysInMonth(int year, int month) {
    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month];
}

std::string CalendarGenerator::getMonthName(int month) {
    static const std::string monthNames[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return monthNames[month];
}

std::vector<std::string> CalendarGenerator::generateWeekLines(int year, int month) {
    std::vector<std::string> weeks(6); // 最多6行
    int firstDay = getFirstDayOfWeek(year, month);
    int daysInMonth = getDaysInMonth(year, month);
    int day = 1;
    for (int week = 0; week < 6; ++week) {
        std::stringstream ss;
        for (int wday = 0; wday < 7; ++wday) {
            if ((week == 0 && wday < firstDay) || day > daysInMonth) {
                ss << "   "; // 3个空格
            } else {
                ss << std::setw(2) << day << " ";
                day++;
            }
        }
        std::string line = ss.str();
        weeks[week] = line;
    }
    return weeks;
}

int CalendarGenerator::getCurrentYear() {
    time_t now = time(nullptr);
    struct tm* timeinfo = localtime(&now);
    return timeinfo->tm_year + 1900;
}

int CalendarGenerator::getCurrentMonth() {
    time_t now = time(nullptr);
    struct tm* timeinfo = localtime(&now);
    return timeinfo->tm_mon + 1;
}

// CalendarRenderer实现
std::string CalendarRenderer::render(const std::vector<CalendarGenerator::MonthData>& months, int rowMonths) {
    std::stringstream ss;
    
    for (size_t i = 0; i < months.size(); i += rowMonths) {
        // 横向拼接 rowMonths 个月的日历
        std::vector<std::string> titleLines;
        std::vector<std::string> weekdayHeaderLines;
        
        // 准备标题行和星期标题行
        for (int j = 0; j < rowMonths && (i + j) < months.size(); ++j) {
            titleLines.push_back(formatMonthTitle(months[i + j].title));
            weekdayHeaderLines.push_back(getWeekdayHeader());
        }
        
        // 输出标题行
        ss << formatWeekLine(titleLines) << "\n";
        
        // 输出星期标题行
        ss << formatWeekLine(weekdayHeaderLines) << "\n";
        
        // 输出每周的日期行
        for (int weekIdx = 0; weekIdx < 6; ++weekIdx) {
            std::vector<std::string> weekLines;
            bool hasContent = false;
            
            for (int j = 0; j < rowMonths && (i + j) < months.size(); ++j) {
                if (weekIdx < months[i + j].weeks.size()) {
                    weekLines.push_back(months[i + j].weeks[weekIdx]);
                    if (!months[i + j].weeks[weekIdx].empty()) {
                        hasContent = true;
                    }
                } 
            }
            
            // 只有当行有内容时才输出
            if (hasContent) {
                ss << formatWeekLine(weekLines) << "\n";
            }
        }
        
        // 在不同月份块之间添加空行
        if (i + rowMonths < months.size()) {
            ss << "\n";
        }
    }
    
    return ss.str();
}

std::string CalendarRenderer::formatWeekLine(const std::vector<std::string>& lines) {
    std::string result;
    for (size_t i = 0; i < lines.size(); ++i) {
        std::string line = lines[i];
        if (line.length() < 20) line += std::string(20 - line.length(), ' ');
        result += line;
        if (i < lines.size() - 1) {
            result += "  "; // 两个空格分隔不同月份
        }
    }
    return result;
}

std::string CalendarRenderer::formatMonthTitle(const std::string& title) {
    // 居中显示月份标题
    std::stringstream ss;
    int padding = (21 - title.length()) / 2;
    ss << std::string(padding, ' ') << title << std::string(21 - title.length() - padding, ' ');
    return ss.str();
}

std::string CalendarRenderer::getWeekdayHeader() {
    return "Su Mo Tu We Th Fr Sa ";
}

// CalendarApp实现
CalendarApp::CalendarApp() : parser(), generator(), renderer() {
    // 初始化各个组件
}

void CalendarApp::run(int argc, char* argv[]) {
    // 解析命令行参数
    CommandLineParser::Options options = parser.parse(argc, argv);
    
    // 生成日历数据
    std::vector<CalendarGenerator::MonthData> monthsData = generator.generate(options);
    
    // 渲染日历
    std::string calendarOutput = renderer.render(monthsData, options.rowMonths);
    
    // 输出结果
    std::cout << calendarOutput;
}
