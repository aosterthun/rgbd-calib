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
include source/CMakeFiles/measure_pose_offset.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/measure_pose_offset.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/measure_pose_offset.dir/flags.make

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o: source/CMakeFiles/measure_pose_offset.dir/flags.make
source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o: ../source/measure_pose_offset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o -c /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/measure_pose_offset.cpp

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.i"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/measure_pose_offset.cpp > CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.i

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.s"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/measure_pose_offset.cpp -o CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.s

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.requires:

.PHONY : source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.requires

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.provides: source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/measure_pose_offset.dir/build.make source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.provides.build
.PHONY : source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.provides

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.provides.build: source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o


# Object files for target measure_pose_offset
measure_pose_offset_OBJECTS = \
"CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o"

# External object files for target measure_pose_offset
measure_pose_offset_EXTERNAL_OBJECTS =

Debug/measure_pose_offset: source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o
Debug/measure_pose_offset: source/CMakeFiles/measure_pose_offset.dir/build.make
Debug/measure_pose_offset: Debug/libframework.a
Debug/measure_pose_offset: external/glfw-3.0.3/src/libglfw3.a
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libX11.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libXrandr.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libXi.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/librt.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libm.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libGL.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libzmq.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libopencv_core.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libCGAL.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libboost_thread.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libboost_system.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
Debug/measure_pose_offset: external/squish/libsquishd.a
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libgmp.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libmpfr.so
Debug/measure_pose_offset: source/CMakeFiles/measure_pose_offset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../Debug/measure_pose_offset"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/measure_pose_offset.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/measure_pose_offset.dir/build: Debug/measure_pose_offset

.PHONY : source/CMakeFiles/measure_pose_offset.dir/build

source/CMakeFiles/measure_pose_offset.dir/requires: source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.requires

.PHONY : source/CMakeFiles/measure_pose_offset.dir/requires

source/CMakeFiles/measure_pose_offset.dir/clean:
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && $(CMAKE_COMMAND) -P CMakeFiles/measure_pose_offset.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/measure_pose_offset.dir/clean

source/CMakeFiles/measure_pose_offset.dir/depend:
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source/CMakeFiles/measure_pose_offset.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/measure_pose_offset.dir/depend
