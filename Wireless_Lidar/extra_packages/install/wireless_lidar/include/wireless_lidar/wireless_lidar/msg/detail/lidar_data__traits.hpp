// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__TRAITS_HPP_
#define WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "wireless_lidar/msg/detail/lidar_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'data'
#include "wireless_lidar/msg/detail/point_data__traits.hpp"

namespace wireless_lidar
{

namespace msg
{

inline void to_flow_style_yaml(
  const LidarData & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    rosidl_generator_traits::value_to_yaml(msg.header, out);
    out << ", ";
  }

  // member: pkg_length
  {
    out << "pkg_length: ";
    rosidl_generator_traits::value_to_yaml(msg.pkg_length, out);
    out << ", ";
  }

  // member: rate
  {
    out << "rate: ";
    rosidl_generator_traits::value_to_yaml(msg.rate, out);
    out << ", ";
  }

  // member: start_angle
  {
    out << "start_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.start_angle, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: stop_angle
  {
    out << "stop_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_angle, out);
    out << ", ";
  }

  // member: sum_data
  {
    out << "sum_data: ";
    rosidl_generator_traits::value_to_yaml(msg.sum_data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LidarData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header: ";
    rosidl_generator_traits::value_to_yaml(msg.header, out);
    out << "\n";
  }

  // member: pkg_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pkg_length: ";
    rosidl_generator_traits::value_to_yaml(msg.pkg_length, out);
    out << "\n";
  }

  // member: rate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rate: ";
    rosidl_generator_traits::value_to_yaml(msg.rate, out);
    out << "\n";
  }

  // member: start_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.start_angle, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: stop_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stop_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.stop_angle, out);
    out << "\n";
  }

  // member: sum_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sum_data: ";
    rosidl_generator_traits::value_to_yaml(msg.sum_data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LidarData & msg, bool use_flow_style = false)
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
  const wireless_lidar::msg::LidarData & msg,
  std::ostream & out, size_t indentation = 0)
{
  wireless_lidar::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use wireless_lidar::msg::to_yaml() instead")]]
inline std::string to_yaml(const wireless_lidar::msg::LidarData & msg)
{
  return wireless_lidar::msg::to_yaml(msg);
}

template<>
inline const char * data_type<wireless_lidar::msg::LidarData>()
{
  return "wireless_lidar::msg::LidarData";
}

template<>
inline const char * name<wireless_lidar::msg::LidarData>()
{
  return "wireless_lidar/msg/LidarData";
}

template<>
struct has_fixed_size<wireless_lidar::msg::LidarData>
  : std::integral_constant<bool, has_fixed_size<wireless_lidar::msg::PointData>::value> {};

template<>
struct has_bounded_size<wireless_lidar::msg::LidarData>
  : std::integral_constant<bool, has_bounded_size<wireless_lidar::msg::PointData>::value> {};

template<>
struct is_message<wireless_lidar::msg::LidarData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__TRAITS_HPP_
