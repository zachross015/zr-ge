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
include CMakeFiles/GameEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GameEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameEngine.dir/flags.make

CMakeFiles/GameEngine.dir/src/main.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GameEngine.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/main.cpp.o -c /home/zachary/projects/game-engine/src/main.cpp

CMakeFiles/GameEngine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/main.cpp > CMakeFiles/GameEngine.dir/src/main.cpp.i

CMakeFiles/GameEngine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/main.cpp -o CMakeFiles/GameEngine.dir/src/main.cpp.s

CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.o: ../src/sdl_wrapper/blend_mode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.o -c /home/zachary/projects/game-engine/src/sdl_wrapper/blend_mode.cpp

CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/sdl_wrapper/blend_mode.cpp > CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.i

CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/sdl_wrapper/blend_mode.cpp -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.s

CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.o: ../src/sdl_wrapper/display_mode_config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.o -c /home/zachary/projects/game-engine/src/sdl_wrapper/display_mode_config.cpp

CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/sdl_wrapper/display_mode_config.cpp > CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.i

CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/sdl_wrapper/display_mode_config.cpp -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.s

CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.o: ../src/sdl_wrapper/pixel_format.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.o -c /home/zachary/projects/game-engine/src/sdl_wrapper/pixel_format.cpp

CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/sdl_wrapper/pixel_format.cpp > CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.i

CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/sdl_wrapper/pixel_format.cpp -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.s

CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.o: ../src/sdl_wrapper/render_dispatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.o -c /home/zachary/projects/game-engine/src/sdl_wrapper/render_dispatch.cpp

CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/sdl_wrapper/render_dispatch.cpp > CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.i

CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/sdl_wrapper/render_dispatch.cpp -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.s

CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.o: ../src/sdl_wrapper/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.o -c /home/zachary/projects/game-engine/src/sdl_wrapper/renderer.cpp

CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/sdl_wrapper/renderer.cpp > CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.i

CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/sdl_wrapper/renderer.cpp -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.s

CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.o: ../src/sdl_wrapper/sdl_exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.o -c /home/zachary/projects/game-engine/src/sdl_wrapper/sdl_exception.cpp

CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/sdl_wrapper/sdl_exception.cpp > CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.i

CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/sdl_wrapper/sdl_exception.cpp -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.s

CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.o: ../src/sdl_wrapper/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.o -c /home/zachary/projects/game-engine/src/sdl_wrapper/texture.cpp

CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/sdl_wrapper/texture.cpp > CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.i

CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/sdl_wrapper/texture.cpp -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.s

CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.o: ../src/sdl_wrapper/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.o -c /home/zachary/projects/game-engine/src/sdl_wrapper/window.cpp

CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/sdl_wrapper/window.cpp > CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.i

CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/sdl_wrapper/window.cpp -o CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.s

CMakeFiles/GameEngine.dir/src/util.cpp.o: CMakeFiles/GameEngine.dir/flags.make
CMakeFiles/GameEngine.dir/src/util.cpp.o: ../src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/GameEngine.dir/src/util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GameEngine.dir/src/util.cpp.o -c /home/zachary/projects/game-engine/src/util.cpp

CMakeFiles/GameEngine.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GameEngine.dir/src/util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zachary/projects/game-engine/src/util.cpp > CMakeFiles/GameEngine.dir/src/util.cpp.i

CMakeFiles/GameEngine.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GameEngine.dir/src/util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zachary/projects/game-engine/src/util.cpp -o CMakeFiles/GameEngine.dir/src/util.cpp.s

# Object files for target GameEngine
GameEngine_OBJECTS = \
"CMakeFiles/GameEngine.dir/src/main.cpp.o" \
"CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.o" \
"CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.o" \
"CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.o" \
"CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.o" \
"CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.o" \
"CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.o" \
"CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.o" \
"CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.o" \
"CMakeFiles/GameEngine.dir/src/util.cpp.o"

# External object files for target GameEngine
GameEngine_EXTERNAL_OBJECTS =

GameEngine: CMakeFiles/GameEngine.dir/src/main.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/sdl_wrapper/blend_mode.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/sdl_wrapper/display_mode_config.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/sdl_wrapper/pixel_format.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/sdl_wrapper/render_dispatch.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/sdl_wrapper/renderer.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/sdl_wrapper/sdl_exception.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/sdl_wrapper/texture.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/sdl_wrapper/window.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/src/util.cpp.o
GameEngine: CMakeFiles/GameEngine.dir/build.make
GameEngine: lib/armadillo-code/libarmadillo.so.10.8.2
GameEngine: lib/SDL/libSDL2-2.0d.so.0.18.3
GameEngine: /usr/lib/x86_64-linux-gnu/libblas.so
GameEngine: /usr/lib/x86_64-linux-gnu/liblapack.so
GameEngine: CMakeFiles/GameEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zachary/projects/game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable GameEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameEngine.dir/build: GameEngine

.PHONY : CMakeFiles/GameEngine.dir/build

CMakeFiles/GameEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameEngine.dir/clean

CMakeFiles/GameEngine.dir/depend:
	cd /home/zachary/projects/game-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zachary/projects/game-engine /home/zachary/projects/game-engine /home/zachary/projects/game-engine/build /home/zachary/projects/game-engine/build /home/zachary/projects/game-engine/build/CMakeFiles/GameEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GameEngine.dir/depend

