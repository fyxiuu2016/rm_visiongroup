// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_interfaces:msg/Armor.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__ARMOR__STRUCT_H_
#define RM_INTERFACES__MSG__DETAIL__ARMOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'RED'.
/**
  * ---- 颜色（常量只是给数字起名字，不占数据空间） ----
  * 规定：红色在表里写 0
 */
enum
{
  rm_interfaces__msg__Armor__RED = 0
};

/// Constant 'BLUE'.
/**
  * 蓝色写 1
 */
enum
{
  rm_interfaces__msg__Armor__BLUE = 1
};

/// Constant 'SMALL'.
/**
  * ---- 大小（大板血厚、判定区大，打法不同） ----
  * 小板写 0
 */
enum
{
  rm_interfaces__msg__Armor__SMALL = 0
};

/// Constant 'BIG'.
/**
  * 大板写 1
 */
enum
{
  rm_interfaces__msg__Armor__BIG = 1
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'corners'
#include "geometry_msgs/msg/detail/point32__struct.h"

/// Struct defined in msg/Armor in the package rm_interfaces.
/**
  * ============================================================
  * Armor —— "我看到一块装甲板"（检测节点填，发给解算节点）
  * 只记录照片上的二维信息，此时还不知道它在现实中哪里
  * ============================================================
 */
typedef struct rm_interfaces__msg__Armor
{
  /// 表头：自带时间戳，记录这一帧是什么时候拍的
  std_msgs__msg__Header header;
  /// 这块板的颜色（填 0 或 1）
  uint8_t color;
  /// 大板还是小板
  uint8_t type;
  /// 板子上的数字编号：
  /// 1~5 步兵/英雄，6 哨兵，7 前哨站，8 基地（依训练集定义）
  uint8_t number;
  /// 检测程序有多大把握（0~1，0.9 = 九成把握）
  float confidence;
  /// 板子四个角在照片上的像素位置
  /// [4] = 固定 4 个点，从左上角开始顺时针排列
  geometry_msgs__msg__Point32 corners[4];
} rm_interfaces__msg__Armor;

// Struct for a sequence of rm_interfaces__msg__Armor.
typedef struct rm_interfaces__msg__Armor__Sequence
{
  rm_interfaces__msg__Armor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_interfaces__msg__Armor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_INTERFACES__MSG__DETAIL__ARMOR__STRUCT_H_
