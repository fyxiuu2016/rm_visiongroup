// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_
#define RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_

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

/// Struct defined in msg/GimbalCmd in the package rm_interfaces.
/**
  * ============================================================
  * GimbalCmd —— "云台这么转、开不开火"（决策节点填，发给下位机）
  * CAN 节点订阅本消息，打包成 CAN 帧发给 C 板执行
  * 对应话题：/gimbal/cmd
  * ============================================================
 */
typedef struct rm_interfaces__msg__GimbalCmd
{
  std_msgs__msg__Header header;
  /// 自瞄要不要接管云台？
  /// false = 交还给操作手（自瞄没把握时）
  bool control;
  /// 开火吗？true = 打！
  bool fire;
  /// 云台应该转到的水平角（弧度）
  float yaw;
  /// 云台应该转到的俯仰角（弧度）
  float pitch;
  /// 预留：yaw 该转多快（速度前馈，让云台更跟手）
  float yaw_velocity;
  /// 预留：pitch 速度前馈（决策节点后续会填）
  float pitch_velocity;
  /// 目标距离（米），给下位机做弹道参考
  float distance;
} rm_interfaces__msg__GimbalCmd;

// Struct for a sequence of rm_interfaces__msg__GimbalCmd.
typedef struct rm_interfaces__msg__GimbalCmd__Sequence
{
  rm_interfaces__msg__GimbalCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_interfaces__msg__GimbalCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__STRUCT_H_
