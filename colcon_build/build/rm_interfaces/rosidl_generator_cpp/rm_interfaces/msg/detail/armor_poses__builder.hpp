// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_interfaces:msg/ArmorPoses.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__ARMOR_POSES__BUILDER_HPP_
#define RM_INTERFACES__MSG__DETAIL__ARMOR_POSES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_interfaces/msg/detail/armor_poses__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmorPoses_armors
{
public:
  explicit Init_ArmorPoses_armors(::rm_interfaces::msg::ArmorPoses & msg)
  : msg_(msg)
  {}
  ::rm_interfaces::msg::ArmorPoses armors(::rm_interfaces::msg::ArmorPoses::_armors_type arg)
  {
    msg_.armors = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_interfaces::msg::ArmorPoses msg_;
};

class Init_ArmorPoses_header
{
public:
  Init_ArmorPoses_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmorPoses_armors header(::rm_interfaces::msg::ArmorPoses::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ArmorPoses_armors(msg_);
  }

private:
  ::rm_interfaces::msg::ArmorPoses msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_interfaces::msg::ArmorPoses>()
{
  return rm_interfaces::msg::builder::Init_ArmorPoses_header();
}

}  // namespace rm_interfaces

#endif  // RM_INTERFACES__MSG__DETAIL__ARMOR_POSES__BUILDER_HPP_
