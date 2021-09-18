cmake_minimum_required(VERSION 3.0.2)
project(supervisor)

find_package(catkin REQUIRED
    roscpp
    sensor_msgs
    geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES supervisor
   CATKIN_DEPENDS roscpp sensor_msgs geometry_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(supervisor src/supervisor.cpp)
target_link_libraries(supervisor ${catkin_LIBRARIES})