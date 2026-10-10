// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_interfaces:msg/Armor.idl
// generated code does not contain a copyright notice

#ifndef RM_INTERFACES__MSG__DETAIL__ARMOR__BUILDER_HPP_
#define RM_INTERFACES__MSG__DETAIL__ARMOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_interfaces/msg/detail/armor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_Armor_corners
{
public:
  explicit Init_Armor_corners(::rm_interfaces::msg::Armor & msg)
  : msg_(msg)
  {}
  ::rm_interfaces::msg::Armor corners(::rm_interfaces::msg::Armor::_corners_type arg)
  {
    msg_.corners = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_interfaces::msg::Armor msg_;
};

class Init_Armor_confidence
{
public:
  explicit Init_Armor_confidence(::rm_interfaces::msg::Armor & msg)
  : msg_(msg)
  {}
  Init_Armor_corners confidence(::rm_interfaces::msg::Armor::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_Armor_corners(msg_);
  }

private:
  ::rm_interfaces::msg::Armor msg_;
};

class Init_Armor_number
{
public:
  explicit Init_Armor_number(::rm_interfaces::msg::Armor & msg)
  : msg_(msg)
  {}
  Init_Armor_confidence number(::rm_interfaces::msg::Armor::_number_type arg)
  {
    msg_.number = std::move(arg);
    return Init_Armor_confidence(msg_);
  }

private:
  ::rm_interfaces::msg::Armor msg_;
};

class Init_Armor_type
{
public:
  explicit Init_Armor_type(::rm_interfaces::msg::Armor & msg)
  : msg_(msg)
  {}
  Init_Armor_number type(::rm_interfaces::msg::Armor::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Armor_number(msg_);
  }

private:
  ::rm_interfaces::msg::Armor msg_;
};

class Init_Armor_color
{
public:
  explicit Init_Armor_color(::rm_interfaces::msg::Armor & msg)
  : msg_(msg)
  {}
  Init_Armor_type color(::rm_interfaces::msg::Armor::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_Armor_type(msg_);
  }

private:
  ::rm_interfaces::msg::Armor msg_;
};

class Init_Armor_header
{
public:
  Init_Armor_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Armor_color header(::rm_interfaces::msg::Armor::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Armor_color(msg_);
  }

private:
  ::rm_interfaces::msg::Armor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_interfaces::msg::Armor>()
{
  return rm_interfaces::msg::builder::Init_Armor_header();
}

}  // namespace rm_interfaces

#endif  // RM_INTERFACES__MSG__DETAIL__ARMOR__BUILDER_HPP_
