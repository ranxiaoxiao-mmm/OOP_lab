cmake_minimum_required(VERSION 3.23)
project(cal_command)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)

# 主程序
add_executable(cal src/main_cal.cpp src/cal.cpp)
target_link_libraries(cal PRIVATE fmt::fmt)
target_include_directories(cal PRIVATE ${CMAKE_SOURCE_DIR}/src)

# 测试程序
add_executable(cal_test test/cal_test.cpp src/cal.cpp)
target_link_libraries(cal_test PRIVATE fmt::fmt)
target_include_directories(cal_test PRIVATE ${CMAKE_SOURCE_DIR}/src)

enable_testing()
add_test(NAME cal_test COMMAND cal_test)