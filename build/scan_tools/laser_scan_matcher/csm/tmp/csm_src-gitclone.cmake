if("23703a998fff57250322" STREQUAL "")
  message(FATAL_ERROR "Tag for git checkout should not be empty.")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/home/sudha/catkin_ws/build/scan_tools/laser_scan_matcher/csm/src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/sudha/catkin_ws/build/scan_tools/laser_scan_matcher/csm/src'")
endif()

execute_process(
  COMMAND "/usr/bin/git" clone "https://github.com/AndreaCensi/csm.git" "src"
  WORKING_DIRECTORY "/home/sudha/catkin_ws/build/scan_tools/laser_scan_matcher/csm"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/AndreaCensi/csm.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git" checkout 23703a998fff57250322
  WORKING_DIRECTORY "/home/sudha/catkin_ws/build/scan_tools/laser_scan_matcher/csm/src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '23703a998fff57250322'")
endif()

execute_process(
  COMMAND "/usr/bin/git" submodule init
  WORKING_DIRECTORY "/home/sudha/catkin_ws/build/scan_tools/laser_scan_matcher/csm/src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to init submodules in: '/home/sudha/catkin_ws/build/scan_tools/laser_scan_matcher/csm/src'")
endif()

execute_process(
  COMMAND "/usr/bin/git" submodule update --recursive
  WORKING_DIRECTORY "/home/sudha/catkin_ws/build/scan_tools/laser_scan_matcher/csm/src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/sudha/catkin_ws/build/scan_tools/laser_scan_matcher/csm/src'")
endif()

