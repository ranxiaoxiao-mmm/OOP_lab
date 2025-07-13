cmake_minimum_required(VERSION 3.25)
project(ackermann)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})
project(lab03)

#add_executable(E211 E211.cc)
#target_compile_options(E211 PUBLIC -std=c++23)

add_executable(E211_NEW E211_NEW.cc)
target_compile_options(E211_NEW PUBLIC -std=c++23)

#add_executable(E212 E212.cc)
#target_compile_options(E212 PUBLIC -std=c++23)


#add_executable(E213 E213.cc)
#target_compile_options(E213 PUBLIC -std=c++23)

#add_executable(grid grid.cc grid_main.cc)
#target_compile_options(grid PUBLIC -std=c++23)
