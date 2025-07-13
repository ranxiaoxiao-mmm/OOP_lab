cmake_minimum_required(VERSION 3.20)

project(lab7-review)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

list(APPEND SRCS static inherit sample date stack)
list(APPEND NUMS 1 2 3 4 5)
foreach(num src IN ZIP_LISTS NUMS SRCS)
    add_executable(${src} "${num}${src}.cpp")
endforeach()

# add_executable(staticx 1static.cpp)
# add_executable(inherit 2inherit.cpp)
# add_executable(sample 3sample.cpp)
# add_executable(date 4date.cpp)
# add_executable(stack 5stack.cpp)

