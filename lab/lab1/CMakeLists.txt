cmake_minimum_required(VERSION 3.25)

project(prime)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(prime)

target_sources(prime
	PRIVATE
	prime.cpp
)

add_executable(prime_re)

target_sources(prime_re
	PRIVATE
	prime_re.cpp
)

target_compile_features(prime PUBLIC cxx_std_23)
