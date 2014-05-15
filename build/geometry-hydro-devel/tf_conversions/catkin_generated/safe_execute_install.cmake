execute_process(COMMAND "/home/sudha/catkin_ws/build/geometry-hydro-devel/tf_conversions/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/sudha/catkin_ws/build/geometry-hydro-devel/tf_conversions/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
