// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lslidar_msgs:msg/LslidarDifop.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__TRAITS_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lslidar_msgs/msg/detail/lslidar_difop__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lslidar_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LslidarDifop & msg,
  std::ostream & out)
{
  out << "{";
  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: rpm
  {
    out << "rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.rpm, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LslidarDifop & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.rpm, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LslidarDifop & msg, bool use_flow_style = false)
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
  const lslidar_msgs::msg::LslidarDifop & msg,
  std::ostream & out, size_t indentation = 0)
{
  lslidar_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lslidar_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lslidar_msgs::msg::LslidarDifop & msg)
{
  return lslidar_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lslidar_msgs::msg::LslidarDifop>()
{
  return "lslidar_msgs::msg::LslidarDifop";
}

template<>
inline const char * name<lslidar_msgs::msg::LslidarDifop>()
{
  return "lslidar_msgs/msg/LslidarDifop";
}

template<>
struct has_fixed_size<lslidar_msgs::msg::LslidarDifop>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lslidar_msgs::msg::LslidarDifop>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lslidar_msgs::msg::LslidarDifop>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__TRAITS_HPP_
