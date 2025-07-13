cmake_minimum_required(VERSION 3.22)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

project(lab6)

# add gtest lib for testing
enable_testing()

# use fechContent to download gtest
include(FetchContent)
FetchContent_Declare(
    GTest
    VERSION v1.16.0
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
FetchContent_MakeAvailable(GTest)

# or use find_package to find gtest: YOU need to config VCPKG package manager
# find_package(GTest CONFIG REQUIRED)

add_executable(vec_test vec_test.cpp)
target_link_libraries(vec_test PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
