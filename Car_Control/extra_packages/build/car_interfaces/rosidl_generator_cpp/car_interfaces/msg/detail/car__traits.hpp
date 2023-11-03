// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from car_interfaces:msg/Car.idl
// generated code does not contain a copyright notice

#ifndef CAR_INTERFACES__MSG__DETAIL__CAR__TRAITS_HPP_
#define CAR_INTERFACES__MSG__DETAIL__CAR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "car_interfaces/msg/detail/car__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace car_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Car & msg,
  std::ostream & out)
{
  out << "{";
  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: w
  {
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Car & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "w: ";
    rosidl_generator_traits::value_to_yaml(msg.w, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Car & msg, bool use_flow_style = false)
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

}  // namespace car_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use car_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const car_interfaces::msg::Car & msg,
  std::ostream & out, size_t indentation = 0)
{
  car_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use car_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const car_interfaces::msg::Car & msg)
{
  return car_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<car_interfaces::msg::Car>()
{
  return "car_interfaces::msg::Car";
}

template<>
inline const char * name<car_interfaces::msg::Car>()
{
  return "car_interfaces/msg/Car";
}

template<>
struct has_fixed_size<car_interfaces::msg::Car>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<car_interfaces::msg::Car>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<car_interfaces::msg::Car>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CAR_INTERFACES__MSG__DETAIL__CAR__TRAITS_HPP_
