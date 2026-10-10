// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_interfaces:msg/ArmorPose.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__ARMOR_POSE__BUILDER_HPP_
#define RM_INTERFACES__MSG__DETAIL__ARMOR_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_interfaces/msg/detail/armor_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmorPose_yaw
{
public:
  explicit Init_ArmorPose_yaw(::rm_interfaces::msg::ArmorPose & msg)
  : msg_(msg)
  {}
  ::rm_interfaces::msg::ArmorPose yaw(::rm_interfaces::msg::ArmorPose::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_interfaces::msg::ArmorPose msg_;
};

class Init_ArmorPose_position
{
public:
  explicit Init_ArmorPose_position(::rm_interfaces::msg::ArmorPose & msg)
  : msg_(msg)
  {}
  Init_ArmorPose_yaw position(::rm_interfaces::msg::ArmorPose::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_ArmorPose_yaw(msg_);
  }

private:
  ::rm_interfaces::msg::ArmorPose msg_;
};

class Init_ArmorPose_armor
{
public:
  explicit Init_ArmorPose_armor(::rm_interfaces::msg::ArmorPose & msg)
  : msg_(msg)
  {}
  Init_ArmorPose_position armor(::rm_interfaces::msg::ArmorPose::_armor_type arg)
  {
    msg_.armor = std::move(arg);
    return Init_ArmorPose_position(msg_);
  }

private:
  ::rm_interfaces::msg::ArmorPose msg_;
};

class Init_ArmorPose_header
{
public:
  Init_ArmorPose_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmorPose_armor header(::rm_interfaces::msg::ArmorPose::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ArmorPose_armor(msg_);
  }

private:
  ::rm_interfaces::msg::ArmorPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_interfaces::msg::ArmorPose>()
{
  return rm_interfaces::msg::builder::Init_ArmorPose_header();
}

}  // namespace rm_interfaces

#endif  // RM_INTERFACES__MSG__DETAIL__ARMOR_POSE__BUILDER_HPP_
