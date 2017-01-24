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
include source/CMakeFiles/initialize.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/initialize.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/initialize.dir/flags.make

source/CMakeFiles/initialize.dir/initialize.cpp.o: source/CMakeFiles/initialize.dir/flags.make
source/CMakeFiles/initialize.dir/initialize.cpp.o: ../source/initialize.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tuje8374/rgbd/rgbd-calib/cmake/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object source/CMakeFiles/initialize.dir/initialize.cpp.o"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/initialize.dir/initialize.cpp.o -c /home/tuje8374/rgbd/rgbd-calib/source/initialize.cpp

source/CMakeFiles/initialize.dir/initialize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/initialize.dir/initialize.cpp.i"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tuje8374/rgbd/rgbd-calib/source/initialize.cpp > CMakeFiles/initialize.dir/initialize.cpp.i

source/CMakeFiles/initialize.dir/initialize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/initialize.dir/initialize.cpp.s"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tuje8374/rgbd/rgbd-calib/source/initialize.cpp -o CMakeFiles/initialize.dir/initialize.cpp.s

source/CMakeFiles/initialize.dir/initialize.cpp.o.requires:
.PHONY : source/CMakeFiles/initialize.dir/initialize.cpp.o.requires

source/CMakeFiles/initialize.dir/initialize.cpp.o.provides: source/CMakeFiles/initialize.dir/initialize.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/initialize.dir/build.make source/CMakeFiles/initialize.dir/initialize.cpp.o.provides.build
.PHONY : source/CMakeFiles/initialize.dir/initialize.cpp.o.provides

source/CMakeFiles/initialize.dir/initialize.cpp.o.provides.build: source/CMakeFiles/initialize.dir/initialize.cpp.o

# Object files for target initialize
initialize_OBJECTS = \
"CMakeFiles/initialize.dir/initialize.cpp.o"

# External object files for target initialize
initialize_EXTERNAL_OBJECTS =

Debug/initialize: source/CMakeFiles/initialize.dir/initialize.cpp.o
Debug/initialize: source/CMakeFiles/initialize.dir/build.make
Debug/initialize: Debug/libframework.a
Debug/initialize: external/glfw-3.0.3/src/libglfw3.a
Debug/initialize: /usr/lib/x86_64-linux-gnu/libX11.so
Debug/initialize: /usr/lib/x86_64-linux-gnu/libXrandr.so
Debug/initialize: /usr/lib/x86_64-linux-gnu/libXi.so
Debug/initialize: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
Debug/initialize: /usr/lib/x86_64-linux-gnu/librt.so
Debug/initialize: /usr/lib/x86_64-linux-gnu/libm.so
Debug/initialize: /usr/lib/x86_64-linux-gnu/libGL.so
Debug/initialize: /opt/zmq/current/lib/libzmq.so
Debug/initialize: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_core.so
Debug/initialize: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_imgproc.so
Debug/initialize: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_highgui.so
Debug/initialize: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_calib3d.so
Debug/initialize: /opt/cgal/lib/libCGAL.so
Debug/initialize: /opt/boost/boost_1_55_0/lib/libboost_thread.so
Debug/initialize: /opt/boost/boost_1_55_0/lib/libboost_system.so
Debug/initialize: /usr/lib/x86_64-linux-gnu/libpthread.so
Debug/initialize: external/squish/libsquishd.a
Debug/initialize: /opt/gmp/lib/libgmp.so
Debug/initialize: /opt/mpfr/lib/libmpfr.so
Debug/initialize: source/CMakeFiles/initialize.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../Debug/initialize"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/initialize.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/initialize.dir/build: Debug/initialize
.PHONY : source/CMakeFiles/initialize.dir/build

source/CMakeFiles/initialize.dir/requires: source/CMakeFiles/initialize.dir/initialize.cpp.o.requires
.PHONY : source/CMakeFiles/initialize.dir/requires

source/CMakeFiles/initialize.dir/clean:
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && $(CMAKE_COMMAND) -P CMakeFiles/initialize.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/initialize.dir/clean

source/CMakeFiles/initialize.dir/depend:
	cd /home/tuje8374/rgbd/rgbd-calib/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tuje8374/rgbd/rgbd-calib /home/tuje8374/rgbd/rgbd-calib/source /home/tuje8374/rgbd/rgbd-calib/cmake /home/tuje8374/rgbd/rgbd-calib/cmake/source /home/tuje8374/rgbd/rgbd-calib/cmake/source/CMakeFiles/initialize.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/initialize.dir/depend

