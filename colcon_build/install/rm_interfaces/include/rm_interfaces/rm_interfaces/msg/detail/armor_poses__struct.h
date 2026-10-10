// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_interfaces:msg/ArmorPoses.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__ARMOR_POSES__STRUCT_H_
#define RM_INTERFACES__MSG__DETAIL__ARMOR_POSES__STRUCT_H_

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
// Member 'armors'
#include "rm_interfaces/msg/detail/armor_pose__struct.h"

/// Struct defined in msg/ArmorPoses in the package rm_interfaces.
/**
  * ============================================================
  * ArmorPoses —— 一帧中全部解算完的装甲板（打包发出）
  * 对应话题：/solver/armors
  * ============================================================
 */
typedef struct rm_interfaces__msg__ArmorPoses
{
  std_msgs__msg__Header header;
  rm_interfaces__msg__ArmorPose__Sequence armors;
} rm_interfaces__msg__ArmorPoses;

// Struct for a sequence of rm_interfaces__msg__ArmorPoses.
typedef struct rm_interfaces__msg__ArmorPoses__Sequence
{
  rm_interfaces__msg__ArmorPoses * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_interfaces__msg__ArmorPoses__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_INTERFACES__MSG__DETAIL__ARMOR_POSES__STRUCT_H_
