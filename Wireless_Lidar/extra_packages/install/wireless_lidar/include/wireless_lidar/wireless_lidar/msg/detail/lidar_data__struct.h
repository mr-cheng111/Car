// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__STRUCT_H_
#define WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "wireless_lidar/msg/detail/point_data__struct.h"

/// Struct defined in msg/LidarData in the package wireless_lidar.
typedef struct wireless_lidar__msg__LidarData
{
  uint16_t header;
  uint8_t pkg_length;
  uint16_t rate;
  uint16_t start_angle;
  wireless_lidar__msg__PointData data[16];
  uint16_t stop_angle;
  uint8_t sum_data;
  uint32_t time;
} wireless_lidar__msg__LidarData;

// Struct for a sequence of wireless_lidar__msg__LidarData.
typedef struct wireless_lidar__msg__LidarData__Sequence
{
  wireless_lidar__msg__LidarData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wireless_lidar__msg__LidarData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__STRUCT_H_
