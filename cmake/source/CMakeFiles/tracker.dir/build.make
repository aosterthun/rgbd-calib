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
include source/CMakeFiles/tracker.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/tracker.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/tracker.dir/flags.make

source/CMakeFiles/tracker.dir/tracker.cpp.o: source/CMakeFiles/tracker.dir/flags.make
source/CMakeFiles/tracker.dir/tracker.cpp.o: ../source/tracker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tuje8374/rgbd/rgbd-calib/cmake/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object source/CMakeFiles/tracker.dir/tracker.cpp.o"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tracker.dir/tracker.cpp.o -c /home/tuje8374/rgbd/rgbd-calib/source/tracker.cpp

source/CMakeFiles/tracker.dir/tracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tracker.dir/tracker.cpp.i"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tuje8374/rgbd/rgbd-calib/source/tracker.cpp > CMakeFiles/tracker.dir/tracker.cpp.i

source/CMakeFiles/tracker.dir/tracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tracker.dir/tracker.cpp.s"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tuje8374/rgbd/rgbd-calib/source/tracker.cpp -o CMakeFiles/tracker.dir/tracker.cpp.s

source/CMakeFiles/tracker.dir/tracker.cpp.o.requires:
.PHONY : source/CMakeFiles/tracker.dir/tracker.cpp.o.requires

source/CMakeFiles/tracker.dir/tracker.cpp.o.provides: source/CMakeFiles/tracker.dir/tracker.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/tracker.dir/build.make source/CMakeFiles/tracker.dir/tracker.cpp.o.provides.build
.PHONY : source/CMakeFiles/tracker.dir/tracker.cpp.o.provides

source/CMakeFiles/tracker.dir/tracker.cpp.o.provides.build: source/CMakeFiles/tracker.dir/tracker.cpp.o

# Object files for target tracker
tracker_OBJECTS = \
"CMakeFiles/tracker.dir/tracker.cpp.o"

# External object files for target tracker
tracker_EXTERNAL_OBJECTS =

Debug/tracker: source/CMakeFiles/tracker.dir/tracker.cpp.o
Debug/tracker: source/CMakeFiles/tracker.dir/build.make
Debug/tracker: Debug/libframework.a
Debug/tracker: external/glfw-3.0.3/src/libglfw3.a
Debug/tracker: /usr/lib/x86_64-linux-gnu/libX11.so
Debug/tracker: /usr/lib/x86_64-linux-gnu/libXrandr.so
Debug/tracker: /usr/lib/x86_64-linux-gnu/libXi.so
Debug/tracker: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
Debug/tracker: /usr/lib/x86_64-linux-gnu/librt.so
Debug/tracker: /usr/lib/x86_64-linux-gnu/libm.so
Debug/tracker: /usr/lib/x86_64-linux-gnu/libGL.so
Debug/tracker: /opt/zmq/current/lib/libzmq.so
Debug/tracker: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_core.so
Debug/tracker: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_imgproc.so
Debug/tracker: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_highgui.so
Debug/tracker: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_calib3d.so
Debug/tracker: /opt/cgal/lib/libCGAL.so
Debug/tracker: /opt/boost/boost_1_55_0/lib/libboost_thread.so
Debug/tracker: /opt/boost/boost_1_55_0/lib/libboost_system.so
Debug/tracker: /usr/lib/x86_64-linux-gnu/libpthread.so
Debug/tracker: external/squish/libsquishd.a
Debug/tracker: /opt/gmp/lib/libgmp.so
Debug/tracker: /opt/mpfr/lib/libmpfr.so
Debug/tracker: source/CMakeFiles/tracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../Debug/tracker"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/tracker.dir/build: Debug/tracker
.PHONY : source/CMakeFiles/tracker.dir/build

source/CMakeFiles/tracker.dir/requires: source/CMakeFiles/tracker.dir/tracker.cpp.o.requires
.PHONY : source/CMakeFiles/tracker.dir/requires

source/CMakeFiles/tracker.dir/clean:
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && $(CMAKE_COMMAND) -P CMakeFiles/tracker.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/tracker.dir/clean

source/CMakeFiles/tracker.dir/depend:
	cd /home/tuje8374/rgbd/rgbd-calib/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tuje8374/rgbd/rgbd-calib /home/tuje8374/rgbd/rgbd-calib/source /home/tuje8374/rgbd/rgbd-calib/cmake /home/tuje8374/rgbd/rgbd-calib/cmake/source /home/tuje8374/rgbd/rgbd-calib/cmake/source/CMakeFiles/tracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/tracker.dir/depend

