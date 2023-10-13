// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__BUILDER_HPP_
#define WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wireless_lidar/msg/detail/lidar_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wireless_lidar
{

namespace msg
{

namespace builder
{

class Init_LidarData_time
{
public:
  explicit Init_LidarData_time(::wireless_lidar::msg::LidarData & msg)
  : msg_(msg)
  {}
  ::wireless_lidar::msg::LidarData time(::wireless_lidar::msg::LidarData::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wireless_lidar::msg::LidarData msg_;
};

class Init_LidarData_sum_data
{
public:
  explicit Init_LidarData_sum_data(::wireless_lidar::msg::LidarData & msg)
  : msg_(msg)
  {}
  Init_LidarData_time sum_data(::wireless_lidar::msg::LidarData::_sum_data_type arg)
  {
    msg_.sum_data = std::move(arg);
    return Init_LidarData_time(msg_);
  }

private:
  ::wireless_lidar::msg::LidarData msg_;
};

class Init_LidarData_stop_angle
{
public:
  explicit Init_LidarData_stop_angle(::wireless_lidar::msg::LidarData & msg)
  : msg_(msg)
  {}
  Init_LidarData_sum_data stop_angle(::wireless_lidar::msg::LidarData::_stop_angle_type arg)
  {
    msg_.stop_angle = std::move(arg);
    return Init_LidarData_sum_data(msg_);
  }

private:
  ::wireless_lidar::msg::LidarData msg_;
};

class Init_LidarData_data
{
public:
  explicit Init_LidarData_data(::wireless_lidar::msg::LidarData & msg)
  : msg_(msg)
  {}
  Init_LidarData_stop_angle data(::wireless_lidar::msg::LidarData::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_LidarData_stop_angle(msg_);
  }

private:
  ::wireless_lidar::msg::LidarData msg_;
};

class Init_LidarData_start_angle
{
public:
  explicit Init_LidarData_start_angle(::wireless_lidar::msg::LidarData & msg)
  : msg_(msg)
  {}
  Init_LidarData_data start_angle(::wireless_lidar::msg::LidarData::_start_angle_type arg)
  {
    msg_.start_angle = std::move(arg);
    return Init_LidarData_data(msg_);
  }

private:
  ::wireless_lidar::msg::LidarData msg_;
};

class Init_LidarData_rate
{
public:
  explicit Init_LidarData_rate(::wireless_lidar::msg::LidarData & msg)
  : msg_(msg)
  {}
  Init_LidarData_start_angle rate(::wireless_lidar::msg::LidarData::_rate_type arg)
  {
    msg_.rate = std::move(arg);
    return Init_LidarData_start_angle(msg_);
  }

private:
  ::wireless_lidar::msg::LidarData msg_;
};

class Init_LidarData_pkg_length
{
public:
  explicit Init_LidarData_pkg_length(::wireless_lidar::msg::LidarData & msg)
  : msg_(msg)
  {}
  Init_LidarData_rate pkg_length(::wireless_lidar::msg::LidarData::_pkg_length_type arg)
  {
    msg_.pkg_length = std::move(arg);
    return Init_LidarData_rate(msg_);
  }

private:
  ::wireless_lidar::msg::LidarData msg_;
};

class Init_LidarData_header
{
public:
  Init_LidarData_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LidarData_pkg_length header(::wireless_lidar::msg::LidarData::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LidarData_pkg_length(msg_);
  }

private:
  ::wireless_lidar::msg::LidarData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wireless_lidar::msg::LidarData>()
{
  return wireless_lidar::msg::builder::Init_LidarData_header();
}

}  // namespace wireless_lidar

#endif  // WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__BUILDER_HPP_
