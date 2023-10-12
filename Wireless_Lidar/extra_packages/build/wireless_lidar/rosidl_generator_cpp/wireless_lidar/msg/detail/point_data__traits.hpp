// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__TRAITS_HPP_
#define WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wireless_lidar/msg/detail/point_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace wireless_lidar
{

namespace msg
{

inline void to_flow_style_yaml(
  const PointData & msg,
  std::ostream & out)
{
  out << "{";
  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: strength
  {
    out << "strength: ";
    rosidl_generator_traits::value_to_yaml(msg.strength, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PointData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: strength
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "strength: ";
    rosidl_generator_traits::value_to_yaml(msg.strength, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PointData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace wireless_lidar

namespace rosidl_generator_traits
{

[[deprecated("use wireless_lidar::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const wireless_lidar::msg::PointData & msg,
  std::ostream & out, size_t indentation = 0)
{
  wireless_lidar::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wireless_lidar::msg::to_yaml() instead")]]
inline std::string to_yaml(const wireless_lidar::msg::PointData & msg)
{
  return wireless_lidar::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wireless_lidar::msg::PointData>()
{
  return "wireless_lidar::msg::PointData";
}

template<>
inline const char * name<wireless_lidar::msg::PointData>()
{
  return "wireless_lidar/msg/PointData";
}

template<>
struct has_fixed_size<wireless_lidar::msg::PointData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<wireless_lidar::msg::PointData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<wireless_lidar::msg::PointData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__TRAITS_HPP_
