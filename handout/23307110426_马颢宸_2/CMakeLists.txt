cmake_minimum_required(VERSION  3.25)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

project(lab2)

# E2_1
add_executable(E2_1 E2_1.cc)
target_compile_options(E2_1 PUBLIC -O3)
target_compile_features(E2_1 PUBLIC cxx_std_23)

# prime
add_executable(prime prime.cc prime_main.cc)
target_compile_options(prime PUBLIC -O3)
target_compile_features(prime PUBLIC cxx_std_23)

