# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/arne/Documents/cLion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/arne/Documents/cLion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug

# Include any dependencies generated for this target.
include source/CMakeFiles/play.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/play.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/play.dir/flags.make

source/CMakeFiles/play.dir/play.cpp.o: source/CMakeFiles/play.dir/flags.make
source/CMakeFiles/play.dir/play.cpp.o: ../source/play.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/play.dir/play.cpp.o"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/play.dir/play.cpp.o -c /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/play.cpp

source/CMakeFiles/play.dir/play.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/play.dir/play.cpp.i"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/play.cpp > CMakeFiles/play.dir/play.cpp.i

source/CMakeFiles/play.dir/play.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/play.dir/play.cpp.s"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/play.cpp -o CMakeFiles/play.dir/play.cpp.s

source/CMakeFiles/play.dir/play.cpp.o.requires:

.PHONY : source/CMakeFiles/play.dir/play.cpp.o.requires

source/CMakeFiles/play.dir/play.cpp.o.provides: source/CMakeFiles/play.dir/play.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/play.dir/build.make source/CMakeFiles/play.dir/play.cpp.o.provides.build
.PHONY : source/CMakeFiles/play.dir/play.cpp.o.provides

source/CMakeFiles/play.dir/play.cpp.o.provides.build: source/CMakeFiles/play.dir/play.cpp.o


# Object files for target play
play_OBJECTS = \
"CMakeFiles/play.dir/play.cpp.o"

# External object files for target play
play_EXTERNAL_OBJECTS =

Debug/play: source/CMakeFiles/play.dir/play.cpp.o
Debug/play: source/CMakeFiles/play.dir/build.make
Debug/play: Debug/libframework.a
Debug/play: external/glfw-3.0.3/src/libglfw3.a
Debug/play: /usr/lib/x86_64-linux-gnu/libX11.so
Debug/play: /usr/lib/x86_64-linux-gnu/libXrandr.so
Debug/play: /usr/lib/x86_64-linux-gnu/libXi.so
Debug/play: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
Debug/play: /usr/lib/x86_64-linux-gnu/librt.so
Debug/play: /usr/lib/x86_64-linux-gnu/libm.so
Debug/play: /usr/lib/x86_64-linux-gnu/libGL.so
Debug/play: /usr/lib/x86_64-linux-gnu/libzmq.so
Debug/play: /usr/lib/x86_64-linux-gnu/libopencv_core.so
Debug/play: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so
Debug/play: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so
Debug/play: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so
Debug/play: /usr/lib/x86_64-linux-gnu/libCGAL.so
Debug/play: /usr/lib/x86_64-linux-gnu/libboost_thread.so
Debug/play: /usr/lib/x86_64-linux-gnu/libboost_system.so
Debug/play: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
Debug/play: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
Debug/play: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
Debug/play: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
Debug/play: external/squish/libsquishd.a
Debug/play: /usr/lib/x86_64-linux-gnu/libgmp.so
Debug/play: /usr/lib/x86_64-linux-gnu/libmpfr.so
Debug/play: source/CMakeFiles/play.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../Debug/play"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/play.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/play.dir/build: Debug/play

.PHONY : source/CMakeFiles/play.dir/build

source/CMakeFiles/play.dir/requires: source/CMakeFiles/play.dir/play.cpp.o.requires

.PHONY : source/CMakeFiles/play.dir/requires

source/CMakeFiles/play.dir/clean:
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && $(CMAKE_COMMAND) -P CMakeFiles/play.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/play.dir/clean

source/CMakeFiles/play.dir/depend:
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source/CMakeFiles/play.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/play.dir/depend
