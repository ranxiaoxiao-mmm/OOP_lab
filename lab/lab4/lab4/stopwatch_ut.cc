#include <gtest/gtest.h>
#include <thread>
#include "stopwatch.h"  // Assuming the previous Stopwatch class is in this header

class StopwatchTest : public ::testing::Test {
protected:
    Stopwatch sw;

    void SetUp() override {
        sw.reset();
    }
};

// Test basic start/stop functionality
TEST_F(StopwatchTest, BasicTiming) {
    sw.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    sw.stop();
    
    double ms = sw.getDuration(Stopwatch::TimeUnit::Milliseconds);
    EXPECT_GE(ms, 95.0);  // Allow some timing variance
    EXPECT_LE(ms, 150.0); // Upper bound with some buffer
}

// Test different time units
TEST_F(StopwatchTest, TimeUnits) {
    sw.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    sw.stop();

    double ns = sw.getDuration(Stopwatch::TimeUnit::Nanoseconds);
    double us = sw.getDuration(Stopwatch::TimeUnit::Microseconds);
    double ms = sw.getDuration(Stopwatch::TimeUnit::Milliseconds);
    double s = sw.getDuration(Stopwatch::TimeUnit::Seconds);

    EXPECT_GE(ns, 9'000'000.0);
    EXPECT_LE(ns, 15'000'000.0);
    EXPECT_GE(us, 9'000.0);
    EXPECT_LE(us, 15'000.0);
    EXPECT_GE(ms, 9.0);
    EXPECT_LE(ms, 15.0);
    EXPECT_GE(s, 0.009);
    EXPECT_LE(s, 0.015);
}


// Test timing while running
TEST_F(StopwatchTest, DurationWhileRunning) {
    sw.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    double running_duration = sw.getDuration();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    sw.stop();
    double final_duration = sw.getDuration();

    EXPECT_GE(running_duration, 45.0);
    EXPECT_LE(running_duration, 75.0);
    EXPECT_GE(final_duration, 95.0);
    EXPECT_LE(final_duration, 150.0);
    EXPECT_GT(final_duration, running_duration);
}

// Test reset functionality
TEST_F(StopwatchTest, Reset) {
    sw.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    sw.reset();
    
    EXPECT_FALSE(sw.isRunning());
}

// Main function for running tests
// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }