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

# Include any dependencies generated for this target.
include glfw-3.3.6/examples/CMakeFiles/heightmap.dir/depend.make

# Include the progress variables for this target.
include glfw-3.3.6/examples/CMakeFiles/heightmap.dir/progress.make

# Include the compile flags for this target's objects.
include glfw-3.3.6/examples/CMakeFiles/heightmap.dir/flags.make

glfw-3.3.6/examples/CMakeFiles/heightmap.dir/heightmap.c.o: glfw-3.3.6/examples/CMakeFiles/heightmap.dir/flags.make
glfw-3.3.6/examples/CMakeFiles/heightmap.dir/heightmap.c.o: ../glfw-3.3.6/examples/heightmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw-3.3.6/examples/CMakeFiles/heightmap.dir/heightmap.c.o"
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples && /usr/bin/c89-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/heightmap.dir/heightmap.c.o   -c /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/examples/heightmap.c

glfw-3.3.6/examples/CMakeFiles/heightmap.dir/heightmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heightmap.dir/heightmap.c.i"
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples && /usr/bin/c89-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/examples/heightmap.c > CMakeFiles/heightmap.dir/heightmap.c.i

glfw-3.3.6/examples/CMakeFiles/heightmap.dir/heightmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heightmap.dir/heightmap.c.s"
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples && /usr/bin/c89-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/examples/heightmap.c -o CMakeFiles/heightmap.dir/heightmap.c.s

glfw-3.3.6/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o: glfw-3.3.6/examples/CMakeFiles/heightmap.dir/flags.make
glfw-3.3.6/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o: ../glfw-3.3.6/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw-3.3.6/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o"
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples && /usr/bin/c89-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o   -c /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/deps/glad_gl.c

glfw-3.3.6/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/heightmap.dir/__/deps/glad_gl.c.i"
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples && /usr/bin/c89-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/deps/glad_gl.c > CMakeFiles/heightmap.dir/__/deps/glad_gl.c.i

glfw-3.3.6/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/heightmap.dir/__/deps/glad_gl.c.s"
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples && /usr/bin/c89-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/deps/glad_gl.c -o CMakeFiles/heightmap.dir/__/deps/glad_gl.c.s

# Object files for target heightmap
heightmap_OBJECTS = \
"CMakeFiles/heightmap.dir/heightmap.c.o" \
"CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o"

# External object files for target heightmap
heightmap_EXTERNAL_OBJECTS =

glfw-3.3.6/examples/heightmap: glfw-3.3.6/examples/CMakeFiles/heightmap.dir/heightmap.c.o
glfw-3.3.6/examples/heightmap: glfw-3.3.6/examples/CMakeFiles/heightmap.dir/__/deps/glad_gl.c.o
glfw-3.3.6/examples/heightmap: glfw-3.3.6/examples/CMakeFiles/heightmap.dir/build.make
glfw-3.3.6/examples/heightmap: glfw-3.3.6/src/libglfw3d.a
glfw-3.3.6/examples/heightmap: /usr/lib/x86_64-linux-gnu/libm.so
glfw-3.3.6/examples/heightmap: /usr/lib/x86_64-linux-gnu/librt.so
glfw-3.3.6/examples/heightmap: /usr/lib/x86_64-linux-gnu/libm.so
glfw-3.3.6/examples/heightmap: /usr/lib/x86_64-linux-gnu/libX11.so
glfw-3.3.6/examples/heightmap: glfw-3.3.6/examples/CMakeFiles/heightmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable heightmap"
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heightmap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw-3.3.6/examples/CMakeFiles/heightmap.dir/build: glfw-3.3.6/examples/heightmap

.PHONY : glfw-3.3.6/examples/CMakeFiles/heightmap.dir/build

glfw-3.3.6/examples/CMakeFiles/heightmap.dir/clean:
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples && $(CMAKE_COMMAND) -P CMakeFiles/heightmap.dir/cmake_clean.cmake
.PHONY : glfw-3.3.6/examples/CMakeFiles/heightmap.dir/clean

glfw-3.3.6/examples/CMakeFiles/heightmap.dir/depend:
	cd /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/glfw-3.3.6/examples /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples /home/benoit/Documents/GitHub/Doom-Quake-CG/doom-quake/build/glfw-3.3.6/examples/CMakeFiles/heightmap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw-3.3.6/examples/CMakeFiles/heightmap.dir/depend

