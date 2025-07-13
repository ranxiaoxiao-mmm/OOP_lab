#pragma once

#include <string>
#include <functional>
#include <vector>
#include <stdexcept>
#include <iostream>

// 存储测试用例
struct TestCase {
    std::string name;
    std::function<void()> func;
};
static inline std::vector<TestCase> test_cases;

// 测试宏定义
#define TEST(PREFIX, name) \
    void PREFIX##_##name(); \
    struct Register##PREFIX##_##name { \
        Register##PREFIX##_##name() { \
            test_cases.push_back({#PREFIX "_" #name, PREFIX##_##name}); \
        } \
    } register##PREFIX##_##name; \
    void PREFIX##_##name()

class TestFailure : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            throw TestFailure(std::string("Assert failed: ") + #condition); \
        } \
    } while(0)

#define ASSERT_EQ(expected, actual) \
    do { \
        if (!((expected) == (actual))) { \
            throw TestFailure(std::string("Assert equal failed: expected ") + \
                            #expected + " got " + #actual); \
        } \
    } while(0)

#define TEST_MAIN() \
int main() { \
    std::cout << "Running " << test_cases.size() << " tests...\n"; \
    int passed = 0, failed = 0; \
    for(const auto& test : test_cases) { \
        std::cout << "Test: " << test.name << " ... "; \
        try { \
            test.func(); \
            std::cout << "\033[32mOK\033[0m\n"; \
            ++passed; \
        } catch (const TestFailure& e) { \
            std::cout << "\033[31mFAILED\033[0m\n"; \
            std::cout << "    " << e.what() << "\n"; \
            ++failed; \
        } \
    } \
    std::cout << "\nTest Summary:\n" \
              << "  Passed: " << passed << "\n" \
              << "  Failed: " << failed << "\n"; \
    return failed > 0 ? 1 : 0; \
}
