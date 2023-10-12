// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice
#include "wireless_lidar/msg/detail/point_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "wireless_lidar/msg/detail/point_data__functions.h"
#include "wireless_lidar/msg/detail/point_data__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace wireless_lidar
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
cdr_serialize(
  const wireless_lidar::msg::PointData & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: distance
  cdr << ros_message.distance;
  // Member: strength
  cdr << ros_message.strength;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  wireless_lidar::msg::PointData & ros_message)
{
  // Member: distance
  cdr >> ros_message.distance;

  // Member: strength
  cdr >> ros_message.strength;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
get_serialized_size(
  const wireless_lidar::msg::PointData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: distance
  {
    size_t item_size = sizeof(ros_message.distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: strength
  {
    size_t item_size = sizeof(ros_message.strength);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
max_serialized_size_PointData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: strength
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _PointData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const wireless_lidar::msg::PointData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PointData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<wireless_lidar::msg::PointData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PointData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const wireless_lidar::msg::PointData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PointData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PointData(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PointData__callbacks = {
  "wireless_lidar::msg",
  "PointData",
  _PointData__cdr_serialize,
  _PointData__cdr_deserialize,
  _PointData__get_serialized_size,
  _PointData__max_serialized_size
};

static rosidl_message_type_support_t _PointData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PointData__callbacks,
  get_message_typesupport_handle_function,
  &wireless_lidar__msg__PointData__get_type_hash,
  &wireless_lidar__msg__PointData__get_type_description,
  &wireless_lidar__msg__PointData__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace wireless_lidar

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_wireless_lidar
const rosidl_message_type_support_t *
get_message_type_support_handle<wireless_lidar::msg::PointData>()
{
  return &wireless_lidar::msg::typesupport_fastrtps_cpp::_PointData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wireless_lidar, msg, PointData)() {
  return &wireless_lidar::msg::typesupport_fastrtps_cpp::_PointData__handle;
}

#ifdef __cplusplus
}
#endif
