# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /cygdrive/c/Users/11135/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/11135/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/Code/Project-C/C++Primer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/Code/Project-C/C++Primer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C__Primer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C__Primer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C__Primer.dir/flags.make

CMakeFiles/C__Primer.dir/usealgorithm.cpp.o: CMakeFiles/C__Primer.dir/flags.make
CMakeFiles/C__Primer.dir/usealgorithm.cpp.o: ../usealgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/Code/Project-C/C++Primer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C__Primer.dir/usealgorithm.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/C__Primer.dir/usealgorithm.cpp.o -c /cygdrive/d/Code/Project-C/C++Primer/usealgorithm.cpp

CMakeFiles/C__Primer.dir/usealgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C__Primer.dir/usealgorithm.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/Code/Project-C/C++Primer/usealgorithm.cpp > CMakeFiles/C__Primer.dir/usealgorithm.cpp.i

CMakeFiles/C__Primer.dir/usealgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C__Primer.dir/usealgorithm.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/Code/Project-C/C++Primer/usealgorithm.cpp -o CMakeFiles/C__Primer.dir/usealgorithm.cpp.s

CMakeFiles/C__Primer.dir/usealgorithm.cpp.o.requires:

.PHONY : CMakeFiles/C__Primer.dir/usealgorithm.cpp.o.requires

CMakeFiles/C__Primer.dir/usealgorithm.cpp.o.provides: CMakeFiles/C__Primer.dir/usealgorithm.cpp.o.requires
	$(MAKE) -f CMakeFiles/C__Primer.dir/build.make CMakeFiles/C__Primer.dir/usealgorithm.cpp.o.provides.build
.PHONY : CMakeFiles/C__Primer.dir/usealgorithm.cpp.o.provides

CMakeFiles/C__Primer.dir/usealgorithm.cpp.o.provides.build: CMakeFiles/C__Primer.dir/usealgorithm.cpp.o


# Object files for target C__Primer
C__Primer_OBJECTS = \
"CMakeFiles/C__Primer.dir/usealgorithm.cpp.o"

# External object files for target C__Primer
C__Primer_EXTERNAL_OBJECTS =

C__Primer.exe: CMakeFiles/C__Primer.dir/usealgorithm.cpp.o
C__Primer.exe: CMakeFiles/C__Primer.dir/build.make
C__Primer.exe: CMakeFiles/C__Primer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/Code/Project-C/C++Primer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C__Primer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C__Primer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C__Primer.dir/build: C__Primer.exe

.PHONY : CMakeFiles/C__Primer.dir/build

CMakeFiles/C__Primer.dir/requires: CMakeFiles/C__Primer.dir/usealgorithm.cpp.o.requires

.PHONY : CMakeFiles/C__Primer.dir/requires

CMakeFiles/C__Primer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C__Primer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C__Primer.dir/clean

CMakeFiles/C__Primer.dir/depend:
	cd /cygdrive/d/Code/Project-C/C++Primer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/Code/Project-C/C++Primer /cygdrive/d/Code/Project-C/C++Primer /cygdrive/d/Code/Project-C/C++Primer/cmake-build-debug /cygdrive/d/Code/Project-C/C++Primer/cmake-build-debug /cygdrive/d/Code/Project-C/C++Primer/cmake-build-debug/CMakeFiles/C__Primer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C__Primer.dir/depend

