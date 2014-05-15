# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "razor_imu_9dof: 1 messages, 0 services")

set(MSG_I_FLAGS "-Irazor_imu_9dof:/home/sudha/catkin_ws/src/razor_imu_9dof-master/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/hydro/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/hydro/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(razor_imu_9dof_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(razor_imu_9dof
  "/home/sudha/catkin_ws/src/razor_imu_9dof-master/msg/RazorImu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/razor_imu_9dof
)

### Generating Services

### Generating Module File
_generate_module_cpp(razor_imu_9dof
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/razor_imu_9dof
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(razor_imu_9dof_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(razor_imu_9dof_generate_messages razor_imu_9dof_generate_messages_cpp)

# target for backward compatibility
add_custom_target(razor_imu_9dof_gencpp)
add_dependencies(razor_imu_9dof_gencpp razor_imu_9dof_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS razor_imu_9dof_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(razor_imu_9dof
  "/home/sudha/catkin_ws/src/razor_imu_9dof-master/msg/RazorImu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/razor_imu_9dof
)

### Generating Services

### Generating Module File
_generate_module_lisp(razor_imu_9dof
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/razor_imu_9dof
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(razor_imu_9dof_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(razor_imu_9dof_generate_messages razor_imu_9dof_generate_messages_lisp)

# target for backward compatibility
add_custom_target(razor_imu_9dof_genlisp)
add_dependencies(razor_imu_9dof_genlisp razor_imu_9dof_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS razor_imu_9dof_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(razor_imu_9dof
  "/home/sudha/catkin_ws/src/razor_imu_9dof-master/msg/RazorImu.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/razor_imu_9dof
)

### Generating Services

### Generating Module File
_generate_module_py(razor_imu_9dof
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/razor_imu_9dof
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(razor_imu_9dof_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(razor_imu_9dof_generate_messages razor_imu_9dof_generate_messages_py)

# target for backward compatibility
add_custom_target(razor_imu_9dof_genpy)
add_dependencies(razor_imu_9dof_genpy razor_imu_9dof_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS razor_imu_9dof_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/razor_imu_9dof)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/razor_imu_9dof
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(razor_imu_9dof_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(razor_imu_9dof_generate_messages_cpp sensor_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/razor_imu_9dof)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/razor_imu_9dof
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(razor_imu_9dof_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(razor_imu_9dof_generate_messages_lisp sensor_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/razor_imu_9dof)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/razor_imu_9dof\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/razor_imu_9dof
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(razor_imu_9dof_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(razor_imu_9dof_generate_messages_py sensor_msgs_generate_messages_py)
