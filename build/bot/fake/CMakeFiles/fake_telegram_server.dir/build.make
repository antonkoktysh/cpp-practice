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
include bot/fake/CMakeFiles/fake_telegram_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bot/fake/CMakeFiles/fake_telegram_server.dir/compiler_depend.make

# Include the progress variables for this target.
include bot/fake/CMakeFiles/fake_telegram_server.dir/progress.make

# Include the compile flags for this target's objects.
include bot/fake/CMakeFiles/fake_telegram_server.dir/flags.make

bot/fake/CMakeFiles/fake_telegram_server.dir/codegen:
.PHONY : bot/fake/CMakeFiles/fake_telegram_server.dir/codegen

bot/fake/CMakeFiles/fake_telegram_server.dir/fake.cpp.o: bot/fake/CMakeFiles/fake_telegram_server.dir/flags.make
bot/fake/CMakeFiles/fake_telegram_server.dir/fake.cpp.o: /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake/fake.cpp
bot/fake/CMakeFiles/fake_telegram_server.dir/fake.cpp.o: bot/fake/CMakeFiles/fake_telegram_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bot/fake/CMakeFiles/fake_telegram_server.dir/fake.cpp.o"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bot/fake/CMakeFiles/fake_telegram_server.dir/fake.cpp.o -MF CMakeFiles/fake_telegram_server.dir/fake.cpp.o.d -o CMakeFiles/fake_telegram_server.dir/fake.cpp.o -c /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake/fake.cpp

bot/fake/CMakeFiles/fake_telegram_server.dir/fake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fake_telegram_server.dir/fake.cpp.i"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake/fake.cpp > CMakeFiles/fake_telegram_server.dir/fake.cpp.i

bot/fake/CMakeFiles/fake_telegram_server.dir/fake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fake_telegram_server.dir/fake.cpp.s"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake/fake.cpp -o CMakeFiles/fake_telegram_server.dir/fake.cpp.s

bot/fake/CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o: bot/fake/CMakeFiles/fake_telegram_server.dir/flags.make
bot/fake/CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o: /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake/fake_data.cpp
bot/fake/CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o: bot/fake/CMakeFiles/fake_telegram_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bot/fake/CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bot/fake/CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o -MF CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o.d -o CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o -c /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake/fake_data.cpp

bot/fake/CMakeFiles/fake_telegram_server.dir/fake_data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fake_telegram_server.dir/fake_data.cpp.i"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake/fake_data.cpp > CMakeFiles/fake_telegram_server.dir/fake_data.cpp.i

bot/fake/CMakeFiles/fake_telegram_server.dir/fake_data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fake_telegram_server.dir/fake_data.cpp.s"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && /opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake/fake_data.cpp -o CMakeFiles/fake_telegram_server.dir/fake_data.cpp.s

# Object files for target fake_telegram_server
fake_telegram_server_OBJECTS = \
"CMakeFiles/fake_telegram_server.dir/fake.cpp.o" \
"CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o"

# External object files for target fake_telegram_server
fake_telegram_server_EXTERNAL_OBJECTS =

bot/fake/libfake_telegram_server.a: bot/fake/CMakeFiles/fake_telegram_server.dir/fake.cpp.o
bot/fake/libfake_telegram_server.a: bot/fake/CMakeFiles/fake_telegram_server.dir/fake_data.cpp.o
bot/fake/libfake_telegram_server.a: bot/fake/CMakeFiles/fake_telegram_server.dir/build.make
bot/fake/libfake_telegram_server.a: bot/fake/CMakeFiles/fake_telegram_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/antonkoktysh/Desktop/shad/antonkoktysh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libfake_telegram_server.a"
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && $(CMAKE_COMMAND) -P CMakeFiles/fake_telegram_server.dir/cmake_clean_target.cmake
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fake_telegram_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bot/fake/CMakeFiles/fake_telegram_server.dir/build: bot/fake/libfake_telegram_server.a
.PHONY : bot/fake/CMakeFiles/fake_telegram_server.dir/build

bot/fake/CMakeFiles/fake_telegram_server.dir/clean:
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake && $(CMAKE_COMMAND) -P CMakeFiles/fake_telegram_server.dir/cmake_clean.cmake
.PHONY : bot/fake/CMakeFiles/fake_telegram_server.dir/clean

bot/fake/CMakeFiles/fake_telegram_server.dir/depend:
	cd /Users/antonkoktysh/Desktop/shad/antonkoktysh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/antonkoktysh/Desktop/shad/antonkoktysh /Users/antonkoktysh/Desktop/shad/antonkoktysh/bot/fake /Users/antonkoktysh/Desktop/shad/antonkoktysh/build /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake /Users/antonkoktysh/Desktop/shad/antonkoktysh/build/bot/fake/CMakeFiles/fake_telegram_server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : bot/fake/CMakeFiles/fake_telegram_server.dir/depend

