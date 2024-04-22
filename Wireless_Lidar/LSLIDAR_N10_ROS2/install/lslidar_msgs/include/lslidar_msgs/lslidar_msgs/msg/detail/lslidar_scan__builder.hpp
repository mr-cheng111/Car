// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lslidar_msgs:msg/LslidarScan.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__BUILDER_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lslidar_msgs/msg/detail/lslidar_scan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lslidar_msgs
{

namespace msg
{

namespace builder
{

class Init_LslidarScan_points
{
public:
  explicit Init_LslidarScan_points(::lslidar_msgs::msg::LslidarScan & msg)
  : msg_(msg)
  {}
  ::lslidar_msgs::msg::LslidarScan points(::lslidar_msgs::msg::LslidarScan::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarScan msg_;
};

class Init_LslidarScan_altitude
{
public:
  Init_LslidarScan_altitude()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LslidarScan_points altitude(::lslidar_msgs::msg::LslidarScan::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_LslidarScan_points(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarScan msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lslidar_msgs::msg::LslidarScan>()
{
  return lslidar_msgs::msg::builder::Init_LslidarScan_altitude();
}

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__BUILDER_HPP_
