#include "cal.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>


// 简单断言宏
#define ASSERT_TRUE(cond) do { \
    if (!(cond)) { \
        std::cout << "[FAILED] " << __FUNCTION__ << " at line " << __LINE__ << ": " #cond << std::endl; \
        return false; \
    } \
} while(0)

#define ASSERT_EQ(a, b) do { \
    if (!((a) == (b))) { \
        std::cout << "[FAILED] " << __FUNCTION__ << " at line " << __LINE__ << ": " #a " == " #b << " (" << (a) << " != " << (b) << ")" << std::endl; \
        return false; \
    } \
} while(0)

// =================== 单元测试 ===================

// CommandLineParser 单元测试
bool test_CommandLineParser_parse_year_only() {
    const char* argv[] = {"cal", "2025"};
    auto opts = CommandLineParser::parse(2, const_cast<char**>(argv));
    ASSERT_TRUE(opts.isYearSpecified);
    ASSERT_EQ(opts.year, 2025);
    ASSERT_TRUE(!opts.isMonthSpecified);
    return true;
}

bool test_CommandLineParser_parse_year_and_month() {
    const char* argv[] = {"cal", "-d", "2025-5"};
    auto opts = CommandLineParser::parse(3, const_cast<char**>(argv));
    ASSERT_TRUE(opts.isMonthSpecified);
    ASSERT_EQ(opts.year, 2025);
    ASSERT_EQ(opts.month, 5);
    return true;
}

bool test_CommandLineParser_parse_months_after() {
    const char* argv[] = {"cal", "-A", "2"};
    auto opts = CommandLineParser::parse(3, const_cast<char**>(argv));
    ASSERT_EQ(opts.monthsAfter, 2);
    CalendarGenerator gen;
    int currentYear = gen.getCurrentYear();
    int currentMonth = gen.getCurrentMonth();
    return true;
}

bool test_CommandLineParser_parse_months_before() {
    const char* argv[] = {"cal", "-B", "2"};
    auto opts = CommandLineParser::parse(3, const_cast<char**>(argv));
    ASSERT_EQ(opts.monthsBefore, 2);
    CalendarGenerator gen;
    int currentYear = gen.getCurrentYear();
    int currentMonth = gen.getCurrentMonth();
    return true;
}

// CalendarGenerator 单元测试
bool test_CalendarGenerator_generate_single_month() {
    CalendarGenerator gen;
    CommandLineParser::Options opts;
    opts.year = 2025;
    opts.month = 5;
    opts.isMonthSpecified = true;
    auto result = gen.generate(opts);
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0].year, 2025);
    ASSERT_EQ(result[0].month, 5);
    return true;
}

bool test_CalendarGenerator_generate_full_year() {
    CalendarGenerator gen;
    CommandLineParser::Options opts;
    opts.year = 2025;
    opts.isYearSpecified = true;
    auto result = gen.generate(opts);
    ASSERT_EQ(result.size(), 12);
    ASSERT_EQ(result[0].month, 1);
    ASSERT_EQ(result[11].month, 12);
    return true;
}

bool test_CalendarGenerator_leap_year_february() {
    CalendarGenerator gen;
    CommandLineParser::Options opts;
    opts.year = 2024;
    opts.month = 2;
    opts.isMonthSpecified = true;
    auto result = gen.generate(opts);
    ASSERT_EQ(result.size(), 1);
    bool has29 = false;
    for (const auto& week : result[0].weeks) {
        if (week.find("29") != std::string::npos) {
            has29 = true;
            break;
        }
    }
    ASSERT_TRUE(has29);
    return true;
}

// CalendarRenderer 单元测试
bool test_CalendarRenderer_render_single_month() {
    CalendarGenerator gen;
    CalendarRenderer renderer;
    CommandLineParser::Options opts;
    opts.year = 2025;
    opts.month = 5;
    opts.isMonthSpecified = true;
    auto months = gen.generate(opts);
    std::string output = renderer.render(months, 1);
    ASSERT_TRUE(output.find("May 2025") != std::string::npos);
    ASSERT_TRUE(output.find("Su Mo Tu We Th Fr Sa") != std::string::npos);
    return true;
}

// =================== 集成测试 ===================

bool test_Integration_CalendarApp() {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    const char* argv[] = {"cal", "2025"};
    CalendarApp app;
    app.run(2, const_cast<char**>(argv));
    std::cout.rdbuf(old);
    std::string output = buffer.str();
    ASSERT_TRUE(output.find("January 2025") != std::string::npos);
    ASSERT_TRUE(output.find("February 2025") != std::string::npos);
    ASSERT_TRUE(output.find("December 2025") != std::string::npos);
    return true;
}

// =================== 测试入口 ===================

int main() {
    int total = 0, passed = 0;

    // 单元测试
    std::cout << "Running unit tests..." << std::endl;
    if (test_CommandLineParser_parse_year_only()) ++passed; ++total;
    if (test_CommandLineParser_parse_year_and_month()) ++passed; ++total;
    if (test_CommandLineParser_parse_months_after()) ++passed; ++total;
    if (test_CommandLineParser_parse_months_before()) ++passed; ++total;
    if (test_CalendarGenerator_generate_single_month()) ++passed; ++total;
    if (test_CalendarGenerator_generate_full_year()) ++passed; ++total;
    if (test_CalendarGenerator_leap_year_february()) ++passed; ++total;
    if (test_CalendarRenderer_render_single_month()) ++passed; ++total;

    // 集成测试
    std::cout << "Running integration tests..." << std::endl;
    if (test_Integration_CalendarApp()) ++passed; ++total;

    std::cout << "Test passed: " << passed << "/" << total << std::endl;
    return (passed == total) ? 0 : 1;
}