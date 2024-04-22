// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lslidar_msgs:msg/LslidarPacket.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__BUILDER_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lslidar_msgs/msg/detail/lslidar_packet__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lslidar_msgs
{

namespace msg
{

namespace builder
{

class Init_LslidarPacket_data
{
public:
  explicit Init_LslidarPacket_data(::lslidar_msgs::msg::LslidarPacket & msg)
  : msg_(msg)
  {}
  ::lslidar_msgs::msg::LslidarPacket data(::lslidar_msgs::msg::LslidarPacket::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPacket msg_;
};

class Init_LslidarPacket_stamp
{
public:
  Init_LslidarPacket_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LslidarPacket_data stamp(::lslidar_msgs::msg::LslidarPacket::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_LslidarPacket_data(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPacket msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lslidar_msgs::msg::LslidarPacket>()
{
  return lslidar_msgs::msg::builder::Init_LslidarPacket_stamp();
}

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__BUILDER_HPP_
