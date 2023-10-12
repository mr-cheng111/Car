// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice
#include "wireless_lidar/msg/detail/lidar_data__rosidl_typesupport_fastrtps_cpp.hpp"
#include "wireless_lidar/msg/detail/lidar_data__functions.h"
#include "wireless_lidar/msg/detail/lidar_data__struct.hpp"

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
bool cdr_serialize(
  const wireless_lidar::msg::PointData &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  wireless_lidar::msg::PointData &);
size_t get_serialized_size(
  const wireless_lidar::msg::PointData &,
  size_t current_alignment);
size_t
max_serialized_size_PointData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace wireless_lidar


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  cdr << ros_message.header;
  // Member: pkg_length
  cdr << ros_message.pkg_length;
  // Member: rate
  cdr << ros_message.rate;
  // Member: start_angle
  cdr << ros_message.start_angle;
  // Member: data
  {
    for (size_t i = 0; i < 16; i++) {
      wireless_lidar::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.data[i],
        cdr);
    }
  }
  // Member: stop_angle
  cdr << ros_message.stop_angle;
  // Member: sum_data
  cdr << ros_message.sum_data;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  wireless_lidar::msg::LidarData & ros_message)
{
  // Member: header
  cdr >> ros_message.header;

  // Member: pkg_length
  cdr >> ros_message.pkg_length;

  // Member: rate
  cdr >> ros_message.rate;

  // Member: start_angle
  cdr >> ros_message.start_angle;

  // Member: data
  {
    for (size_t i = 0; i < 16; i++) {
      wireless_lidar::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr,
        ros_message.data[i]);
    }
  }

  // Member: stop_angle
  cdr >> ros_message.stop_angle;

  // Member: sum_data
  cdr >> ros_message.sum_data;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
get_serialized_size(
  const wireless_lidar::msg::LidarData & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header
  {
    size_t item_size = sizeof(ros_message.header);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pkg_length
  {
    size_t item_size = sizeof(ros_message.pkg_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rate
  {
    size_t item_size = sizeof(ros_message.rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: start_angle
  {
    size_t item_size = sizeof(ros_message.start_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: data
  {
    size_t array_size = 16;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        wireless_lidar::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.data[index], current_alignment);
    }
  }
  // Member: stop_angle
  {
    size_t item_size = sizeof(ros_message.stop_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sum_data
  {
    size_t item_size = sizeof(ros_message.sum_data);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wireless_lidar
max_serialized_size_LidarData(
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


  // Member: header
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: pkg_length
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: start_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: data
  {
    size_t array_size = 16;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        wireless_lidar::msg::typesupport_fastrtps_cpp::max_serialized_size_PointData(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: stop_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: sum_data
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _LidarData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const wireless_lidar::msg::LidarData *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _LidarData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<wireless_lidar::msg::LidarData *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _LidarData__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const wireless_lidar::msg::LidarData *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _LidarData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_LidarData(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _LidarData__callbacks = {
  "wireless_lidar::msg",
  "LidarData",
  _LidarData__cdr_serialize,
  _LidarData__cdr_deserialize,
  _LidarData__get_serialized_size,
  _LidarData__max_serialized_size
};

static rosidl_message_type_support_t _LidarData__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_LidarData__callbacks,
  get_message_typesupport_handle_function,
  &wireless_lidar__msg__LidarData__get_type_hash,
  &wireless_lidar__msg__LidarData__get_type_description,
  &wireless_lidar__msg__LidarData__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace wireless_lidar

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_wireless_lidar
const rosidl_message_type_support_t *
get_message_type_support_handle<wireless_lidar::msg::LidarData>()
{
  return &wireless_lidar::msg::typesupport_fastrtps_cpp::_LidarData__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wireless_lidar, msg, LidarData)() {
  return &wireless_lidar::msg::typesupport_fastrtps_cpp::_LidarData__handle;
}

#ifdef __cplusplus
}
#endif
