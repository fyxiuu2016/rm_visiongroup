// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_interfaces:msg/GimbalState.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__GIMBAL_STATE__STRUCT_H_
#define RM_INTERFACES__MSG__DETAIL__GIMBAL_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MODE_IDLE'.
/**
  * ---- 下位机当前模式 ----
  * 空闲：自瞄别干活
 */
enum
{
  rm_interfaces__msg__GimbalState__MODE_IDLE = 0
};

/// Constant 'MODE_AUTO_AIM'.
/**
  * 自瞄模式：操作手开了自瞄，干活
 */
enum
{
  rm_interfaces__msg__GimbalState__MODE_AUTO_AIM = 1
};

/// Constant 'MODE_SMALL_BUFF'.
/**
  * 打小能量机关
 */
enum
{
  rm_interfaces__msg__GimbalState__MODE_SMALL_BUFF = 2
};

/// Constant 'MODE_BIG_BUFF'.
/**
  * 打大能量机关
 */
enum
{
  rm_interfaces__msg__GimbalState__MODE_BIG_BUFF = 3
};

/// Constant 'MODE_OUTPOST'.
/**
  * 打前哨站
 */
enum
{
  rm_interfaces__msg__GimbalState__MODE_OUTPOST = 4
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

/// Struct defined in msg/GimbalState in the package rm_interfaces.
/**
  * ============================================================
  * GimbalState —— "云台现在什么状态"（下位机上报，CAN 节点填）
  * 方向反过来：下位机 -> 视觉
  * 没有这张表，Armor 的像素位置就是死数据——
  * 解算必须知道"拍照那一瞬间相机朝哪"
  * 对应话题：/gimbal/state
  * ============================================================
 */
typedef struct rm_interfaces__msg__GimbalState
{
  std_msgs__msg__Header header;
  /// 云台 IMU 四元数 = 云台当前的姿态
  /// 解算节点用它把像素位置换算成现实位置
  geometry_msgs__msg__Quaternion quaternion;
  /// 当前弹速（米/秒）
  /// 弹速影响子弹下坠，决策节点算弹道补偿要用
  float bullet_speed;
  uint8_t mode;
} rm_interfaces__msg__GimbalState;

// Struct for a sequence of rm_interfaces__msg__GimbalState.
typedef struct rm_interfaces__msg__GimbalState__Sequence
{
  rm_interfaces__msg__GimbalState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_interfaces__msg__GimbalState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_INTERFACES__MSG__DETAIL__GIMBAL_STATE__STRUCT_H_
