# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests

# Include any dependencies generated for this target.
include scc_tests/CMakeFiles/scc_tests.dir/depend.make

# Include the progress variables for this target.
include scc_tests/CMakeFiles/scc_tests.dir/progress.make

# Include the compile flags for this target's objects.
include scc_tests/CMakeFiles/scc_tests.dir/flags.make

scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o: scc_tests/CMakeFiles/scc_tests.dir/flags.make
scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o: scc_tests/scc_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o"
	cd /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scc_tests.dir/scc_tests.cpp.o -c /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests/scc_tests.cpp

scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scc_tests.dir/scc_tests.cpp.i"
	cd /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests/scc_tests.cpp > CMakeFiles/scc_tests.dir/scc_tests.cpp.i

scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scc_tests.dir/scc_tests.cpp.s"
	cd /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests/scc_tests.cpp -o CMakeFiles/scc_tests.dir/scc_tests.cpp.s

scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o.requires:

.PHONY : scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o.requires

scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o.provides: scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o.requires
	$(MAKE) -f scc_tests/CMakeFiles/scc_tests.dir/build.make scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o.provides.build
.PHONY : scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o.provides

scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o.provides.build: scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o


# Object files for target scc_tests
scc_tests_OBJECTS = \
"CMakeFiles/scc_tests.dir/scc_tests.cpp.o"

# External object files for target scc_tests
scc_tests_EXTERNAL_OBJECTS =

scc_tests/scc_tests: scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o
scc_tests/scc_tests: scc_tests/CMakeFiles/scc_tests.dir/build.make
scc_tests/scc_tests: testing_utils/libtesting_utils.a
scc_tests/scc_tests: /usr/lib/libgtest_main.a
scc_tests/scc_tests: /usr/lib/libgtest.a
scc_tests/scc_tests: testing_utils/kwsys/libkwsys.a
scc_tests/scc_tests: testing_utils/libperf/libperf.a
scc_tests/scc_tests: scc_tests/CMakeFiles/scc_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scc_tests"
	cd /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scc_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
scc_tests/CMakeFiles/scc_tests.dir/build: scc_tests/scc_tests

.PHONY : scc_tests/CMakeFiles/scc_tests.dir/build

scc_tests/CMakeFiles/scc_tests.dir/requires: scc_tests/CMakeFiles/scc_tests.dir/scc_tests.cpp.o.requires

.PHONY : scc_tests/CMakeFiles/scc_tests.dir/requires

scc_tests/CMakeFiles/scc_tests.dir/clean:
	cd /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests && $(CMAKE_COMMAND) -P CMakeFiles/scc_tests.dir/cmake_clean.cmake
.PHONY : scc_tests/CMakeFiles/scc_tests.dir/clean

scc_tests/CMakeFiles/scc_tests.dir/depend:
	cd /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests /home/cs104/Repositories/hw-kwakjame/hw6/hw6_tests/scc_tests/CMakeFiles/scc_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : scc_tests/CMakeFiles/scc_tests.dir/depend

