// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lslidar_msgs:msg/LslidarPoint.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__STRUCT_H_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LslidarPoint in the package lslidar_msgs.
/**
  * Time when the point is captured
 */
typedef struct lslidar_msgs__msg__LslidarPoint
{
  float time;
  /// Converted distance in the sensor frame
  double x;
  double y;
  double z;
  /// Raw measurement from Leishen M10
  double azimuth;
  double distance;
  double intensity;
} lslidar_msgs__msg__LslidarPoint;

// Struct for a sequence of lslidar_msgs__msg__LslidarPoint.
typedef struct lslidar_msgs__msg__LslidarPoint__Sequence
{
  lslidar_msgs__msg__LslidarPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lslidar_msgs__msg__LslidarPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__STRUCT_H_
