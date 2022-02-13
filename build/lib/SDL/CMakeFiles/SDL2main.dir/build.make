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
CMAKE_SOURCE_DIR = /home/zachary/projects/game-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zachary/projects/game-engine/build

# Include any dependencies generated for this target.
include lib/SDL/CMakeFiles/SDL2main.dir/depend.make

# Include the progress variables for this target.
include lib/SDL/CMakeFiles/SDL2main.dir/progress.make

# Include the compile flags for this target's objects.
include lib/SDL/CMakeFiles/SDL2main.dir/flags.make

lib/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o: lib/SDL/CMakeFiles/SDL2main.dir/flags.make
lib/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o: ../lib/SDL/src/main/dummy/SDL_dummy_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o"
	cd /home/zachary/projects/game-engine/build/lib/SDL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o   -c /home/zachary/projects/game-engine/lib/SDL/src/main/dummy/SDL_dummy_main.c

lib/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i"
	cd /home/zachary/projects/game-engine/build/lib/SDL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zachary/projects/game-engine/lib/SDL/src/main/dummy/SDL_dummy_main.c > CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i

lib/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s"
	cd /home/zachary/projects/game-engine/build/lib/SDL && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zachary/projects/game-engine/lib/SDL/src/main/dummy/SDL_dummy_main.c -o CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s

# Object files for target SDL2main
SDL2main_OBJECTS = \
"CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o"

# External object files for target SDL2main
SDL2main_EXTERNAL_OBJECTS =

lib/SDL/libSDL2maind.a: lib/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o
lib/SDL/libSDL2maind.a: lib/SDL/CMakeFiles/SDL2main.dir/build.make
lib/SDL/libSDL2maind.a: lib/SDL/CMakeFiles/SDL2main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libSDL2maind.a"
	cd /home/zachary/projects/game-engine/build/lib/SDL && $(CMAKE_COMMAND) -P CMakeFiles/SDL2main.dir/cmake_clean_target.cmake
	cd /home/zachary/projects/game-engine/build/lib/SDL && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/SDL/CMakeFiles/SDL2main.dir/build: lib/SDL/libSDL2maind.a

.PHONY : lib/SDL/CMakeFiles/SDL2main.dir/build

lib/SDL/CMakeFiles/SDL2main.dir/clean:
	cd /home/zachary/projects/game-engine/build/lib/SDL && $(CMAKE_COMMAND) -P CMakeFiles/SDL2main.dir/cmake_clean.cmake
.PHONY : lib/SDL/CMakeFiles/SDL2main.dir/clean

lib/SDL/CMakeFiles/SDL2main.dir/depend:
	cd /home/zachary/projects/game-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zachary/projects/game-engine /home/zachary/projects/game-engine/lib/SDL /home/zachary/projects/game-engine/build /home/zachary/projects/game-engine/build/lib/SDL /home/zachary/projects/game-engine/build/lib/SDL/CMakeFiles/SDL2main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/SDL/CMakeFiles/SDL2main.dir/depend

