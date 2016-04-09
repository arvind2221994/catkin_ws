# generated from genmsg/cmake/pkg-msg-paths.cmake.em

# message include dirs in installspace
_prepend_path("${tf_DIR}/.." "msg" tf_MSG_INCLUDE_DIRS UNIQUE)
set(tf_MSG_DEPENDENCIES geometry_msgs;sensor_msgs;std_msgs)
