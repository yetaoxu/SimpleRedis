# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/xuyetao/CLionProjects/SimpleRedis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/xuyetao/CLionProjects/SimpleRedis/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SimpleRedis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleRedis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleRedis.dir/flags.make

CMakeFiles/SimpleRedis.dir/main.cpp.o: CMakeFiles/SimpleRedis.dir/flags.make
CMakeFiles/SimpleRedis.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/xuyetao/CLionProjects/SimpleRedis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimpleRedis.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimpleRedis.dir/main.cpp.o -c /Users/xuyetao/CLionProjects/SimpleRedis/main.cpp

CMakeFiles/SimpleRedis.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleRedis.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/xuyetao/CLionProjects/SimpleRedis/main.cpp > CMakeFiles/SimpleRedis.dir/main.cpp.i

CMakeFiles/SimpleRedis.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleRedis.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/xuyetao/CLionProjects/SimpleRedis/main.cpp -o CMakeFiles/SimpleRedis.dir/main.cpp.s

# Object files for target SimpleRedis
SimpleRedis_OBJECTS = \
"CMakeFiles/SimpleRedis.dir/main.cpp.o"

# External object files for target SimpleRedis
SimpleRedis_EXTERNAL_OBJECTS =

SimpleRedis: CMakeFiles/SimpleRedis.dir/main.cpp.o
SimpleRedis: CMakeFiles/SimpleRedis.dir/build.make
SimpleRedis: CMakeFiles/SimpleRedis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/xuyetao/CLionProjects/SimpleRedis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SimpleRedis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleRedis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleRedis.dir/build: SimpleRedis

.PHONY : CMakeFiles/SimpleRedis.dir/build

CMakeFiles/SimpleRedis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleRedis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleRedis.dir/clean

CMakeFiles/SimpleRedis.dir/depend:
	cd /Users/xuyetao/CLionProjects/SimpleRedis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/xuyetao/CLionProjects/SimpleRedis /Users/xuyetao/CLionProjects/SimpleRedis /Users/xuyetao/CLionProjects/SimpleRedis/cmake-build-debug /Users/xuyetao/CLionProjects/SimpleRedis/cmake-build-debug /Users/xuyetao/CLionProjects/SimpleRedis/cmake-build-debug/CMakeFiles/SimpleRedis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleRedis.dir/depend

