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
include source/CMakeFiles/evaluate.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/evaluate.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/evaluate.dir/flags.make

source/CMakeFiles/evaluate.dir/evaluate.cpp.o: source/CMakeFiles/evaluate.dir/flags.make
source/CMakeFiles/evaluate.dir/evaluate.cpp.o: ../source/evaluate.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tuje8374/rgbd/rgbd-calib/cmake/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object source/CMakeFiles/evaluate.dir/evaluate.cpp.o"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/evaluate.dir/evaluate.cpp.o -c /home/tuje8374/rgbd/rgbd-calib/source/evaluate.cpp

source/CMakeFiles/evaluate.dir/evaluate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evaluate.dir/evaluate.cpp.i"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tuje8374/rgbd/rgbd-calib/source/evaluate.cpp > CMakeFiles/evaluate.dir/evaluate.cpp.i

source/CMakeFiles/evaluate.dir/evaluate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evaluate.dir/evaluate.cpp.s"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && /usr/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tuje8374/rgbd/rgbd-calib/source/evaluate.cpp -o CMakeFiles/evaluate.dir/evaluate.cpp.s

source/CMakeFiles/evaluate.dir/evaluate.cpp.o.requires:
.PHONY : source/CMakeFiles/evaluate.dir/evaluate.cpp.o.requires

source/CMakeFiles/evaluate.dir/evaluate.cpp.o.provides: source/CMakeFiles/evaluate.dir/evaluate.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/evaluate.dir/build.make source/CMakeFiles/evaluate.dir/evaluate.cpp.o.provides.build
.PHONY : source/CMakeFiles/evaluate.dir/evaluate.cpp.o.provides

source/CMakeFiles/evaluate.dir/evaluate.cpp.o.provides.build: source/CMakeFiles/evaluate.dir/evaluate.cpp.o

# Object files for target evaluate
evaluate_OBJECTS = \
"CMakeFiles/evaluate.dir/evaluate.cpp.o"

# External object files for target evaluate
evaluate_EXTERNAL_OBJECTS =

Debug/evaluate: source/CMakeFiles/evaluate.dir/evaluate.cpp.o
Debug/evaluate: source/CMakeFiles/evaluate.dir/build.make
Debug/evaluate: Debug/libframework.a
Debug/evaluate: external/glfw-3.0.3/src/libglfw3.a
Debug/evaluate: /usr/lib/x86_64-linux-gnu/libX11.so
Debug/evaluate: /usr/lib/x86_64-linux-gnu/libXrandr.so
Debug/evaluate: /usr/lib/x86_64-linux-gnu/libXi.so
Debug/evaluate: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
Debug/evaluate: /usr/lib/x86_64-linux-gnu/librt.so
Debug/evaluate: /usr/lib/x86_64-linux-gnu/libm.so
Debug/evaluate: /usr/lib/x86_64-linux-gnu/libGL.so
Debug/evaluate: /opt/zmq/current/lib/libzmq.so
Debug/evaluate: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_core.so
Debug/evaluate: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_imgproc.so
Debug/evaluate: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_highgui.so
Debug/evaluate: /opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib/libopencv_calib3d.so
Debug/evaluate: /opt/cgal/lib/libCGAL.so
Debug/evaluate: /opt/boost/boost_1_55_0/lib/libboost_thread.so
Debug/evaluate: /opt/boost/boost_1_55_0/lib/libboost_system.so
Debug/evaluate: /usr/lib/x86_64-linux-gnu/libpthread.so
Debug/evaluate: external/squish/libsquishd.a
Debug/evaluate: /opt/gmp/lib/libgmp.so
Debug/evaluate: /opt/mpfr/lib/libmpfr.so
Debug/evaluate: source/CMakeFiles/evaluate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../Debug/evaluate"
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/evaluate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/evaluate.dir/build: Debug/evaluate
.PHONY : source/CMakeFiles/evaluate.dir/build

source/CMakeFiles/evaluate.dir/requires: source/CMakeFiles/evaluate.dir/evaluate.cpp.o.requires
.PHONY : source/CMakeFiles/evaluate.dir/requires

source/CMakeFiles/evaluate.dir/clean:
	cd /home/tuje8374/rgbd/rgbd-calib/cmake/source && $(CMAKE_COMMAND) -P CMakeFiles/evaluate.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/evaluate.dir/clean

source/CMakeFiles/evaluate.dir/depend:
	cd /home/tuje8374/rgbd/rgbd-calib/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tuje8374/rgbd/rgbd-calib /home/tuje8374/rgbd/rgbd-calib/source /home/tuje8374/rgbd/rgbd-calib/cmake /home/tuje8374/rgbd/rgbd-calib/cmake/source /home/tuje8374/rgbd/rgbd-calib/cmake/source/CMakeFiles/evaluate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/evaluate.dir/depend

