add_executable(laser_max_range_filter.exe
               laser_max_range_filter.cpp)
target_link_libraries(laser_max_range_filter.exe
                      ${catkin_LIBRARIES})

add_executable(initial_status_sender
               initial_status_sender.cpp)
target_link_libraries(initial_status_sender
                      ${catkin_LIBRARIES})
