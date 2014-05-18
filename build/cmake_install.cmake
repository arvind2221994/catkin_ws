# Install script for directory: /home/sudha/catkin_ws/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/sudha/catkin_ws/install")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sudha/catkin_ws/install/.catkin")
FILE(INSTALL DESTINATION "/home/sudha/catkin_ws/install" TYPE FILE FILES "/home/sudha/catkin_ws/build/catkin_generated/installspace/.catkin")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sudha/catkin_ws/install/_setup_util.py")
FILE(INSTALL DESTINATION "/home/sudha/catkin_ws/install" TYPE PROGRAM FILES "/home/sudha/catkin_ws/build/catkin_generated/installspace/_setup_util.py")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sudha/catkin_ws/install/env.sh")
FILE(INSTALL DESTINATION "/home/sudha/catkin_ws/install" TYPE PROGRAM FILES "/home/sudha/catkin_ws/build/catkin_generated/installspace/env.sh")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sudha/catkin_ws/install/setup.bash")
FILE(INSTALL DESTINATION "/home/sudha/catkin_ws/install" TYPE FILE FILES "/home/sudha/catkin_ws/build/catkin_generated/installspace/setup.bash")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sudha/catkin_ws/install/setup.sh")
FILE(INSTALL DESTINATION "/home/sudha/catkin_ws/install" TYPE FILE FILES "/home/sudha/catkin_ws/build/catkin_generated/installspace/setup.sh")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sudha/catkin_ws/install/setup.zsh")
FILE(INSTALL DESTINATION "/home/sudha/catkin_ws/install" TYPE FILE FILES "/home/sudha/catkin_ws/build/catkin_generated/installspace/setup.zsh")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sudha/catkin_ws/install/.rosinstall")
FILE(INSTALL DESTINATION "/home/sudha/catkin_ws/install" TYPE FILE FILES "/home/sudha/catkin_ws/build/catkin_generated/installspace/.rosinstall")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/etc/catkin/profile.d" TYPE FILE FILES "/opt/ros/hydro/share/catkin/cmake/env-hooks/05.catkin_make.bash")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/etc/catkin/profile.d" TYPE FILE FILES "/opt/ros/hydro/share/catkin/cmake/env-hooks/05.catkin_make_isolated.bash")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/sudha/catkin_ws/build/gtest/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/abhiyan_description/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/geometry-hydro-devel/eigen_conversions/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/geometry-hydro-devel/geometry/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/gps_umd/gps_common/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/gps_umd/gps_umd/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/gps_umd/gpsd_client/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/gps_t/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/ip/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/geometry-hydro-devel/kdl_conversions/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/RCPRG_laser_drivers/liblms1xx/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/litemsgs/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/RCPRG_laser_drivers/lms1xx/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/move_base_msgs/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/navigation/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rosserial/rosserial/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rosserial/rosserial_client/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rosserial/rosserial_msgs/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rosserial/rosserial_python/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rosserial/rosserial_server/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rosserial/rosserial_xbee/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/simple_navigation_goals/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/slam_gmapping-hydro-devel/slam_gmapping/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/temp/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/geometry-hydro-devel/tf/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/fake_localization/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/slam_gmapping-hydro-devel/gmapping/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/lite_odom/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/map_server/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/amcl/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/r2d2/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/razor_imu_9dof-master/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/robot_pose_ekf/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/robot_tf_config/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rosserial/rosserial_arduino/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rosserial/rosserial_embeddedlinux/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/geometry-hydro-devel/tf_conversions/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/uprobotics/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/voxel_grid/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/costmap_2d/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/nav_core/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/base_local_planner/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/carrot_planner/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/clear_costmap_recovery/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/dwa_local_planner/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/move_slow_and_clear/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/navfn/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/global_planner/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/rotate_recovery/cmake_install.cmake")
  INCLUDE("/home/sudha/catkin_ws/build/move_base/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/sudha/catkin_ws/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/sudha/catkin_ws/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
