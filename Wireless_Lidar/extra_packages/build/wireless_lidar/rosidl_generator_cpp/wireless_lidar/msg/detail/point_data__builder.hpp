// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__BUILDER_HPP_
#define WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "wireless_lidar/msg/detail/point_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace wireless_lidar
{

namespace msg
{

namespace builder
{

class Init_PointData_strength
{
public:
  explicit Init_PointData_strength(::wireless_lidar::msg::PointData & msg)
  : msg_(msg)
  {}
  ::wireless_lidar::msg::PointData strength(::wireless_lidar::msg::PointData::_strength_type arg)
  {
    msg_.strength = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wireless_lidar::msg::PointData msg_;
};

class Init_PointData_distance
{
public:
  Init_PointData_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointData_strength distance(::wireless_lidar::msg::PointData::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_PointData_strength(msg_);
  }

private:
  ::wireless_lidar::msg::PointData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wireless_lidar::msg::PointData>()
{
  return wireless_lidar::msg::builder::Init_PointData_distance();
}

}  // namespace wireless_lidar

#endif  // WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__BUILDER_HPP_
