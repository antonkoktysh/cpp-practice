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
include deque/CMakeFiles/test_deque_memory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include deque/CMakeFiles/test_deque_memory.dir/compiler_depend.make

# Include the progress variables for this target.
include deque/CMakeFiles/test_deque_memory.dir/progress.make

# Include the compile flags for this target's objects.
include deque/CMakeFiles/test_deque_memory.dir/flags.make

deque/CMakeFiles/test_deque_memory.dir/codegen:
.PHONY : deque/CMakeFiles/test_deque_memory.dir/codegen

deque/CMakeFiles/test_deque_memory.dir/test_memory.cpp.o: deque/CMakeFiles/test_deque_memory.dir/flags.make
deque/CMakeFiles/test_deque_memory.dir/test_memory.cpp.o: /Users/antonkoktysh/Desktop/shad/antonkoktysh/deque/test_memory.cpp
deque/CMakeFiles/test_deque_memory.dir/test_memory.cpp.o: deque/CMakeFiles/test_deque_memory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object deque/CMakeFiles/test_deque_memory.dir/test_memory.cpp.o"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/deque && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT deque/CMakeFiles/test_deque_memory.dir/test_memory.cpp.o -MF CMakeFiles/test_deque_memory.dir/test_memory.cpp.o.d -o CMakeFiles/test_deque_memory.dir/test_memory.cpp.o -c /Users/antonkoktysh/Desktop/shad/antonkoktysh/deque/test_memory.cpp

deque/CMakeFiles/test_deque_memory.dir/test_memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_deque_memory.dir/test_memory.cpp.i"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/deque && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/antonkoktysh/Desktop/shad/antonkoktysh/deque/test_memory.cpp > CMakeFiles/test_deque_memory.dir/test_memory.cpp.i

deque/CMakeFiles/test_deque_memory.dir/test_memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_deque_memory.dir/test_memory.cpp.s"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/deque && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/antonkoktysh/Desktop/shad/antonkoktysh/deque/test_memory.cpp -o CMakeFiles/test_deque_memory.dir/test_memory.cpp.s

# Object files for target test_deque_memory
test_deque_memory_OBJECTS = \
"CMakeFiles/test_deque_memory.dir/test_memory.cpp.o"

# External object files for target test_deque_memory
test_deque_memory_EXTERNAL_OBJECTS =

test_deque_memory: deque/CMakeFiles/test_deque_memory.dir/test_memory.cpp.o
test_deque_memory: deque/CMakeFiles/test_deque_memory.dir/build.make
test_deque_memory: _deps/catch2-build/src/libCatch2Main.a
test_deque_memory: _deps/catch2-build/src/libCatch2.a
test_deque_memory: deque/CMakeFiles/test_deque_memory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../test_deque_memory"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/deque && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_deque_memory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
deque/CMakeFiles/test_deque_memory.dir/build: test_deque_memory
.PHONY : deque/CMakeFiles/test_deque_memory.dir/build

deque/CMakeFiles/test_deque_memory.dir/clean:
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/deque && $(CMAKE_COMMAND) -P CMakeFiles/test_deque_memory.dir/cmake_clean.cmake
.PHONY : deque/CMakeFiles/test_deque_memory.dir/clean

deque/CMakeFiles/test_deque_memory.dir/depend:
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/antonkoktysh/Desktop/shad/antonkoktysh /Users/antonkoktysh/Desktop/shad/antonkoktysh/deque /Users/antonkoktysh/Desktop/shad/antonkoktysh/build /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/deque /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/deque/CMakeFiles/test_deque_memory.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : deque/CMakeFiles/test_deque_memory.dir/depend

