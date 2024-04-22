// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lslidar_msgs:msg/LslidarPoint.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__TRAITS_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lslidar_msgs/msg/detail/lslidar_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lslidar_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LslidarPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: azimuth
  {
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: intensity
  {
    out << "intensity: ";
    rosidl_generator_traits::value_to_yaml(msg.intensity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LslidarPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: azimuth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: intensity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "intensity: ";
    rosidl_generator_traits::value_to_yaml(msg.intensity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LslidarPoint & msg, bool use_flow_style = false)
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

}  // namespace lslidar_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lslidar_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lslidar_msgs::msg::LslidarPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  lslidar_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lslidar_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lslidar_msgs::msg::LslidarPoint & msg)
{
  return lslidar_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lslidar_msgs::msg::LslidarPoint>()
{
  return "lslidar_msgs::msg::LslidarPoint";
}

template<>
inline const char * name<lslidar_msgs::msg::LslidarPoint>()
{
  return "lslidar_msgs/msg/LslidarPoint";
}

template<>
struct has_fixed_size<lslidar_msgs::msg::LslidarPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lslidar_msgs::msg::LslidarPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lslidar_msgs::msg::LslidarPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__TRAITS_HPP_
