# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "move_base_msgs: 7 messages, 0 services")

set(MSG_I_FLAGS "-Imove_base_msgs:/home/sudha/catkin_ws/devel/share/move_base_msgs/msg;-Iactionlib_msgs:/opt/ros/hydro/share/actionlib_msgs/cmake/../msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/hydro/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(move_base_msgs_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_cpp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_cpp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_cpp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_cpp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionGoal.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_cpp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_cpp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(move_base_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(move_base_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(move_base_msgs_generate_messages move_base_msgs_generate_messages_cpp)

# target for backward compatibility
add_custom_target(move_base_msgs_gencpp)
add_dependencies(move_base_msgs_gencpp move_base_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS move_base_msgs_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_lisp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_lisp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_lisp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_lisp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionGoal.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_lisp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
)
_generate_msg_lisp(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(move_base_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(move_base_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(move_base_msgs_generate_messages move_base_msgs_generate_messages_lisp)

# target for backward compatibility
add_custom_target(move_base_msgs_genlisp)
add_dependencies(move_base_msgs_genlisp move_base_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS move_base_msgs_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
)
_generate_msg_py(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
)
_generate_msg_py(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
)
_generate_msg_py(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
)
_generate_msg_py(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionResult.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseResult.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionGoal.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
)
_generate_msg_py(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
)
_generate_msg_py(move_base_msgs
  "/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/sudha/catkin_ws/devel/share/move_base_msgs/msg/MoveBaseGoal.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(move_base_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(move_base_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(move_base_msgs_generate_messages move_base_msgs_generate_messages_py)

# target for backward compatibility
add_custom_target(move_base_msgs_genpy)
add_dependencies(move_base_msgs_genpy move_base_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS move_base_msgs_generate_messages_py)


debug_message(2 "move_base_msgs: Iflags=${MSG_I_FLAGS}")


if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/move_base_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(move_base_msgs_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
add_dependencies(move_base_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(move_base_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/move_base_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(move_base_msgs_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
add_dependencies(move_base_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(move_base_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/move_base_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(move_base_msgs_generate_messages_py actionlib_msgs_generate_messages_py)
add_dependencies(move_base_msgs_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(move_base_msgs_generate_messages_py geometry_msgs_generate_messages_py)
