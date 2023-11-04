// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from car_interfaces:msg/Car.idl
// generated code does not contain a copyright notice

#ifndef CAR_INTERFACES__MSG__DETAIL__CAR__STRUCT_H_
#define CAR_INTERFACES__MSG__DETAIL__CAR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Car in the package car_interfaces.
typedef struct car_interfaces__msg__Car
{
  float speed;
  float w;
  float x;
  float y;
} car_interfaces__msg__Car;

// Struct for a sequence of car_interfaces__msg__Car.
typedef struct car_interfaces__msg__Car__Sequence
{
  car_interfaces__msg__Car * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} car_interfaces__msg__Car__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAR_INTERFACES__MSG__DETAIL__CAR__STRUCT_H_
