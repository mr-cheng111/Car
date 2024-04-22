// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lslidar_msgs:msg/LslidarSweep.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__STRUCT_H_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'scans'
#include "lslidar_msgs/msg/detail/lslidar_scan__struct.h"

/// Struct defined in msg/LslidarSweep in the package lslidar_msgs.
typedef struct lslidar_msgs__msg__LslidarSweep
{
  std_msgs__msg__Header header;
  /// The 0th scan is at the bottom
  lslidar_msgs__msg__LslidarScan scans[16];
} lslidar_msgs__msg__LslidarSweep;

// Struct for a sequence of lslidar_msgs__msg__LslidarSweep.
typedef struct lslidar_msgs__msg__LslidarSweep__Sequence
{
  lslidar_msgs__msg__LslidarSweep * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lslidar_msgs__msg__LslidarSweep__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__STRUCT_H_
