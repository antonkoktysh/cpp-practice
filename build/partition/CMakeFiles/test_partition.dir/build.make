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
include partition/CMakeFiles/test_partition.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include partition/CMakeFiles/test_partition.dir/compiler_depend.make

# Include the progress variables for this target.
include partition/CMakeFiles/test_partition.dir/progress.make

# Include the compile flags for this target's objects.
include partition/CMakeFiles/test_partition.dir/flags.make

partition/CMakeFiles/test_partition.dir/codegen:
.PHONY : partition/CMakeFiles/test_partition.dir/codegen

partition/CMakeFiles/test_partition.dir/test.cpp.o: partition/CMakeFiles/test_partition.dir/flags.make
partition/CMakeFiles/test_partition.dir/test.cpp.o: /Users/antonkoktysh/Desktop/shad/antonkoktysh/partition/test.cpp
partition/CMakeFiles/test_partition.dir/test.cpp.o: partition/CMakeFiles/test_partition.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object partition/CMakeFiles/test_partition.dir/test.cpp.o"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/partition && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT partition/CMakeFiles/test_partition.dir/test.cpp.o -MF CMakeFiles/test_partition.dir/test.cpp.o.d -o CMakeFiles/test_partition.dir/test.cpp.o -c /Users/antonkoktysh/Desktop/shad/antonkoktysh/partition/test.cpp

partition/CMakeFiles/test_partition.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_partition.dir/test.cpp.i"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/partition && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/antonkoktysh/Desktop/shad/antonkoktysh/partition/test.cpp > CMakeFiles/test_partition.dir/test.cpp.i

partition/CMakeFiles/test_partition.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_partition.dir/test.cpp.s"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/partition && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/antonkoktysh/Desktop/shad/antonkoktysh/partition/test.cpp -o CMakeFiles/test_partition.dir/test.cpp.s

# Object files for target test_partition
test_partition_OBJECTS = \
"CMakeFiles/test_partition.dir/test.cpp.o"

# External object files for target test_partition
test_partition_EXTERNAL_OBJECTS =

test_partition: partition/CMakeFiles/test_partition.dir/test.cpp.o
test_partition: partition/CMakeFiles/test_partition.dir/build.make
test_partition: _deps/catch2-build/src/libCatch2Main.a
test_partition: _deps/catch2-build/src/libCatch2.a
test_partition: partition/CMakeFiles/test_partition.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../test_partition"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/partition && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_partition.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
partition/CMakeFiles/test_partition.dir/build: test_partition
.PHONY : partition/CMakeFiles/test_partition.dir/build

partition/CMakeFiles/test_partition.dir/clean:
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/partition && $(CMAKE_COMMAND) -P CMakeFiles/test_partition.dir/cmake_clean.cmake
.PHONY : partition/CMakeFiles/test_partition.dir/clean

partition/CMakeFiles/test_partition.dir/depend:
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/antonkoktysh/Desktop/shad/antonkoktysh /Users/antonkoktysh/Desktop/shad/antonkoktysh/partition /Users/antonkoktysh/Desktop/shad/antonkoktysh/build /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/partition /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/partition/CMakeFiles/test_partition.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : partition/CMakeFiles/test_partition.dir/depend

