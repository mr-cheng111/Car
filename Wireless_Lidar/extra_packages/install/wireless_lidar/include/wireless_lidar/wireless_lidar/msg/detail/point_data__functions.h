// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__FUNCTIONS_H_
#define WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "wireless_lidar/msg/rosidl_generator_c__visibility_control.h"

#include "wireless_lidar/msg/detail/point_data__struct.h"

/// Initialize msg/PointData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * wireless_lidar__msg__PointData
 * )) before or use
 * wireless_lidar__msg__PointData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
bool
wireless_lidar__msg__PointData__init(wireless_lidar__msg__PointData * msg);

/// Finalize msg/PointData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
void
wireless_lidar__msg__PointData__fini(wireless_lidar__msg__PointData * msg);

/// Create msg/PointData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * wireless_lidar__msg__PointData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
wireless_lidar__msg__PointData *
wireless_lidar__msg__PointData__create();

/// Destroy msg/PointData message.
/**
 * It calls
 * wireless_lidar__msg__PointData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
void
wireless_lidar__msg__PointData__destroy(wireless_lidar__msg__PointData * msg);

/// Check for msg/PointData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
bool
wireless_lidar__msg__PointData__are_equal(const wireless_lidar__msg__PointData * lhs, const wireless_lidar__msg__PointData * rhs);

/// Copy a msg/PointData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
bool
wireless_lidar__msg__PointData__copy(
  const wireless_lidar__msg__PointData * input,
  wireless_lidar__msg__PointData * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
const rosidl_type_hash_t *
wireless_lidar__msg__PointData__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
const rosidl_runtime_c__type_description__TypeDescription *
wireless_lidar__msg__PointData__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
const rosidl_runtime_c__type_description__TypeSource *
wireless_lidar__msg__PointData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
const rosidl_runtime_c__type_description__TypeSource__Sequence *
wireless_lidar__msg__PointData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/PointData messages.
/**
 * It allocates the memory for the number of elements and calls
 * wireless_lidar__msg__PointData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
bool
wireless_lidar__msg__PointData__Sequence__init(wireless_lidar__msg__PointData__Sequence * array, size_t size);

/// Finalize array of msg/PointData messages.
/**
 * It calls
 * wireless_lidar__msg__PointData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
void
wireless_lidar__msg__PointData__Sequence__fini(wireless_lidar__msg__PointData__Sequence * array);

/// Create array of msg/PointData messages.
/**
 * It allocates the memory for the array and calls
 * wireless_lidar__msg__PointData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
wireless_lidar__msg__PointData__Sequence *
wireless_lidar__msg__PointData__Sequence__create(size_t size);

/// Destroy array of msg/PointData messages.
/**
 * It calls
 * wireless_lidar__msg__PointData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
void
wireless_lidar__msg__PointData__Sequence__destroy(wireless_lidar__msg__PointData__Sequence * array);

/// Check for msg/PointData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
bool
wireless_lidar__msg__PointData__Sequence__are_equal(const wireless_lidar__msg__PointData__Sequence * lhs, const wireless_lidar__msg__PointData__Sequence * rhs);

/// Copy an array of msg/PointData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
bool
wireless_lidar__msg__PointData__Sequence__copy(
  const wireless_lidar__msg__PointData__Sequence * input,
  wireless_lidar__msg__PointData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__FUNCTIONS_H_
