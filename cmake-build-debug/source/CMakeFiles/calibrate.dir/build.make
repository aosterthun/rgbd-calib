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
include source/CMakeFiles/calibrate.dir/depend.make

# Include the progress variables for this target.
include source/CMakeFiles/calibrate.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/calibrate.dir/flags.make

source/CMakeFiles/calibrate.dir/calibrate.cpp.o: source/CMakeFiles/calibrate.dir/flags.make
source/CMakeFiles/calibrate.dir/calibrate.cpp.o: ../source/calibrate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/calibrate.dir/calibrate.cpp.o"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calibrate.dir/calibrate.cpp.o -c /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/calibrate.cpp

source/CMakeFiles/calibrate.dir/calibrate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calibrate.dir/calibrate.cpp.i"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/calibrate.cpp > CMakeFiles/calibrate.dir/calibrate.cpp.i

source/CMakeFiles/calibrate.dir/calibrate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calibrate.dir/calibrate.cpp.s"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source/calibrate.cpp -o CMakeFiles/calibrate.dir/calibrate.cpp.s

source/CMakeFiles/calibrate.dir/calibrate.cpp.o.requires:

.PHONY : source/CMakeFiles/calibrate.dir/calibrate.cpp.o.requires

source/CMakeFiles/calibrate.dir/calibrate.cpp.o.provides: source/CMakeFiles/calibrate.dir/calibrate.cpp.o.requires
	$(MAKE) -f source/CMakeFiles/calibrate.dir/build.make source/CMakeFiles/calibrate.dir/calibrate.cpp.o.provides.build
.PHONY : source/CMakeFiles/calibrate.dir/calibrate.cpp.o.provides

source/CMakeFiles/calibrate.dir/calibrate.cpp.o.provides.build: source/CMakeFiles/calibrate.dir/calibrate.cpp.o


# Object files for target calibrate
calibrate_OBJECTS = \
"CMakeFiles/calibrate.dir/calibrate.cpp.o"

# External object files for target calibrate
calibrate_EXTERNAL_OBJECTS =

Debug/calibrate: source/CMakeFiles/calibrate.dir/calibrate.cpp.o
Debug/calibrate: source/CMakeFiles/calibrate.dir/build.make
Debug/calibrate: Debug/libframework.a
Debug/calibrate: external/glfw-3.0.3/src/libglfw3.a
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libX11.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libXrandr.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libXi.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/librt.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libm.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libGL.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libzmq.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libopencv_core.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libCGAL.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libboost_thread.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libboost_system.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
Debug/calibrate: external/squish/libsquishd.a
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libgmp.so
Debug/calibrate: /usr/lib/x86_64-linux-gnu/libmpfr.so
Debug/calibrate: source/CMakeFiles/calibrate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../Debug/calibrate"
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calibrate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/calibrate.dir/build: Debug/calibrate

.PHONY : source/CMakeFiles/calibrate.dir/build

source/CMakeFiles/calibrate.dir/requires: source/CMakeFiles/calibrate.dir/calibrate.cpp.o.requires

.PHONY : source/CMakeFiles/calibrate.dir/requires

source/CMakeFiles/calibrate.dir/clean:
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source && $(CMAKE_COMMAND) -P CMakeFiles/calibrate.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/calibrate.dir/clean

source/CMakeFiles/calibrate.dir/depend:
	cd /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/source /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source /home/arne/Documents/Hiwi/KinectDaemon/rgbd-calib/cmake-build-debug/source/CMakeFiles/calibrate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/calibrate.dir/depend

