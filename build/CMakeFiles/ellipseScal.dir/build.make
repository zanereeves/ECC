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
include CMakeFiles/ellipseScal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ellipseScal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ellipseScal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ellipseScal.dir/flags.make

CMakeFiles/ellipseScal.dir/src/main.c.o: CMakeFiles/ellipseScal.dir/flags.make
CMakeFiles/ellipseScal.dir/src/main.c.o: /Users/zanereeves/projects/ECC/src/main.c
CMakeFiles/ellipseScal.dir/src/main.c.o: CMakeFiles/ellipseScal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zanereeves/projects/ECC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ellipseScal.dir/src/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ellipseScal.dir/src/main.c.o -MF CMakeFiles/ellipseScal.dir/src/main.c.o.d -o CMakeFiles/ellipseScal.dir/src/main.c.o -c /Users/zanereeves/projects/ECC/src/main.c

CMakeFiles/ellipseScal.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ellipseScal.dir/src/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zanereeves/projects/ECC/src/main.c > CMakeFiles/ellipseScal.dir/src/main.c.i

CMakeFiles/ellipseScal.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ellipseScal.dir/src/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zanereeves/projects/ECC/src/main.c -o CMakeFiles/ellipseScal.dir/src/main.c.s

# Object files for target ellipseScal
ellipseScal_OBJECTS = \
"CMakeFiles/ellipseScal.dir/src/main.c.o"

# External object files for target ellipseScal
ellipseScal_EXTERNAL_OBJECTS =

ellipseScal: CMakeFiles/ellipseScal.dir/src/main.c.o
ellipseScal: CMakeFiles/ellipseScal.dir/build.make
ellipseScal: libELLIPSE_LIB.dylib
ellipseScal: /usr/local/lib/libsodium.dylib
ellipseScal: /usr/local/lib/libgmp.dylib
ellipseScal: CMakeFiles/ellipseScal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/zanereeves/projects/ECC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ellipseScal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ellipseScal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ellipseScal.dir/build: ellipseScal
.PHONY : CMakeFiles/ellipseScal.dir/build

CMakeFiles/ellipseScal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ellipseScal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ellipseScal.dir/clean

CMakeFiles/ellipseScal.dir/depend:
	cd /Users/zanereeves/projects/ECC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zanereeves/projects/ECC /Users/zanereeves/projects/ECC /Users/zanereeves/projects/ECC/build /Users/zanereeves/projects/ECC/build /Users/zanereeves/projects/ECC/build/CMakeFiles/ellipseScal.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ellipseScal.dir/depend

