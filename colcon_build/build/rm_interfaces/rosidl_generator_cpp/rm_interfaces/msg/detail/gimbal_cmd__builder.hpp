// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_interfaces:msg/GimbalCmd.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_
#define RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_interfaces/msg/detail/gimbal_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_GimbalCmd_distance
{
public:
  explicit Init_GimbalCmd_distance(::rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  ::rm_interfaces::msg::GimbalCmd distance(::rm_interfaces::msg::GimbalCmd::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_pitch_velocity
{
public:
  explicit Init_GimbalCmd_pitch_velocity(::rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_distance pitch_velocity(::rm_interfaces::msg::GimbalCmd::_pitch_velocity_type arg)
  {
    msg_.pitch_velocity = std::move(arg);
    return Init_GimbalCmd_distance(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_yaw_velocity
{
public:
  explicit Init_GimbalCmd_yaw_velocity(::rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_pitch_velocity yaw_velocity(::rm_interfaces::msg::GimbalCmd::_yaw_velocity_type arg)
  {
    msg_.yaw_velocity = std::move(arg);
    return Init_GimbalCmd_pitch_velocity(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_pitch
{
public:
  explicit Init_GimbalCmd_pitch(::rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_yaw_velocity pitch(::rm_interfaces::msg::GimbalCmd::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_GimbalCmd_yaw_velocity(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_yaw
{
public:
  explicit Init_GimbalCmd_yaw(::rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_pitch yaw(::rm_interfaces::msg::GimbalCmd::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_GimbalCmd_pitch(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_fire
{
public:
  explicit Init_GimbalCmd_fire(::rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_yaw fire(::rm_interfaces::msg::GimbalCmd::_fire_type arg)
  {
    msg_.fire = std::move(arg);
    return Init_GimbalCmd_yaw(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_control
{
public:
  explicit Init_GimbalCmd_control(::rm_interfaces::msg::GimbalCmd & msg)
  : msg_(msg)
  {}
  Init_GimbalCmd_fire control(::rm_interfaces::msg::GimbalCmd::_control_type arg)
  {
    msg_.control = std::move(arg);
    return Init_GimbalCmd_fire(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalCmd msg_;
};

class Init_GimbalCmd_header
{
public:
  Init_GimbalCmd_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GimbalCmd_control header(::rm_interfaces::msg::GimbalCmd::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GimbalCmd_control(msg_);
  }

private:
  ::rm_interfaces::msg::GimbalCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_interfaces::msg::GimbalCmd>()
{
  return rm_interfaces::msg::builder::Init_GimbalCmd_header();
}

}  // namespace rm_interfaces

#endif  // RM_INTERFACES__MSG__DETAIL__GIMBAL_CMD__BUILDER_HPP_
