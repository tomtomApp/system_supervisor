cmake_minimum_required(VERSION 3.0.2)
project(system_supervisor)

find_package(catkin REQUIRED
    roscpp
    sensor_msgs
    geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES system_supervisor
   CATKIN_DEPENDS roscpp sensor_msgs geometry_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(supervisor src/supervisor.cpp)
target_link_libraries(supervisor ${catkin_LIBRARIES})

add_executable(supervisor_obstacle_avoidance src/supervisor_obstacle_avoidance.cpp)
target_link_libraries(supervisor_obstacle_avoidance ${catkin_LIBRARIES})