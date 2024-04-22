// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lslidar_msgs:msg/LslidarDifop.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__BUILDER_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lslidar_msgs/msg/detail/lslidar_difop__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lslidar_msgs
{

namespace msg
{

namespace builder
{

class Init_LslidarDifop_rpm
{
public:
  explicit Init_LslidarDifop_rpm(::lslidar_msgs::msg::LslidarDifop & msg)
  : msg_(msg)
  {}
  ::lslidar_msgs::msg::LslidarDifop rpm(::lslidar_msgs::msg::LslidarDifop::_rpm_type arg)
  {
    msg_.rpm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarDifop msg_;
};

class Init_LslidarDifop_temperature
{
public:
  Init_LslidarDifop_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LslidarDifop_rpm temperature(::lslidar_msgs::msg::LslidarDifop::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_LslidarDifop_rpm(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarDifop msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lslidar_msgs::msg::LslidarDifop>()
{
  return lslidar_msgs::msg::builder::Init_LslidarDifop_temperature();
}

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__BUILDER_HPP_
