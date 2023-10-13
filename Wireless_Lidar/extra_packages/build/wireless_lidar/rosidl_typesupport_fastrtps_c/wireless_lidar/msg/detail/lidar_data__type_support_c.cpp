// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice
#include "wireless_lidar/msg/detail/lidar_data__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "wireless_lidar/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "wireless_lidar/msg/detail/lidar_data__struct.h"
#include "wireless_lidar/msg/detail/lidar_data__functions.h"
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

#include "wireless_lidar/msg/detail/point_data__functions.h"  // data

// forward declare type support functions
size_t get_serialized_size_wireless_lidar__msg__PointData(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_wireless_lidar__msg__PointData(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, wireless_lidar, msg, PointData)();


using _LidarData__ros_msg_type = wireless_lidar__msg__LidarData;

static bool _LidarData__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LidarData__ros_msg_type * ros_message = static_cast<const _LidarData__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    cdr << ros_message->header;
  }

  // Field name: pkg_length
  {
    cdr << ros_message->pkg_length;
  }

  // Field name: rate
  {
    cdr << ros_message->rate;
  }

  // Field name: start_angle
  {
    cdr << ros_message->start_angle;
  }

  // Field name: data
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, wireless_lidar, msg, PointData
      )()->data);
    size_t size = 16;
    auto array_ptr = ros_message->data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: stop_angle
  {
    cdr << ros_message->stop_angle;
  }

  // Field name: sum_data
  {
    cdr << ros_message->sum_data;
  }

  // Field name: time
  {
    cdr << ros_message->time;
  }

  return true;
}

static bool _LidarData__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LidarData__ros_msg_type * ros_message = static_cast<_LidarData__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    cdr >> ros_message->header;
  }

  // Field name: pkg_length
  {
    cdr >> ros_message->pkg_length;
  }

  // Field name: rate
  {
    cdr >> ros_message->rate;
  }

  // Field name: start_angle
  {
    cdr >> ros_message->start_angle;
  }

  // Field name: data
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, wireless_lidar, msg, PointData
      )()->data);
    size_t size = 16;
    auto array_ptr = ros_message->data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: stop_angle
  {
    cdr >> ros_message->stop_angle;
  }

  // Field name: sum_data
  {
    cdr >> ros_message->sum_data;
  }

  // Field name: time
  {
    cdr >> ros_message->time;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wireless_lidar
size_t get_serialized_size_wireless_lidar__msg__LidarData(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LidarData__ros_msg_type * ros_message = static_cast<const _LidarData__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header
  {
    size_t item_size = sizeof(ros_message->header);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pkg_length
  {
    size_t item_size = sizeof(ros_message->pkg_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rate
  {
    size_t item_size = sizeof(ros_message->rate);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name start_angle
  {
    size_t item_size = sizeof(ros_message->start_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name data
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->data;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_wireless_lidar__msg__PointData(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name stop_angle
  {
    size_t item_size = sizeof(ros_message->stop_angle);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sum_data
  {
    size_t item_size = sizeof(ros_message->sum_data);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name time
  {
    size_t item_size = sizeof(ros_message->time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LidarData__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_wireless_lidar__msg__LidarData(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_wireless_lidar
size_t max_serialized_size_wireless_lidar__msg__LidarData(
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

  // member: header
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: pkg_length
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rate
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: start_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: data
  {
    size_t array_size = 16;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_wireless_lidar__msg__PointData(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: stop_angle
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: sum_data
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: time
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _LidarData__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_wireless_lidar__msg__LidarData(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LidarData = {
  "wireless_lidar::msg",
  "LidarData",
  _LidarData__cdr_serialize,
  _LidarData__cdr_deserialize,
  _LidarData__get_serialized_size,
  _LidarData__max_serialized_size
};

static rosidl_message_type_support_t _LidarData__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LidarData,
  get_message_typesupport_handle_function,
  &wireless_lidar__msg__LidarData__get_type_hash,
  &wireless_lidar__msg__LidarData__get_type_description,
  &wireless_lidar__msg__LidarData__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, wireless_lidar, msg, LidarData)() {
  return &_LidarData__type_support;
}

#if defined(__cplusplus)
}
#endif
