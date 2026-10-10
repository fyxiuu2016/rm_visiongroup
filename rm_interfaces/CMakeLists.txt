cmake_minimum_required(VERSION 3.8)
project(rm_interfaces)

find_package(ament_cmake REQUIRED)                # ament 构建体系本体
find_package(std_msgs REQUIRED)                   # 提供 Header
find_package(geometry_msgs REQUIRED)              # 提供 Point32
find_package(rosidl_default_generators REQUIRED)  # 消息"编译器"

# rosidl 生成器把它翻译成 .hpp 和 .so
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Armor.msg"
  "msg/Armors.msg"
  "msg/ArmorPose.msg"
  "msg/ArmorPoses.msg"
  "msg/Target.msg"
  "msg/GimbalCmd.msg"
  "msg/GimbalState.msg"
  DEPENDENCIES std_msgs geometry_msgs
  #DEPENDENCIES把std_msgs、geometry_msgs加入编译，把std_msgs、geometry_msgs两个头文件加入，加入.msg
  #std_msgs消息包 geometry_msgs里面的几何量
)

ament_package()     #结束命令
