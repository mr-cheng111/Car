// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lslidar_msgs:msg/LslidarDifop.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__STRUCT_H_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LslidarDifop in the package lslidar_msgs.
typedef struct lslidar_msgs__msg__LslidarDifop
{
  int64_t temperature;
  int64_t rpm;
} lslidar_msgs__msg__LslidarDifop;

// Struct for a sequence of lslidar_msgs__msg__LslidarDifop.
typedef struct lslidar_msgs__msg__LslidarDifop__Sequence
{
  lslidar_msgs__msg__LslidarDifop * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lslidar_msgs__msg__LslidarDifop__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__STRUCT_H_
