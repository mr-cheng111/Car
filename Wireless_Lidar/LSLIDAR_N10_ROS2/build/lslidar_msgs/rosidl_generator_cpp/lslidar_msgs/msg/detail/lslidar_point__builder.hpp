// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lslidar_msgs:msg/LslidarPoint.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__BUILDER_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lslidar_msgs/msg/detail/lslidar_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lslidar_msgs
{

namespace msg
{

namespace builder
{

class Init_LslidarPoint_intensity
{
public:
  explicit Init_LslidarPoint_intensity(::lslidar_msgs::msg::LslidarPoint & msg)
  : msg_(msg)
  {}
  ::lslidar_msgs::msg::LslidarPoint intensity(::lslidar_msgs::msg::LslidarPoint::_intensity_type arg)
  {
    msg_.intensity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPoint msg_;
};

class Init_LslidarPoint_distance
{
public:
  explicit Init_LslidarPoint_distance(::lslidar_msgs::msg::LslidarPoint & msg)
  : msg_(msg)
  {}
  Init_LslidarPoint_intensity distance(::lslidar_msgs::msg::LslidarPoint::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_LslidarPoint_intensity(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPoint msg_;
};

class Init_LslidarPoint_azimuth
{
public:
  explicit Init_LslidarPoint_azimuth(::lslidar_msgs::msg::LslidarPoint & msg)
  : msg_(msg)
  {}
  Init_LslidarPoint_distance azimuth(::lslidar_msgs::msg::LslidarPoint::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_LslidarPoint_distance(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPoint msg_;
};

class Init_LslidarPoint_z
{
public:
  explicit Init_LslidarPoint_z(::lslidar_msgs::msg::LslidarPoint & msg)
  : msg_(msg)
  {}
  Init_LslidarPoint_azimuth z(::lslidar_msgs::msg::LslidarPoint::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_LslidarPoint_azimuth(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPoint msg_;
};

class Init_LslidarPoint_y
{
public:
  explicit Init_LslidarPoint_y(::lslidar_msgs::msg::LslidarPoint & msg)
  : msg_(msg)
  {}
  Init_LslidarPoint_z y(::lslidar_msgs::msg::LslidarPoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_LslidarPoint_z(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPoint msg_;
};

class Init_LslidarPoint_x
{
public:
  explicit Init_LslidarPoint_x(::lslidar_msgs::msg::LslidarPoint & msg)
  : msg_(msg)
  {}
  Init_LslidarPoint_y x(::lslidar_msgs::msg::LslidarPoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_LslidarPoint_y(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPoint msg_;
};

class Init_LslidarPoint_time
{
public:
  Init_LslidarPoint_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LslidarPoint_x time(::lslidar_msgs::msg::LslidarPoint::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_LslidarPoint_x(msg_);
  }

private:
  ::lslidar_msgs::msg::LslidarPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lslidar_msgs::msg::LslidarPoint>()
{
  return lslidar_msgs::msg::builder::Init_LslidarPoint_time();
}

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__BUILDER_HPP_
