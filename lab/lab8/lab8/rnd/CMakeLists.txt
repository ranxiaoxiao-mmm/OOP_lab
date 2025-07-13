cmake_minimum_required(VERSION 3.20)

project(gui)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#include(FetchContent)
#FetchContent_Declare(SFML
#    URL file://${CMAKE_SOURCE_DIR}/3rd/SFML-2.6.2.zip
#    )
#FetchContent_MakeAvailable(SFML)

add_executable(gui window.cpp shapes.cpp rnd.cpp)
target_compile_features(gui PRIVATE cxx_std_17)

target_include_directories(gui PRIVATE ${CMAKE_SOURCE_DIR}/3rd/include)
target_link_directories(gui PRIVATE ${CMAKE_SOURCE_DIR}/3rd/lib)
target_link_libraries(gui PRIVATE sfml-audio sfml-graphics sfml-network sfml-system sfml-window)
