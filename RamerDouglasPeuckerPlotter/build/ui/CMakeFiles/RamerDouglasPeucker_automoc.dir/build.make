# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake

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
CMAKE_SOURCE_DIR = /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build

# Utility rule file for RamerDouglasPeucker_automoc.

# Include the progress variables for this target.
include ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/progress.make

ui/CMakeFiles/RamerDouglasPeucker_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc for target RamerDouglasPeucker"
	cd /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build/ui && /usr/bin/cmake -E cmake_autogen /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build/ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/ Devel

RamerDouglasPeucker_automoc: ui/CMakeFiles/RamerDouglasPeucker_automoc
RamerDouglasPeucker_automoc: ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/build.make

.PHONY : RamerDouglasPeucker_automoc

# Rule to build all files generated by this target.
ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/build: RamerDouglasPeucker_automoc

.PHONY : ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/build

ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/clean:
	cd /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build/ui && $(CMAKE_COMMAND) -P CMakeFiles/RamerDouglasPeucker_automoc.dir/cmake_clean.cmake
.PHONY : ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/clean

ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/depend:
	cd /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/src /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/src/ui /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build/ui /home/jthistle/Documents/ControlTech/RamerDouglasPeuckerPlotter/build/ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ui/CMakeFiles/RamerDouglasPeucker_automoc.dir/depend

