// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lslidar_msgs:msg/LslidarPacket.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__STRUCT_H_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/LslidarPacket in the package lslidar_msgs.
/**
  * Raw Leishen LIDAR packet.
 */
typedef struct lslidar_msgs__msg__LslidarPacket
{
  /// packet timestamp
  builtin_interfaces__msg__Time stamp;
  /// packet contents
  uint8_t data[2000];
} lslidar_msgs__msg__LslidarPacket;

// Struct for a sequence of lslidar_msgs__msg__LslidarPacket.
typedef struct lslidar_msgs__msg__LslidarPacket__Sequence
{
  lslidar_msgs__msg__LslidarPacket * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lslidar_msgs__msg__LslidarPacket__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__STRUCT_H_
