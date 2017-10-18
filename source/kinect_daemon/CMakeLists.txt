add_executable(kinect_server main.cpp)
target_link_libraries(kinect_server framework)
install(TARGETS kinect_server DESTINATION bin)


