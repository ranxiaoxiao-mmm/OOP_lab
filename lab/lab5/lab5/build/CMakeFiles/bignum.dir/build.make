# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:/Archive/subject/two two/OOP/lab/lab5/lab5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:/Archive/subject/two two/OOP/lab/lab5/lab5/build"

# Include any dependencies generated for this target.
include CMakeFiles/bignum.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bignum.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bignum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bignum.dir/flags.make

CMakeFiles/bignum.dir/bignum.cc.obj: CMakeFiles/bignum.dir/flags.make
CMakeFiles/bignum.dir/bignum.cc.obj: CMakeFiles/bignum.dir/includes_CXX.rsp
CMakeFiles/bignum.dir/bignum.cc.obj: D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bignum.cc
CMakeFiles/bignum.dir/bignum.cc.obj: CMakeFiles/bignum.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:/Archive/subject/two two/OOP/lab/lab5/lab5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bignum.dir/bignum.cc.obj"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bignum.dir/bignum.cc.obj -MF CMakeFiles/bignum.dir/bignum.cc.obj.d -o CMakeFiles/bignum.dir/bignum.cc.obj -c "D:/Archive/subject/two two/OOP/lab/lab5/lab5/bignum.cc"

CMakeFiles/bignum.dir/bignum.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bignum.dir/bignum.cc.i"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/Archive/subject/two two/OOP/lab/lab5/lab5/bignum.cc" > CMakeFiles/bignum.dir/bignum.cc.i

CMakeFiles/bignum.dir/bignum.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bignum.dir/bignum.cc.s"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/Archive/subject/two two/OOP/lab/lab5/lab5/bignum.cc" -o CMakeFiles/bignum.dir/bignum.cc.s

CMakeFiles/bignum.dir/bignum_test.cc.obj: CMakeFiles/bignum.dir/flags.make
CMakeFiles/bignum.dir/bignum_test.cc.obj: CMakeFiles/bignum.dir/includes_CXX.rsp
CMakeFiles/bignum.dir/bignum_test.cc.obj: D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bignum_test.cc
CMakeFiles/bignum.dir/bignum_test.cc.obj: CMakeFiles/bignum.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:/Archive/subject/two two/OOP/lab/lab5/lab5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bignum.dir/bignum_test.cc.obj"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bignum.dir/bignum_test.cc.obj -MF CMakeFiles/bignum.dir/bignum_test.cc.obj.d -o CMakeFiles/bignum.dir/bignum_test.cc.obj -c "D:/Archive/subject/two two/OOP/lab/lab5/lab5/bignum_test.cc"

CMakeFiles/bignum.dir/bignum_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bignum.dir/bignum_test.cc.i"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:/Archive/subject/two two/OOP/lab/lab5/lab5/bignum_test.cc" > CMakeFiles/bignum.dir/bignum_test.cc.i

CMakeFiles/bignum.dir/bignum_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bignum.dir/bignum_test.cc.s"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:/Archive/subject/two two/OOP/lab/lab5/lab5/bignum_test.cc" -o CMakeFiles/bignum.dir/bignum_test.cc.s

# Object files for target bignum
bignum_OBJECTS = \
"CMakeFiles/bignum.dir/bignum.cc.obj" \
"CMakeFiles/bignum.dir/bignum_test.cc.obj"

# External object files for target bignum
bignum_EXTERNAL_OBJECTS =

D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe: CMakeFiles/bignum.dir/bignum.cc.obj
D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe: CMakeFiles/bignum.dir/bignum_test.cc.obj
D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe: CMakeFiles/bignum.dir/build.make
D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe: D:/anaconda/Library/lib/gtest.lib
D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe: D:/anaconda/Library/lib/gtest_main.lib
D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe: D:/anaconda/Library/lib/gtest.lib
D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe: CMakeFiles/bignum.dir/linkLibs.rsp
D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe: CMakeFiles/bignum.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:/Archive/subject/two two/OOP/lab/lab5/lab5/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable \"D:/Archive/subject/two two/OOP/lab/lab5/lab5/bin/bignum.exe\""
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/bignum.dir/objects.a
	C:/mingw64/bin/ar.exe qc CMakeFiles/bignum.dir/objects.a @CMakeFiles/bignum.dir/objects1.rsp
	C:/mingw64/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/bignum.dir/objects.a -Wl,--no-whole-archive -o "D:/Archive/subject/two two/OOP/lab/lab5/lab5/bin/bignum.exe" -Wl,--out-implib,"D:/Archive/subject/two two/OOP/lab/lab5/lab5/bin/libbignum.dll.a" -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/bignum.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/bignum.dir/build: D:/Archive/subject/two\ two/OOP/lab/lab5/lab5/bin/bignum.exe
.PHONY : CMakeFiles/bignum.dir/build

CMakeFiles/bignum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bignum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bignum.dir/clean

CMakeFiles/bignum.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "D:/Archive/subject/two two/OOP/lab/lab5/lab5" "D:/Archive/subject/two two/OOP/lab/lab5/lab5" "D:/Archive/subject/two two/OOP/lab/lab5/lab5/build" "D:/Archive/subject/two two/OOP/lab/lab5/lab5/build" "D:/Archive/subject/two two/OOP/lab/lab5/lab5/build/CMakeFiles/bignum.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bignum.dir/depend

