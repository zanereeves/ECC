# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zanereeves/projects/ECC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zanereeves/projects/ECC/build

# Include any dependencies generated for this target.
include CMakeFiles/ELLIPSE_LIB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ELLIPSE_LIB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ELLIPSE_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ELLIPSE_LIB.dir/flags.make

CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o: CMakeFiles/ELLIPSE_LIB.dir/flags.make
CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o: /Users/zanereeves/projects/ECC/src/arithmetic.c
CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o: CMakeFiles/ELLIPSE_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zanereeves/projects/ECC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o -MF CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o.d -o CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o -c /Users/zanereeves/projects/ECC/src/arithmetic.c

CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zanereeves/projects/ECC/src/arithmetic.c > CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.i

CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zanereeves/projects/ECC/src/arithmetic.c -o CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.s

# Object files for target ELLIPSE_LIB
ELLIPSE_LIB_OBJECTS = \
"CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o"

# External object files for target ELLIPSE_LIB
ELLIPSE_LIB_EXTERNAL_OBJECTS =

libELLIPSE_LIB.dylib: CMakeFiles/ELLIPSE_LIB.dir/src/arithmetic.c.o
libELLIPSE_LIB.dylib: CMakeFiles/ELLIPSE_LIB.dir/build.make
libELLIPSE_LIB.dylib: /usr/local/lib/libsodium.dylib
libELLIPSE_LIB.dylib: /usr/local/lib/libgmp.dylib
libELLIPSE_LIB.dylib: CMakeFiles/ELLIPSE_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/zanereeves/projects/ECC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libELLIPSE_LIB.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ELLIPSE_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ELLIPSE_LIB.dir/build: libELLIPSE_LIB.dylib
.PHONY : CMakeFiles/ELLIPSE_LIB.dir/build

CMakeFiles/ELLIPSE_LIB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ELLIPSE_LIB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ELLIPSE_LIB.dir/clean

CMakeFiles/ELLIPSE_LIB.dir/depend:
	cd /Users/zanereeves/projects/ECC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zanereeves/projects/ECC /Users/zanereeves/projects/ECC /Users/zanereeves/projects/ECC/build /Users/zanereeves/projects/ECC/build /Users/zanereeves/projects/ECC/build/CMakeFiles/ELLIPSE_LIB.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ELLIPSE_LIB.dir/depend
