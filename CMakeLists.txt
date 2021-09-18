cmake_minimum_required(VERSION 3.0.2)
project(supervisor)

find_package(catkin REQUIRED
    roscpp
    sensor_msgs
    geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES obstacle_avoidance
   CATKIN_DEPENDS roscpp sensor_msgs geometry_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)