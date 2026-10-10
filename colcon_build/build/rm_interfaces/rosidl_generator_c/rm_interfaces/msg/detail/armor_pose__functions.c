// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_interfaces:msg/ArmorPose.idl
// generated code does not contain a copyright notice
#include "rm_interfaces/msg/detail/armor_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `armor`
#include "rm_interfaces/msg/detail/armor__functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
rm_interfaces__msg__ArmorPose__init(rm_interfaces__msg__ArmorPose * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    rm_interfaces__msg__ArmorPose__fini(msg);
    return false;
  }
  // armor
  if (!rm_interfaces__msg__Armor__init(&msg->armor)) {
    rm_interfaces__msg__ArmorPose__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    rm_interfaces__msg__ArmorPose__fini(msg);
    return false;
  }
  // yaw
  return true;
}

void
rm_interfaces__msg__ArmorPose__fini(rm_interfaces__msg__ArmorPose * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // armor
  rm_interfaces__msg__Armor__fini(&msg->armor);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // yaw
}

bool
rm_interfaces__msg__ArmorPose__are_equal(const rm_interfaces__msg__ArmorPose * lhs, const rm_interfaces__msg__ArmorPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // armor
  if (!rm_interfaces__msg__Armor__are_equal(
      &(lhs->armor), &(rhs->armor)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  return true;
}

bool
rm_interfaces__msg__ArmorPose__copy(
  const rm_interfaces__msg__ArmorPose * input,
  rm_interfaces__msg__ArmorPose * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // armor
  if (!rm_interfaces__msg__Armor__copy(
      &(input->armor), &(output->armor)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // yaw
  output->yaw = input->yaw;
  return true;
}

rm_interfaces__msg__ArmorPose *
rm_interfaces__msg__ArmorPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_interfaces__msg__ArmorPose * msg = (rm_interfaces__msg__ArmorPose *)allocator.allocate(sizeof(rm_interfaces__msg__ArmorPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_interfaces__msg__ArmorPose));
  bool success = rm_interfaces__msg__ArmorPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_interfaces__msg__ArmorPose__destroy(rm_interfaces__msg__ArmorPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_interfaces__msg__ArmorPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_interfaces__msg__ArmorPose__Sequence__init(rm_interfaces__msg__ArmorPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_interfaces__msg__ArmorPose * data = NULL;

  if (size) {
    data = (rm_interfaces__msg__ArmorPose *)allocator.zero_allocate(size, sizeof(rm_interfaces__msg__ArmorPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_interfaces__msg__ArmorPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_interfaces__msg__ArmorPose__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rm_interfaces__msg__ArmorPose__Sequence__fini(rm_interfaces__msg__ArmorPose__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rm_interfaces__msg__ArmorPose__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rm_interfaces__msg__ArmorPose__Sequence *
rm_interfaces__msg__ArmorPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_interfaces__msg__ArmorPose__Sequence * array = (rm_interfaces__msg__ArmorPose__Sequence *)allocator.allocate(sizeof(rm_interfaces__msg__ArmorPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_interfaces__msg__ArmorPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_interfaces__msg__ArmorPose__Sequence__destroy(rm_interfaces__msg__ArmorPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_interfaces__msg__ArmorPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_interfaces__msg__ArmorPose__Sequence__are_equal(const rm_interfaces__msg__ArmorPose__Sequence * lhs, const rm_interfaces__msg__ArmorPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_interfaces__msg__ArmorPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_interfaces__msg__ArmorPose__Sequence__copy(
  const rm_interfaces__msg__ArmorPose__Sequence * input,
  rm_interfaces__msg__ArmorPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_interfaces__msg__ArmorPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_interfaces__msg__ArmorPose * data =
      (rm_interfaces__msg__ArmorPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_interfaces__msg__ArmorPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_interfaces__msg__ArmorPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_interfaces__msg__ArmorPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
