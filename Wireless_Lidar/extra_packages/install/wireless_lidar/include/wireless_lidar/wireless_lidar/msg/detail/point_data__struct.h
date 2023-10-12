// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__STRUCT_H_
#define WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/PointData in the package wireless_lidar.
typedef struct wireless_lidar__msg__PointData
{
  uint16_t distance;
  uint8_t strength;
} wireless_lidar__msg__PointData;

// Struct for a sequence of wireless_lidar__msg__PointData.
typedef struct wireless_lidar__msg__PointData__Sequence
{
  wireless_lidar__msg__PointData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wireless_lidar__msg__PointData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__STRUCT_H_
