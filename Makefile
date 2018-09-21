# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/grzegorz/Projects/szkolenie/11/CMakeFiles /home/grzegorz/Projects/szkolenie/11/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/grzegorz/Projects/szkolenie/11/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named run

# Build rule for target.
run: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 run
.PHONY : run

# fast build rule for target.
run/fast:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/build
.PHONY : run/fast

main.o: main.c.o

.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i

.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s

.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/main.c.s
.PHONY : main.c.s

src/stud_console.o: src/stud_console.c.o

.PHONY : src/stud_console.o

# target to build an object file
src/stud_console.c.o:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_console.c.o
.PHONY : src/stud_console.c.o

src/stud_console.i: src/stud_console.c.i

.PHONY : src/stud_console.i

# target to preprocess a source file
src/stud_console.c.i:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_console.c.i
.PHONY : src/stud_console.c.i

src/stud_console.s: src/stud_console.c.s

.PHONY : src/stud_console.s

# target to generate assembly for a file
src/stud_console.c.s:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_console.c.s
.PHONY : src/stud_console.c.s

src/stud_file.o: src/stud_file.c.o

.PHONY : src/stud_file.o

# target to build an object file
src/stud_file.c.o:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_file.c.o
.PHONY : src/stud_file.c.o

src/stud_file.i: src/stud_file.c.i

.PHONY : src/stud_file.i

# target to preprocess a source file
src/stud_file.c.i:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_file.c.i
.PHONY : src/stud_file.c.i

src/stud_file.s: src/stud_file.c.s

.PHONY : src/stud_file.s

# target to generate assembly for a file
src/stud_file.c.s:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_file.c.s
.PHONY : src/stud_file.c.s

src/stud_sort.o: src/stud_sort.c.o

.PHONY : src/stud_sort.o

# target to build an object file
src/stud_sort.c.o:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_sort.c.o
.PHONY : src/stud_sort.c.o

src/stud_sort.i: src/stud_sort.c.i

.PHONY : src/stud_sort.i

# target to preprocess a source file
src/stud_sort.c.i:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_sort.c.i
.PHONY : src/stud_sort.c.i

src/stud_sort.s: src/stud_sort.c.s

.PHONY : src/stud_sort.s

# target to generate assembly for a file
src/stud_sort.c.s:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_sort.c.s
.PHONY : src/stud_sort.c.s

src/stud_utils.o: src/stud_utils.c.o

.PHONY : src/stud_utils.o

# target to build an object file
src/stud_utils.c.o:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_utils.c.o
.PHONY : src/stud_utils.c.o

src/stud_utils.i: src/stud_utils.c.i

.PHONY : src/stud_utils.i

# target to preprocess a source file
src/stud_utils.c.i:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_utils.c.i
.PHONY : src/stud_utils.c.i

src/stud_utils.s: src/stud_utils.c.s

.PHONY : src/stud_utils.s

# target to generate assembly for a file
src/stud_utils.c.s:
	$(MAKE) -f CMakeFiles/run.dir/build.make CMakeFiles/run.dir/src/stud_utils.c.s
.PHONY : src/stud_utils.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... run"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/stud_console.o"
	@echo "... src/stud_console.i"
	@echo "... src/stud_console.s"
	@echo "... src/stud_file.o"
	@echo "... src/stud_file.i"
	@echo "... src/stud_file.s"
	@echo "... src/stud_sort.o"
	@echo "... src/stud_sort.i"
	@echo "... src/stud_sort.s"
	@echo "... src/stud_utils.o"
	@echo "... src/stud_utils.i"
	@echo "... src/stud_utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
