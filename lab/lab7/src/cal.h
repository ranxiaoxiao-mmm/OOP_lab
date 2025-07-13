#ifndef CAL_H
#define CAL_H

#include <string>
#include <vector>

// CommandLineParser类定义
class CommandLineParser {
public:
    struct Options {
        int year = 0;               // 指定年份（默认为当前年）
        int month = 0;              // 指定月份（默认为当前月）
        int monthsBefore = 0;       // -B 参数值
        int monthsAfter = 0;        // -A 参数值
        int rowMonths = 3;          // -r 参数值（默认3个月/行）
        bool isYearSpecified = false; // 是否单独指定了年份（如 `cal 2025`）
        bool isMonthSpecified = false; // 是否指定了月份（如 `-m 5` 或 `-d yyyy-mm`）
    };

    static Options parse(int argc, char* argv[]); // 解析命令行参数
};

// CalendarGenerator类定义
class CalendarGenerator {
public:
    struct MonthData {
        int year;
        int month;
        std::string title;          // 月份标题（如 "May 2025"）
        std::vector<std::string> weeks; // 每周的字符串表示（如 " 1  2  3 ... 31"）
    };

    std::vector<MonthData> generate(const CommandLineParser::Options& options);
    int getCurrentYear();                       // 获取当前年份
    int getCurrentMonth();                      // 获取当前月份

private:
    int getFirstDayOfWeek(int year, int month); // 计算某月第一天的星期
    bool isLeapYear(int year);                  // 判断闰年
    int getDaysInMonth(int year, int month);    // 获取月份的天数
    std::string getMonthName(int month);        // 获取月份名称
    std::vector<std::string> generateWeekLines(int year, int month); // 生成周数据

};

// CalendarRenderer类定义
class CalendarRenderer {
public:
    std::string render(const std::vector<CalendarGenerator::MonthData>& months, int rowMonths);

private:
    std::string formatWeekLine(const std::vector<std::string>& lines); // 格式化一周的行
    std::string formatMonthTitle(const std::string& title);           // 格式化月份标题
    std::string getWeekdayHeader();                                   // 获取星期标题行
};

// CalendarApp类定义
class CalendarApp {
public:
    CalendarApp();
    void run(int argc, char* argv[]); // 主流程控制

private:
    CommandLineParser parser;
    CalendarGenerator generator;
    CalendarRenderer renderer;
};

#endif // CAL_H