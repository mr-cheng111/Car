// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "wireless_lidar/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "wireless_lidar/msg/detail/lidar_data__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace wireless_lidar
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
cdr_serialize(
  const wireless_lidar::msg::LidarData & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  wireless_lidar::msg::LidarData & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
get_serialized_size(
  const wireless_lidar::msg::LidarData & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
max_serialized_size_LidarData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace wireless_lidar

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wireless_lidar, msg, LidarData)();

#ifdef __cplusplus
}
#endif

#endif  // WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
