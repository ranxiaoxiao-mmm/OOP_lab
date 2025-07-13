cmake_minimum_required(VERSION 3.23)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

project(bignum)

add_executable(bignum)
target_sources(bignum
    PRIVATE
        bignum.cc
        bignum_test.cc
)

# if use GTest, you should use these cmake commands
find_package(GTest CONFIG REQUIRED)
target_link_libraries(bignum
     PRIVATE
         GTest::gtest
         GTest::gtest_main
 )