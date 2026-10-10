// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rm_interfaces:msg/Armor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rm_interfaces/msg/detail/armor__rosidl_typesupport_introspection_c.h"
#include "rm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rm_interfaces/msg/detail/armor__functions.h"
#include "rm_interfaces/msg/detail/armor__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `corners`
#include "geometry_msgs/msg/point32.h"
// Member `corners`
#include "geometry_msgs/msg/detail/point32__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rm_interfaces__msg__Armor__init(message_memory);
}

void rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_fini_function(void * message_memory)
{
  rm_interfaces__msg__Armor__fini(message_memory);
}

size_t rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__size_function__Armor__corners(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_const_function__Armor__corners(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point32 * member =
    (const geometry_msgs__msg__Point32 *)(untyped_member);
  return &member[index];
}

void * rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_function__Armor__corners(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point32 * member =
    (geometry_msgs__msg__Point32 *)(untyped_member);
  return &member[index];
}

void rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__fetch_function__Armor__corners(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point32 * item =
    ((const geometry_msgs__msg__Point32 *)
    rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_const_function__Armor__corners(untyped_member, index));
  geometry_msgs__msg__Point32 * value =
    (geometry_msgs__msg__Point32 *)(untyped_value);
  *value = *item;
}

void rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__assign_function__Armor__corners(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point32 * item =
    ((geometry_msgs__msg__Point32 *)
    rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_function__Armor__corners(untyped_member, index));
  const geometry_msgs__msg__Point32 * value =
    (const geometry_msgs__msg__Point32 *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_interfaces__msg__Armor, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "color",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_interfaces__msg__Armor, color),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_interfaces__msg__Armor, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_interfaces__msg__Armor, number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rm_interfaces__msg__Armor, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "corners",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(rm_interfaces__msg__Armor, corners),  // bytes offset in struct
    NULL,  // default value
    rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__size_function__Armor__corners,  // size() function pointer
    rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_const_function__Armor__corners,  // get_const(index) function pointer
    rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__get_function__Armor__corners,  // get(index) function pointer
    rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__fetch_function__Armor__corners,  // fetch(index, &value) function pointer
    rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__assign_function__Armor__corners,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_members = {
  "rm_interfaces__msg",  // message namespace
  "Armor",  // message name
  6,  // number of fields
  sizeof(rm_interfaces__msg__Armor),
  rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array,  // message members
  rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_init_function,  // function to initialize message memory (memory has to be allocated)
  rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_type_support_handle = {
  0,
  &rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rm_interfaces, msg, Armor)() {
  rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point32)();
  if (!rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_type_support_handle.typesupport_identifier) {
    rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rm_interfaces__msg__Armor__rosidl_typesupport_introspection_c__Armor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
