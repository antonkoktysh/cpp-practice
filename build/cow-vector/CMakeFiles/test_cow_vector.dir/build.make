# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/antonkoktysh/Desktop/shad/antonkoktysh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/antonkoktysh/Desktop/shad/antonkoktysh/build

# Include any dependencies generated for this target.
include cow-vector/CMakeFiles/test_cow_vector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include cow-vector/CMakeFiles/test_cow_vector.dir/compiler_depend.make

# Include the progress variables for this target.
include cow-vector/CMakeFiles/test_cow_vector.dir/progress.make

# Include the compile flags for this target's objects.
include cow-vector/CMakeFiles/test_cow_vector.dir/flags.make

cow-vector/CMakeFiles/test_cow_vector.dir/codegen:
.PHONY : cow-vector/CMakeFiles/test_cow_vector.dir/codegen

cow-vector/CMakeFiles/test_cow_vector.dir/test.cpp.o: cow-vector/CMakeFiles/test_cow_vector.dir/flags.make
cow-vector/CMakeFiles/test_cow_vector.dir/test.cpp.o: /Users/antonkoktysh/Desktop/shad/antonkoktysh/cow-vector/test.cpp
cow-vector/CMakeFiles/test_cow_vector.dir/test.cpp.o: cow-vector/CMakeFiles/test_cow_vector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cow-vector/CMakeFiles/test_cow_vector.dir/test.cpp.o"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/cow-vector && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT cow-vector/CMakeFiles/test_cow_vector.dir/test.cpp.o -MF CMakeFiles/test_cow_vector.dir/test.cpp.o.d -o CMakeFiles/test_cow_vector.dir/test.cpp.o -c /Users/antonkoktysh/Desktop/shad/antonkoktysh/cow-vector/test.cpp

cow-vector/CMakeFiles/test_cow_vector.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_cow_vector.dir/test.cpp.i"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/cow-vector && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/antonkoktysh/Desktop/shad/antonkoktysh/cow-vector/test.cpp > CMakeFiles/test_cow_vector.dir/test.cpp.i

cow-vector/CMakeFiles/test_cow_vector.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_cow_vector.dir/test.cpp.s"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/cow-vector && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/antonkoktysh/Desktop/shad/antonkoktysh/cow-vector/test.cpp -o CMakeFiles/test_cow_vector.dir/test.cpp.s

# Object files for target test_cow_vector
test_cow_vector_OBJECTS = \
"CMakeFiles/test_cow_vector.dir/test.cpp.o"

# External object files for target test_cow_vector
test_cow_vector_EXTERNAL_OBJECTS =

test_cow_vector: cow-vector/CMakeFiles/test_cow_vector.dir/test.cpp.o
test_cow_vector: cow-vector/CMakeFiles/test_cow_vector.dir/build.make
test_cow_vector: _deps/catch2-build/src/libCatch2Main.a
test_cow_vector: _deps/catch2-build/src/libCatch2.a
test_cow_vector: cow-vector/CMakeFiles/test_cow_vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../test_cow_vector"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/cow-vector && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_cow_vector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cow-vector/CMakeFiles/test_cow_vector.dir/build: test_cow_vector
.PHONY : cow-vector/CMakeFiles/test_cow_vector.dir/build

cow-vector/CMakeFiles/test_cow_vector.dir/clean:
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/cow-vector && $(CMAKE_COMMAND) -P CMakeFiles/test_cow_vector.dir/cmake_clean.cmake
.PHONY : cow-vector/CMakeFiles/test_cow_vector.dir/clean

cow-vector/CMakeFiles/test_cow_vector.dir/depend:
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/antonkoktysh/Desktop/shad/antonkoktysh /Users/antonkoktysh/Desktop/shad/antonkoktysh/cow-vector /Users/antonkoktysh/Desktop/shad/antonkoktysh/build /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/cow-vector /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/cow-vector/CMakeFiles/test_cow_vector.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : cow-vector/CMakeFiles/test_cow_vector.dir/depend

