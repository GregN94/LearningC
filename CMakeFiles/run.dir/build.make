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
CMAKE_SOURCE_DIR = /home/grzegorz/Projects/szkolenie/11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/grzegorz/Projects/szkolenie/11

# Include any dependencies generated for this target.
include CMakeFiles/run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run.dir/flags.make

CMakeFiles/run.dir/main.c.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grzegorz/Projects/szkolenie/11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/run.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/run.dir/main.c.o   -c /home/grzegorz/Projects/szkolenie/11/main.c

CMakeFiles/run.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grzegorz/Projects/szkolenie/11/main.c > CMakeFiles/run.dir/main.c.i

CMakeFiles/run.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grzegorz/Projects/szkolenie/11/main.c -o CMakeFiles/run.dir/main.c.s

CMakeFiles/run.dir/main.c.o.requires:

.PHONY : CMakeFiles/run.dir/main.c.o.requires

CMakeFiles/run.dir/main.c.o.provides: CMakeFiles/run.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/main.c.o.provides.build
.PHONY : CMakeFiles/run.dir/main.c.o.provides

CMakeFiles/run.dir/main.c.o.provides.build: CMakeFiles/run.dir/main.c.o


CMakeFiles/run.dir/src/stud_console.c.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/stud_console.c.o: src/stud_console.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grzegorz/Projects/szkolenie/11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/run.dir/src/stud_console.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/run.dir/src/stud_console.c.o   -c /home/grzegorz/Projects/szkolenie/11/src/stud_console.c

CMakeFiles/run.dir/src/stud_console.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run.dir/src/stud_console.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grzegorz/Projects/szkolenie/11/src/stud_console.c > CMakeFiles/run.dir/src/stud_console.c.i

CMakeFiles/run.dir/src/stud_console.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run.dir/src/stud_console.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grzegorz/Projects/szkolenie/11/src/stud_console.c -o CMakeFiles/run.dir/src/stud_console.c.s

CMakeFiles/run.dir/src/stud_console.c.o.requires:

.PHONY : CMakeFiles/run.dir/src/stud_console.c.o.requires

CMakeFiles/run.dir/src/stud_console.c.o.provides: CMakeFiles/run.dir/src/stud_console.c.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_console.c.o.provides.build
.PHONY : CMakeFiles/run.dir/src/stud_console.c.o.provides

CMakeFiles/run.dir/src/stud_console.c.o.provides.build: CMakeFiles/run.dir/src/stud_console.c.o


CMakeFiles/run.dir/src/stud_file.c.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/stud_file.c.o: src/stud_file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grzegorz/Projects/szkolenie/11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/run.dir/src/stud_file.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/run.dir/src/stud_file.c.o   -c /home/grzegorz/Projects/szkolenie/11/src/stud_file.c

CMakeFiles/run.dir/src/stud_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run.dir/src/stud_file.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grzegorz/Projects/szkolenie/11/src/stud_file.c > CMakeFiles/run.dir/src/stud_file.c.i

CMakeFiles/run.dir/src/stud_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run.dir/src/stud_file.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grzegorz/Projects/szkolenie/11/src/stud_file.c -o CMakeFiles/run.dir/src/stud_file.c.s

CMakeFiles/run.dir/src/stud_file.c.o.requires:

.PHONY : CMakeFiles/run.dir/src/stud_file.c.o.requires

CMakeFiles/run.dir/src/stud_file.c.o.provides: CMakeFiles/run.dir/src/stud_file.c.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_file.c.o.provides.build
.PHONY : CMakeFiles/run.dir/src/stud_file.c.o.provides

CMakeFiles/run.dir/src/stud_file.c.o.provides.build: CMakeFiles/run.dir/src/stud_file.c.o


CMakeFiles/run.dir/src/stud_sort.c.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/stud_sort.c.o: src/stud_sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grzegorz/Projects/szkolenie/11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/run.dir/src/stud_sort.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/run.dir/src/stud_sort.c.o   -c /home/grzegorz/Projects/szkolenie/11/src/stud_sort.c

CMakeFiles/run.dir/src/stud_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run.dir/src/stud_sort.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grzegorz/Projects/szkolenie/11/src/stud_sort.c > CMakeFiles/run.dir/src/stud_sort.c.i

CMakeFiles/run.dir/src/stud_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run.dir/src/stud_sort.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grzegorz/Projects/szkolenie/11/src/stud_sort.c -o CMakeFiles/run.dir/src/stud_sort.c.s

CMakeFiles/run.dir/src/stud_sort.c.o.requires:

.PHONY : CMakeFiles/run.dir/src/stud_sort.c.o.requires

CMakeFiles/run.dir/src/stud_sort.c.o.provides: CMakeFiles/run.dir/src/stud_sort.c.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_sort.c.o.provides.build
.PHONY : CMakeFiles/run.dir/src/stud_sort.c.o.provides

CMakeFiles/run.dir/src/stud_sort.c.o.provides.build: CMakeFiles/run.dir/src/stud_sort.c.o


CMakeFiles/run.dir/src/stud_utils.c.o: CMakeFiles/run.dir/flags.make
CMakeFiles/run.dir/src/stud_utils.c.o: src/stud_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/grzegorz/Projects/szkolenie/11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/run.dir/src/stud_utils.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/run.dir/src/stud_utils.c.o   -c /home/grzegorz/Projects/szkolenie/11/src/stud_utils.c

CMakeFiles/run.dir/src/stud_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/run.dir/src/stud_utils.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/grzegorz/Projects/szkolenie/11/src/stud_utils.c > CMakeFiles/run.dir/src/stud_utils.c.i

CMakeFiles/run.dir/src/stud_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/run.dir/src/stud_utils.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/grzegorz/Projects/szkolenie/11/src/stud_utils.c -o CMakeFiles/run.dir/src/stud_utils.c.s

CMakeFiles/run.dir/src/stud_utils.c.o.requires:

.PHONY : CMakeFiles/run.dir/src/stud_utils.c.o.requires

CMakeFiles/run.dir/src/stud_utils.c.o.provides: CMakeFiles/run.dir/src/stud_utils.c.o.requires
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_utils.c.o.provides.build
.PHONY : CMakeFiles/run.dir/src/stud_utils.c.o.provides

CMakeFiles/run.dir/src/stud_utils.c.o.provides.build: CMakeFiles/run.dir/src/stud_utils.c.o


# Object files for target run
run_OBJECTS = \
"CMakeFiles/run.dir/main.c.o" \
"CMakeFiles/run.dir/src/stud_console.c.o" \
"CMakeFiles/run.dir/src/stud_file.c.o" \
"CMakeFiles/run.dir/src/stud_sort.c.o" \
"CMakeFiles/run.dir/src/stud_utils.c.o"

# External object files for target run
run_EXTERNAL_OBJECTS =

run: CMakeFiles/run.dir/main.c.o
run: CMakeFiles/run.dir/src/stud_console.c.o
run: CMakeFiles/run.dir/src/stud_file.c.o
run: CMakeFiles/run.dir/src/stud_sort.c.o
run: CMakeFiles/run.dir/src/stud_utils.c.o
run: CMakeFiles/run.dir/build.make
run: CMakeFiles/run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/grzegorz/Projects/szkolenie/11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run

.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/requires: CMakeFiles/run.dir/main.c.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/stud_console.c.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/stud_file.c.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/stud_sort.c.o.requires
CMakeFiles/run.dir/requires: CMakeFiles/run.dir/src/stud_utils.c.o.requires

.PHONY : CMakeFiles/run.dir/requires

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /home/grzegorz/Projects/szkolenie/11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/grzegorz/Projects/szkolenie/11 /home/grzegorz/Projects/szkolenie/11 /home/grzegorz/Projects/szkolenie/11 /home/grzegorz/Projects/szkolenie/11 /home/grzegorz/Projects/szkolenie/11/CMakeFiles/run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run.dir/depend
