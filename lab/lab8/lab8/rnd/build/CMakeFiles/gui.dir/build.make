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
CMAKE_SOURCE_DIR = D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/build

# Include any dependencies generated for this target.
include CMakeFiles/gui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gui.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gui.dir/flags.make

CMakeFiles/gui.dir/window.cpp.obj: CMakeFiles/gui.dir/flags.make
CMakeFiles/gui.dir/window.cpp.obj: CMakeFiles/gui.dir/includes_CXX.rsp
CMakeFiles/gui.dir/window.cpp.obj: D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/window.cpp
CMakeFiles/gui.dir/window.cpp.obj: CMakeFiles/gui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gui.dir/window.cpp.obj"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gui.dir/window.cpp.obj -MF CMakeFiles/gui.dir/window.cpp.obj.d -o CMakeFiles/gui.dir/window.cpp.obj -c D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/window.cpp

CMakeFiles/gui.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/window.cpp.i"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/window.cpp > CMakeFiles/gui.dir/window.cpp.i

CMakeFiles/gui.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/window.cpp.s"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/window.cpp -o CMakeFiles/gui.dir/window.cpp.s

CMakeFiles/gui.dir/shapes.cpp.obj: CMakeFiles/gui.dir/flags.make
CMakeFiles/gui.dir/shapes.cpp.obj: CMakeFiles/gui.dir/includes_CXX.rsp
CMakeFiles/gui.dir/shapes.cpp.obj: D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/shapes.cpp
CMakeFiles/gui.dir/shapes.cpp.obj: CMakeFiles/gui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gui.dir/shapes.cpp.obj"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gui.dir/shapes.cpp.obj -MF CMakeFiles/gui.dir/shapes.cpp.obj.d -o CMakeFiles/gui.dir/shapes.cpp.obj -c D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/shapes.cpp

CMakeFiles/gui.dir/shapes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/shapes.cpp.i"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/shapes.cpp > CMakeFiles/gui.dir/shapes.cpp.i

CMakeFiles/gui.dir/shapes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/shapes.cpp.s"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/shapes.cpp -o CMakeFiles/gui.dir/shapes.cpp.s

CMakeFiles/gui.dir/rnd.cpp.obj: CMakeFiles/gui.dir/flags.make
CMakeFiles/gui.dir/rnd.cpp.obj: CMakeFiles/gui.dir/includes_CXX.rsp
CMakeFiles/gui.dir/rnd.cpp.obj: D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/rnd.cpp
CMakeFiles/gui.dir/rnd.cpp.obj: CMakeFiles/gui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gui.dir/rnd.cpp.obj"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gui.dir/rnd.cpp.obj -MF CMakeFiles/gui.dir/rnd.cpp.obj.d -o CMakeFiles/gui.dir/rnd.cpp.obj -c D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/rnd.cpp

CMakeFiles/gui.dir/rnd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/rnd.cpp.i"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/rnd.cpp > CMakeFiles/gui.dir/rnd.cpp.i

CMakeFiles/gui.dir/rnd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/rnd.cpp.s"
	C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/rnd.cpp -o CMakeFiles/gui.dir/rnd.cpp.s

# Object files for target gui
gui_OBJECTS = \
"CMakeFiles/gui.dir/window.cpp.obj" \
"CMakeFiles/gui.dir/shapes.cpp.obj" \
"CMakeFiles/gui.dir/rnd.cpp.obj"

# External object files for target gui
gui_EXTERNAL_OBJECTS =

D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe: CMakeFiles/gui.dir/window.cpp.obj
D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe: CMakeFiles/gui.dir/shapes.cpp.obj
D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe: CMakeFiles/gui.dir/rnd.cpp.obj
D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe: CMakeFiles/gui.dir/build.make
D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe: CMakeFiles/gui.dir/linkLibs.rsp
D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe: CMakeFiles/gui.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/gui.dir/objects.a
	C:/mingw64/bin/ar.exe qc CMakeFiles/gui.dir/objects.a @CMakeFiles/gui.dir/objects1.rsp
	C:/mingw64/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/gui.dir/objects.a -Wl,--no-whole-archive -o D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe -Wl,--out-implib,D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/libgui.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/gui.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/gui.dir/build: D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/bin/gui.exe
.PHONY : CMakeFiles/gui.dir/build

CMakeFiles/gui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gui.dir/clean

CMakeFiles/gui.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/build D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/build D:/Archive/subject/two_two/OOP/lab/lab8/lab8/rnd/build/CMakeFiles/gui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gui.dir/depend

