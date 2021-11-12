cmake_minimum_required(VERSION 3.5)
project(autoware_ros_logger)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
find_package(std_msgs REQUIRED)
ament_auto_find_build_dependencies()

include_directories(
  include
)

ament_auto_add_library(autoware_ros_logger SHARED
  src/node.cpp
)

target_link_libraries(autoware_ros_logger)

rclcpp_components_register_node(autoware_ros_logger
  PLUGIN "v2x::AutowareRosLogger"
  EXECUTABLE autoware_ros_logger_node
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
)