# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping

# Include any dependencies generated for this target.
include scanmatcher/CMakeFiles/scanmatcher.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include scanmatcher/CMakeFiles/scanmatcher.dir/compiler_depend.make

# Include the progress variables for this target.
include scanmatcher/CMakeFiles/scanmatcher.dir/progress.make

# Include the compile flags for this target's objects.
include scanmatcher/CMakeFiles/scanmatcher.dir/flags.make

scanmatcher/CMakeFiles/scanmatcher.dir/eig3.cpp.o: scanmatcher/CMakeFiles/scanmatcher.dir/flags.make
scanmatcher/CMakeFiles/scanmatcher.dir/eig3.cpp.o: /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/eig3.cpp
scanmatcher/CMakeFiles/scanmatcher.dir/eig3.cpp.o: scanmatcher/CMakeFiles/scanmatcher.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object scanmatcher/CMakeFiles/scanmatcher.dir/eig3.cpp.o"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scanmatcher/CMakeFiles/scanmatcher.dir/eig3.cpp.o -MF CMakeFiles/scanmatcher.dir/eig3.cpp.o.d -o CMakeFiles/scanmatcher.dir/eig3.cpp.o -c /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/eig3.cpp

scanmatcher/CMakeFiles/scanmatcher.dir/eig3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scanmatcher.dir/eig3.cpp.i"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/eig3.cpp > CMakeFiles/scanmatcher.dir/eig3.cpp.i

scanmatcher/CMakeFiles/scanmatcher.dir/eig3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scanmatcher.dir/eig3.cpp.s"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/eig3.cpp -o CMakeFiles/scanmatcher.dir/eig3.cpp.s

scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o: scanmatcher/CMakeFiles/scanmatcher.dir/flags.make
scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o: /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/scanmatcher.cpp
scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o: scanmatcher/CMakeFiles/scanmatcher.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o -MF CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o.d -o CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o -c /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/scanmatcher.cpp

scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scanmatcher.dir/scanmatcher.cpp.i"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/scanmatcher.cpp > CMakeFiles/scanmatcher.dir/scanmatcher.cpp.i

scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scanmatcher.dir/scanmatcher.cpp.s"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/scanmatcher.cpp -o CMakeFiles/scanmatcher.dir/scanmatcher.cpp.s

scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o: scanmatcher/CMakeFiles/scanmatcher.dir/flags.make
scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o: /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/scanmatcherprocessor.cpp
scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o: scanmatcher/CMakeFiles/scanmatcher.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o -MF CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o.d -o CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o -c /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/scanmatcherprocessor.cpp

scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.i"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/scanmatcherprocessor.cpp > CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.i

scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.s"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/scanmatcherprocessor.cpp -o CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.s

scanmatcher/CMakeFiles/scanmatcher.dir/smmap.cpp.o: scanmatcher/CMakeFiles/scanmatcher.dir/flags.make
scanmatcher/CMakeFiles/scanmatcher.dir/smmap.cpp.o: /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/smmap.cpp
scanmatcher/CMakeFiles/scanmatcher.dir/smmap.cpp.o: scanmatcher/CMakeFiles/scanmatcher.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object scanmatcher/CMakeFiles/scanmatcher.dir/smmap.cpp.o"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT scanmatcher/CMakeFiles/scanmatcher.dir/smmap.cpp.o -MF CMakeFiles/scanmatcher.dir/smmap.cpp.o.d -o CMakeFiles/scanmatcher.dir/smmap.cpp.o -c /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/smmap.cpp

scanmatcher/CMakeFiles/scanmatcher.dir/smmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scanmatcher.dir/smmap.cpp.i"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/smmap.cpp > CMakeFiles/scanmatcher.dir/smmap.cpp.i

scanmatcher/CMakeFiles/scanmatcher.dir/smmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scanmatcher.dir/smmap.cpp.s"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher/smmap.cpp -o CMakeFiles/scanmatcher.dir/smmap.cpp.s

# Object files for target scanmatcher
scanmatcher_OBJECTS = \
"CMakeFiles/scanmatcher.dir/eig3.cpp.o" \
"CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o" \
"CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o" \
"CMakeFiles/scanmatcher.dir/smmap.cpp.o"

# External object files for target scanmatcher
scanmatcher_EXTERNAL_OBJECTS =

scanmatcher/libscanmatcher.a: scanmatcher/CMakeFiles/scanmatcher.dir/eig3.cpp.o
scanmatcher/libscanmatcher.a: scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcher.cpp.o
scanmatcher/libscanmatcher.a: scanmatcher/CMakeFiles/scanmatcher.dir/scanmatcherprocessor.cpp.o
scanmatcher/libscanmatcher.a: scanmatcher/CMakeFiles/scanmatcher.dir/smmap.cpp.o
scanmatcher/libscanmatcher.a: scanmatcher/CMakeFiles/scanmatcher.dir/build.make
scanmatcher/libscanmatcher.a: scanmatcher/CMakeFiles/scanmatcher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libscanmatcher.a"
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && $(CMAKE_COMMAND) -P CMakeFiles/scanmatcher.dir/cmake_clean_target.cmake
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scanmatcher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
scanmatcher/CMakeFiles/scanmatcher.dir/build: scanmatcher/libscanmatcher.a
.PHONY : scanmatcher/CMakeFiles/scanmatcher.dir/build

scanmatcher/CMakeFiles/scanmatcher.dir/clean:
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher && $(CMAKE_COMMAND) -P CMakeFiles/scanmatcher.dir/cmake_clean.cmake
.PHONY : scanmatcher/CMakeFiles/scanmatcher.dir/clean

scanmatcher/CMakeFiles/scanmatcher.dir/depend:
	cd /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping /home/mr-cheng/Documents/ROS2/Car/src/slam_gmapping/openslam_gmapping/scanmatcher /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher /home/mr-cheng/Documents/ROS2/Car/build/openslam_gmapping/scanmatcher/CMakeFiles/scanmatcher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : scanmatcher/CMakeFiles/scanmatcher.dir/depend

