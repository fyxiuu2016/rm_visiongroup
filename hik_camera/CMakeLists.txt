cmake_minimum_required(VERSION 3.8)
project(hik_camera)

# 沿用 ROS2 Humble 默认的 C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

# 视频模式源码（始终编译）
set(SOURCES
  src/hik_camera_node.cpp
  src/video_file_source.cpp
)

# 检测海康 MVS SDK：存在才编译 SDK 模式源码并链接其库
set(MVS_DIR /opt/MVS)
if(EXISTS ${MVS_DIR}/include/MvCameraControl.h)
  message(STATUS "检测到 MVS SDK: ${MVS_DIR}，启用 SDK 取图模式")
  list(APPEND SOURCES src/hik_sdk_source.cpp)
  set(MVS_INCLUDE ${MVS_DIR}/include)
  set(MVS_LIB ${MVS_DIR}/lib/64/libMvCameraControl.so)
  add_compile_definitions(HAS_MVS_SDK)   # 代码里用 #ifdef HAS_MVS_SDK 区分
else()
  message(WARNING "未检测到 MVS SDK，仅编译视频文件模式")
endif()

add_executable(hik_camera_node ${SOURCES})

target_include_directories(hik_camera_node PRIVATE
  src
  ${OpenCV_INCLUDE_DIRS}
  ${MVS_INCLUDE}      # SDK 不存在时为空字符串，无副作用
)

target_link_libraries(hik_camera_node
  ${OpenCV_LIBS}
  ${MVS_LIB}
)

ament_target_dependencies(hik_camera_node
  rclcpp
  sensor_msgs
  cv_bridge
)

install(TARGETS hik_camera_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
