cmake_minimum_required(VERSION 3.25)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
project(nameserver)

add_executable(nsvector)
target_sources(nsvector PRIVATE nsvector.cc nstest.cc split.cc PUBLIC stopwatch.h)
target_compile_options(nsvector PUBLIC -O3 -std=c++23)

add_executable(nsmap)
target_sources(nsmap PRIVATE nsmap.cc nstest.cc split.cc PUBLIC stopwatch.h)
target_compile_options(nsmap PUBLIC -O3 -std=c++23)

add_executable(nsumap) 
target_sources(nsumap PRIVATE nsumap.cc nstest.cc split.cc PUBLIC stopwatch.h)
target_compile_options(nsumap PUBLIC -O3 -std=c++23)
