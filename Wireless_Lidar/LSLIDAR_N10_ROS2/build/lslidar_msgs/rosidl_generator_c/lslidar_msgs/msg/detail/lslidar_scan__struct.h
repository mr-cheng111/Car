// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lslidar_msgs:msg/LslidarScan.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__STRUCT_H_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'points'
#include "lslidar_msgs/msg/detail/lslidar_point__struct.h"

/// Struct defined in msg/LslidarScan in the package lslidar_msgs.
/**
  * Altitude of all the points within this scan
 */
typedef struct lslidar_msgs__msg__LslidarScan
{
  double altitude;
  /// The valid points in this scan sorted by azimuth
  /// from 0 to 359.99
  lslidar_msgs__msg__LslidarPoint__Sequence points;
} lslidar_msgs__msg__LslidarScan;

// Struct for a sequence of lslidar_msgs__msg__LslidarScan.
typedef struct lslidar_msgs__msg__LslidarScan__Sequence
{
  lslidar_msgs__msg__LslidarScan * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lslidar_msgs__msg__LslidarScan__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__STRUCT_H_
