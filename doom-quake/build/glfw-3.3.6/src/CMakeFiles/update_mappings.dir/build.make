# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build

# Utility rule file for update_mappings.

# Include the progress variables for this target.
include glfw-3.3.6/src/CMakeFiles/update_mappings.dir/progress.make

glfw-3.3.6/src/CMakeFiles/update_mappings:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating gamepad mappings from upstream repository"
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/src && /usr/bin/cmake -P /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/CMake/GenerateMappings.cmake mappings.h.in mappings.h

update_mappings: glfw-3.3.6/src/CMakeFiles/update_mappings
update_mappings: glfw-3.3.6/src/CMakeFiles/update_mappings.dir/build.make

.PHONY : update_mappings

# Rule to build all files generated by this target.
glfw-3.3.6/src/CMakeFiles/update_mappings.dir/build: update_mappings

.PHONY : glfw-3.3.6/src/CMakeFiles/update_mappings.dir/build

glfw-3.3.6/src/CMakeFiles/update_mappings.dir/clean:
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/src && $(CMAKE_COMMAND) -P CMakeFiles/update_mappings.dir/cmake_clean.cmake
.PHONY : glfw-3.3.6/src/CMakeFiles/update_mappings.dir/clean

glfw-3.3.6/src/CMakeFiles/update_mappings.dir/depend:
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/src /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/src /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/src/CMakeFiles/update_mappings.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw-3.3.6/src/CMakeFiles/update_mappings.dir/depend

