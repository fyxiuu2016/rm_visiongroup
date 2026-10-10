// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_
#define RM_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/Target in the package rm_interfaces.
/**
  * ============================================================
  * Target —— "敌车整车在哪、怎么动"（跟踪节点填，发给决策节点）
  * 跟踪节点连续观察很多帧，用 EKF（卡尔曼滤波）估计整车运动状态
  * 有了这些量，决策节点才能预测"0.1 秒后装甲板转到哪"
  * 对应话题：/tracker/target
  * ============================================================
 */
typedef struct rm_interfaces__msg__Target
{
  std_msgs__msg__Header header;
  /// 还锁定着目标吗？false = 跟丢了，决策节点应停火停控
  bool tracking;
  /// 跟踪的是几号车（敌车可能有多辆，要锁定一辆打）
  uint8_t number;
  /// 这辆车身上有几块板：
  /// 普通车 4 块，平衡步兵 2 块，前哨站 3 块
  /// 知道数量才能算出"下一块板什么时候转过来"
  uint8_t armor_num;
  /// 整车旋转中心的位置（注意：不是某块板，是车中心）
  geometry_msgs__msg__Point position;
  /// 车往哪跑、多快（x/y/z 三个方向的速度）
  geometry_msgs__msg__Vector3 velocity;
  /// 车现在转到哪个角度（弧度）
  float yaw;
  /// 车的旋转角速度（弧度/秒）
  /// 小陀螺的关键：这个值大 = 转得欢
  float yaw_velocity;
  /// 第 1 组装甲板到旋转中心的距离（米）
  float radius_1;
  /// 第 2 组（相邻两块板的半径可能不一样）
  float radius_2;
  /// 两组板之间的高度差（有的车板子一高一低）
  float dz;
} rm_interfaces__msg__Target;

// Struct for a sequence of rm_interfaces__msg__Target.
typedef struct rm_interfaces__msg__Target__Sequence
{
  rm_interfaces__msg__Target * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_interfaces__msg__Target__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_
