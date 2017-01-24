# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/tuje8374/rgbd/rgbd-calib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tuje8374/rgbd/rgbd-calib/cmake

# Include any dependencies generated for this target.
include source/CMakeFiles/measure_pose_offset.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/measure_pose_offset.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/measure_pose_offset.dir/flags.make

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o: source/CMakeFiles/measure_pose_offset.dir/flags.make
source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o: ../source/measure_pose_offset.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tuje8374/rgbd/rgbd-calib/cmake/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o -c /home/tuje8374/rgbd/rgbd-calib/source/measure_pose_offset.cpp

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.i"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tuje8374/rgbd/rgbd-calib/source/measure_pose_offset.cpp > CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.i

source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.s"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tuje8374/rgbd/rgbd-calib/source/measure_pose_offset.cpp -o CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.s

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
Debug/measure_pose_offset: /opt/zmq/current/lib/libzmq.so
Debug/measure_pose_offset: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_core.so
Debug/measure_pose_offset: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_imgproc.so
Debug/measure_pose_offset: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_highgui.so
Debug/measure_pose_offset: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_calib3d.so
Debug/measure_pose_offset: /opt/cgal/lib/libCGAL.so
Debug/measure_pose_offset: /opt/boost/boost_1_55_0/lib/libboost_thread.so
Debug/measure_pose_offset: /opt/boost/boost_1_55_0/lib/libboost_system.so
Debug/measure_pose_offset: /usr/lib/x86_64-linux-gnu/libpthread.so
Debug/measure_pose_offset: external/squish/libsquishd.a
Debug/measure_pose_offset: /opt/gmp/lib/libgmp.so
Debug/measure_pose_offset: /opt/mpfr/lib/libmpfr.so
Debug/measure_pose_offset: source/CMakeFiles/measure_pose_offset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../Debug/measure_pose_offset"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/measure_pose_offset.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/measure_pose_offset.dir/build: Debug/measure_pose_offset
.PHONY : source/CMakeFiles/measure_pose_offset.dir/build

source/CMakeFiles/measure_pose_offset.dir/requires: source/CMakeFiles/measure_pose_offset.dir/measure_pose_offset.cpp.o.requires
.PHONY : source/CMakeFiles/measure_pose_offset.dir/requires

source/CMakeFiles/measure_pose_offset.dir/clean:
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && $(CMAKE_COMMAND) -P CMakeFiles/measure_pose_offset.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/measure_pose_offset.dir/clean

source/CMakeFiles/measure_pose_offset.dir/depend:
	cd /home/tuje8374/rgbd/rgbd-calib/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tuje8374/rgbd/rgbd-calib /home/tuje8374/rgbd/rgbd-calib/source /home/tuje8374/rgbd/rgbd-calib/cmake /home/tuje8374/rgbd/rgbd-calib/cmake/source /home/tuje8374/rgbd/rgbd-calib/cmake/source/CMakeFiles/measure_pose_offset.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/measure_pose_offset.dir/depend

