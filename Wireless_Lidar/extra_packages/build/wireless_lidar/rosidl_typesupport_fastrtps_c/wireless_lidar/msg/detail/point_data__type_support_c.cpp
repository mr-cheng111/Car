// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice
#include "wireless_lidar/msg/detail/point_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "wireless_lidar/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "wireless_lidar/msg/detail/point_data__struct.h"
#include "wireless_lidar/msg/detail/point_data__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _PointData__ros_msg_type = wireless_lidar__msg__PointData;

static bool _PointData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PointData__ros_msg_type * ros_message = static_cast<const _PointData__ros_msg_type *>(untyped_ros_message);
  // Field name: distance
  {
    cdr << ros_message->distance;
  }

  // Field name: strength
  {
    cdr << ros_message->strength;
  }

  return true;
}

static bool _PointData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PointData__ros_msg_type * ros_message = static_cast<_PointData__ros_msg_type *>(untyped_ros_message);
  // Field name: distance
  {
    cdr >> ros_message->distance;
  }

  // Field name: strength
  {
    cdr >> ros_message->strength;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wireless_lidar
size_t get_serialized_size_wireless_lidar__msg__PointData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PointData__ros_msg_type * ros_message = static_cast<const _PointData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name distance
  {
    size_t item_size = sizeof(ros_message->distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name strength
  {
    size_t item_size = sizeof(ros_message->strength);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PointData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_wireless_lidar__msg__PointData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wireless_lidar
size_t max_serialized_size_wireless_lidar__msg__PointData(
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

  // member: distance
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: strength
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _PointData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_wireless_lidar__msg__PointData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PointData = {
  "wireless_lidar::msg",
  "PointData",
  _PointData__cdr_serialize,
  _PointData__cdr_deserialize,
  _PointData__get_serialized_size,
  _PointData__max_serialized_size
};

static rosidl_message_type_support_t _PointData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PointData,
  get_message_typesupport_handle_function,
  &wireless_lidar__msg__PointData__get_type_hash,
  &wireless_lidar__msg__PointData__get_type_description,
  &wireless_lidar__msg__PointData__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, wireless_lidar, msg, PointData)() {
  return &_PointData__type_support;
}

#if defined(__cplusplus)
}
#endif
