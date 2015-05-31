cmake_minimum_required(VERSION 2.8.3)
project(nav)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp move_base angles amcl gmapping)

###################################
## catkin specific configuration ##
###################################

## The catkin_package macro generates cmake config files for your package
catkin_package(
    INCLUDE_DIRS src
    CATKIN_DEPENDS roscpp move_base angles amcl gmapping
    DEPENDS
)

###########
## Build ##
###########

include_directories(
    include src
    ${catkin_INCLUDE_DIRS}
    ${move_base_INCLUDE_DIRS}
    ${angles_INCLUDE_DIRS}
    ${amcl_INCLUDE_DIRS}
    ${gmapping_INCLUDE_DIRS}
)

add_subdirectory(src)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

install(DIRECTORY src/
    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
    FILES_MATCHING PATTERN "*.h"
    PATTERN ".svn" EXCLUDE
)
