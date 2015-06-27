# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "litemsgs: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ilitemsgs:/home/saathvik/catkin_ws/src/litemsgs/msg;-Igeometry_msgs:/opt/ros/hydro/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(litemsgs_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(litemsgs
  "/home/saathvik/catkin_ws/src/litemsgs/msg/lite.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/litemsgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(litemsgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/litemsgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(litemsgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(litemsgs_generate_messages litemsgs_generate_messages_cpp)

# target for backward compatibility
add_custom_target(litemsgs_gencpp)
add_dependencies(litemsgs_gencpp litemsgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS litemsgs_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(litemsgs
  "/home/saathvik/catkin_ws/src/litemsgs/msg/lite.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/litemsgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(litemsgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/litemsgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(litemsgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(litemsgs_generate_messages litemsgs_generate_messages_lisp)

# target for backward compatibility
add_custom_target(litemsgs_genlisp)
add_dependencies(litemsgs_genlisp litemsgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS litemsgs_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(litemsgs
  "/home/saathvik/catkin_ws/src/litemsgs/msg/lite.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/litemsgs
)

### Generating Services

### Generating Module File
_generate_module_py(litemsgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/litemsgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(litemsgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(litemsgs_generate_messages litemsgs_generate_messages_py)

# target for backward compatibility
add_custom_target(litemsgs_genpy)
add_dependencies(litemsgs_genpy litemsgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS litemsgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/litemsgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/litemsgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(litemsgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/litemsgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/litemsgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(litemsgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/litemsgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/litemsgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/litemsgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(litemsgs_generate_messages_py geometry_msgs_generate_messages_py)
