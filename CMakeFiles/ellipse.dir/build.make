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
CMAKE_BINARY_DIR = /Users/zanereeves/projects/ECC

# Include any dependencies generated for this target.
include CMakeFiles/ellipse.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ellipse.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ellipse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ellipse.dir/flags.make

CMakeFiles/ellipse.dir/src/main.c.o: CMakeFiles/ellipse.dir/flags.make
CMakeFiles/ellipse.dir/src/main.c.o: src/main.c
CMakeFiles/ellipse.dir/src/main.c.o: CMakeFiles/ellipse.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zanereeves/projects/ECC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ellipse.dir/src/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ellipse.dir/src/main.c.o -MF CMakeFiles/ellipse.dir/src/main.c.o.d -o CMakeFiles/ellipse.dir/src/main.c.o -c /Users/zanereeves/projects/ECC/src/main.c

CMakeFiles/ellipse.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ellipse.dir/src/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zanereeves/projects/ECC/src/main.c > CMakeFiles/ellipse.dir/src/main.c.i

CMakeFiles/ellipse.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ellipse.dir/src/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zanereeves/projects/ECC/src/main.c -o CMakeFiles/ellipse.dir/src/main.c.s

# Object files for target ellipse
ellipse_OBJECTS = \
"CMakeFiles/ellipse.dir/src/main.c.o"

# External object files for target ellipse
ellipse_EXTERNAL_OBJECTS =

ellipse: CMakeFiles/ellipse.dir/src/main.c.o
ellipse: CMakeFiles/ellipse.dir/build.make
ellipse: /usr/local/lib/libsodium.dylib
ellipse: /opt/homebrew/Cellar/gmp/6.3.0/lib/libgmp.dylib
ellipse: CMakeFiles/ellipse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/zanereeves/projects/ECC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ellipse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ellipse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ellipse.dir/build: ellipse
.PHONY : CMakeFiles/ellipse.dir/build

CMakeFiles/ellipse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ellipse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ellipse.dir/clean

CMakeFiles/ellipse.dir/depend:
	cd /Users/zanereeves/projects/ECC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zanereeves/projects/ECC /Users/zanereeves/projects/ECC /Users/zanereeves/projects/ECC /Users/zanereeves/projects/ECC /Users/zanereeves/projects/ECC/CMakeFiles/ellipse.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ellipse.dir/depend

