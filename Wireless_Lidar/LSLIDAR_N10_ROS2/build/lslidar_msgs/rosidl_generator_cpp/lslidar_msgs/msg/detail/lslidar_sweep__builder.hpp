// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lslidar_msgs:msg/LslidarSweep.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__BUILDER_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lslidar_msgs/msg/detail/lslidar_sweep__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lslidar_msgs
{

namespace msg
{

namespace builder
{

class Init_LslidarSweep_scans
{
public:
  explicit Init_LslidarSweep_scans(::lslidar_msgs::msg::LslidarSweep & msg)
  : msg_(msg)
  {}
  ::lslidar_msgs::msg::LslidarSweep scans(::lslidar_msgs::msg::LslidarSweep::_scans_type arg)
  {
    msg_.scans = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarSweep msg_;
};

class Init_LslidarSweep_header
{
public:
  Init_LslidarSweep_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LslidarSweep_scans header(::lslidar_msgs::msg::LslidarSweep::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LslidarSweep_scans(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarSweep msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lslidar_msgs::msg::LslidarSweep>()
{
  return lslidar_msgs::msg::builder::Init_LslidarSweep_header();
}

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__BUILDER_HPP_
