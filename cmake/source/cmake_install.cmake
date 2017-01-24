# Install script for directory: /home/tuje8374/rgbd/rgbd-calib/source

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/tuje8374/rgbd/rgbd-calib/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/measure_pose_offset" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/measure_pose_offset")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/measure_pose_offset"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/measure_pose_offset")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/measure_pose_offset" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/measure_pose_offset")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/measure_pose_offset"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/measure_pose_offset")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_sender" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_sender")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_sender"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/zmq_sender")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_sender" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_sender")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_sender"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_sender")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_receiver" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_receiver")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_receiver"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/zmq_receiver")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_receiver" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_receiver")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_receiver"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/zmq_receiver")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/viewer")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/viewer"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/viewer")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/viewer")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/viewer"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/viewer")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tracker" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tracker")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tracker"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/tracker")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tracker" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tracker")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tracker"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/tracker")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/initialize" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/initialize")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/initialize"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/initialize")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/initialize" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/initialize")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/initialize"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/initialize")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/stable_sampler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/stable_sampler")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/stable_sampler"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/stable_sampler")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/stable_sampler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/stable_sampler")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/stable_sampler"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/stable_sampler")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rgbdir_viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rgbdir_viewer")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rgbdir_viewer"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/rgbdir_viewer")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rgbdir_viewer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rgbdir_viewer")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rgbdir_viewer"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/rgbdir_viewer")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate_intrinsic" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate_intrinsic")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate_intrinsic"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/calibrate_intrinsic")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate_intrinsic" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate_intrinsic")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate_intrinsic"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate_intrinsic")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_sampler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_sampler")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_sampler"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/sweep_sampler")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_sampler" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_sampler")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_sampler"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_sampler")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/display_sweep" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/display_sweep")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/display_sweep"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/display_sweep")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/display_sweep" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/display_sweep")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/display_sweep"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/display_sweep")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/test_stuff" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/test_stuff")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/test_stuff"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/test_stuff")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/test_stuff" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/test_stuff")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/test_stuff"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/test_stuff")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/calibrate")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/calibrate")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_calibrate" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_calibrate")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_calibrate"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/sweep_calibrate")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_calibrate" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_calibrate")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_calibrate"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_calibrate")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/evaluate" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/evaluate")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/evaluate"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/evaluate")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/evaluate" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/evaluate")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/evaluate"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/evaluate")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/split_samples" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/split_samples")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/split_samples"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/split_samples")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/split_samples" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/split_samples")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/split_samples"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/split_samples")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/record" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/record")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/record"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/record")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/record" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/record")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/record"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/record")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/play")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play_sweep" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play_sweep")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play_sweep"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/play_sweep")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play_sweep" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play_sweep")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play_sweep"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/play_sweep")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_stats" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_stats")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_stats"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/sweep_stats")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_stats" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_stats")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_stats"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/sweep_stats")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/convert_recording_to_point_cloud" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/convert_recording_to_point_cloud")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/convert_recording_to_point_cloud"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/convert_recording_to_point_cloud")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/convert_recording_to_point_cloud" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/convert_recording_to_point_cloud")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/convert_recording_to_point_cloud"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/convert_recording_to_point_cloud")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/send_recording_as_point_cloud" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/send_recording_as_point_cloud")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/send_recording_as_point_cloud"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/send_recording_as_point_cloud")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/send_recording_as_point_cloud" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/send_recording_as_point_cloud")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/send_recording_as_point_cloud"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/send_recording_as_point_cloud")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/voxelizer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/voxelizer")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/voxelizer"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/voxelizer")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/voxelizer" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/voxelizer")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/voxelizer"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/voxelizer")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kinect_daemon" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kinect_daemon")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kinect_daemon"
         RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/tuje8374/rgbd/rgbd-calib/cmake/Debug/kinect_daemon")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kinect_daemon" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kinect_daemon")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kinect_daemon"
         OLD_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib:"
         NEW_RPATH "/opt/zmq/current/lib:/opt/OpenCV/opencv-2.4.10_without_ffmpeg/lib:/opt/cgal/lib:/opt/boost/boost_1_55_0/lib:/opt/gmp/lib:/opt/mpfr/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/kinect_daemon")
    endif()
  endif()
endif()

