add_executable(teleop_joy.exe
               teleop_joy.cpp)
target_link_libraries(teleop_joy.exe
                      ${catkin_LIBRARIES})

add_executable(teleop_keyboard
               teleop_keyboard.cpp)
target_link_libraries(teleop_keyboard
                      ${catkin_LIBRARIES})
