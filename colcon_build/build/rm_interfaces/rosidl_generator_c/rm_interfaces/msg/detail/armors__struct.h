// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_interfaces:msg/Armors.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__ARMORS__STRUCT_H_
#define RM_INTERFACES__MSG__DETAIL__ARMORS__STRUCT_H_

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
#include "rm_interfaces/msg/detail/armor__struct.h"

/// Struct defined in msg/Armors in the package rm_interfaces.
/**
  * ============================================================
  * Armors —— "这一帧照片里所有的装甲板"（打包发出）
  * 一帧可能看到 0 块、1 块或好几块，所以用数组
  * 对应话题：/detector/armors
  * ============================================================
 */
typedef struct rm_interfaces__msg__Armors
{
  std_msgs__msg__Header header;
  /// Armor 的数组：[] 表示长度不固定
  rm_interfaces__msg__Armor__Sequence armors;
} rm_interfaces__msg__Armors;

// Struct for a sequence of rm_interfaces__msg__Armors.
typedef struct rm_interfaces__msg__Armors__Sequence
{
  rm_interfaces__msg__Armors * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_interfaces__msg__Armors__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_INTERFACES__MSG__DETAIL__ARMORS__STRUCT_H_
