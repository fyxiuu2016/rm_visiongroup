// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_interfaces:msg/GimbalState.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__GIMBAL_STATE__BUILDER_HPP_
#define RM_INTERFACES__MSG__DETAIL__GIMBAL_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_interfaces/msg/detail/gimbal_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_GimbalState_mode
{
public:
  explicit Init_GimbalState_mode(::rm_interfaces::msg::GimbalState & msg)
  : msg_(msg)
  {}
  ::rm_interfaces::msg::GimbalState mode(::rm_interfaces::msg::GimbalState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalState msg_;
};

class Init_GimbalState_bullet_speed
{
public:
  explicit Init_GimbalState_bullet_speed(::rm_interfaces::msg::GimbalState & msg)
  : msg_(msg)
  {}
  Init_GimbalState_mode bullet_speed(::rm_interfaces::msg::GimbalState::_bullet_speed_type arg)
  {
    msg_.bullet_speed = std::move(arg);
    return Init_GimbalState_mode(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalState msg_;
};

class Init_GimbalState_quaternion
{
public:
  explicit Init_GimbalState_quaternion(::rm_interfaces::msg::GimbalState & msg)
  : msg_(msg)
  {}
  Init_GimbalState_bullet_speed quaternion(::rm_interfaces::msg::GimbalState::_quaternion_type arg)
  {
    msg_.quaternion = std::move(arg);
    return Init_GimbalState_bullet_speed(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalState msg_;
};

class Init_GimbalState_header
{
public:
  Init_GimbalState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimbalState_quaternion header(::rm_interfaces::msg::GimbalState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GimbalState_quaternion(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_interfaces::msg::GimbalState>()
{
  return rm_interfaces::msg::builder::Init_GimbalState_header();
}

}  // namespace rm_interfaces

#endif  // RM_INTERFACES__MSG__DETAIL__GIMBAL_STATE__BUILDER_HPP_
