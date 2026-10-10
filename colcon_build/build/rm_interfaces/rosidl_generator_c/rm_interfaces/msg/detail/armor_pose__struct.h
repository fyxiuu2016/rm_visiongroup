// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_interfaces:msg/ArmorPose.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__ARMOR_POSE__STRUCT_H_
#define RM_INTERFACES__MSG__DETAIL__ARMOR_POSE__STRUCT_H_

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
// Member 'armor'
#include "rm_interfaces/msg/detail/armor__struct.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/ArmorPose in the package rm_interfaces.
/**
  * ============================================================
  * ArmorPose —— "这块板在现实中哪里"（解算节点填，发给跟踪节点）
  * 解算 = 拿 Armor 的 4 个像素点 + 相机标定参数，
  *        用 PnP 算法算出三维位置和朝向
  * ============================================================
 */
typedef struct rm_interfaces__msg__ArmorPose
{
  std_msgs__msg__Header header;
  /// 把检测那张表原样带过来（颜色/编号/置信度），
  /// 下一个节点不用再回头查
  rm_interfaces__msg__Armor armor;
  /// 板子中心的三维坐标 (x, y, z)，单位米
  /// 例如 (2.1, 0.3, -0.1) = 右前方 2 米多
  geometry_msgs__msg__Point position;
  /// 板子朝向角，单位弧度
  /// 正对我们时接近 0，侧对时较大
  float yaw;
} rm_interfaces__msg__ArmorPose;

// Struct for a sequence of rm_interfaces__msg__ArmorPose.
typedef struct rm_interfaces__msg__ArmorPose__Sequence
{
  rm_interfaces__msg__ArmorPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_interfaces__msg__ArmorPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_INTERFACES__MSG__DETAIL__ARMOR_POSE__STRUCT_H_
