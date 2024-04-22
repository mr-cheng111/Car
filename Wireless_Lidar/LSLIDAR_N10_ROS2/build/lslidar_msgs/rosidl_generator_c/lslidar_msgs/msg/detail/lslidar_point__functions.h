// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lslidar_msgs:msg/LslidarPoint.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__FUNCTIONS_H_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lslidar_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "lslidar_msgs/msg/detail/lslidar_point__struct.h"

/// Initialize msg/LslidarPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lslidar_msgs__msg__LslidarPoint
 * )) before or use
 * lslidar_msgs__msg__LslidarPoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
bool
lslidar_msgs__msg__LslidarPoint__init(lslidar_msgs__msg__LslidarPoint * msg);

/// Finalize msg/LslidarPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
void
lslidar_msgs__msg__LslidarPoint__fini(lslidar_msgs__msg__LslidarPoint * msg);

/// Create msg/LslidarPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lslidar_msgs__msg__LslidarPoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
lslidar_msgs__msg__LslidarPoint *
lslidar_msgs__msg__LslidarPoint__create();

/// Destroy msg/LslidarPoint message.
/**
 * It calls
 * lslidar_msgs__msg__LslidarPoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
void
lslidar_msgs__msg__LslidarPoint__destroy(lslidar_msgs__msg__LslidarPoint * msg);

/// Check for msg/LslidarPoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
bool
lslidar_msgs__msg__LslidarPoint__are_equal(const lslidar_msgs__msg__LslidarPoint * lhs, const lslidar_msgs__msg__LslidarPoint * rhs);

/// Copy a msg/LslidarPoint message.
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
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
bool
lslidar_msgs__msg__LslidarPoint__copy(
  const lslidar_msgs__msg__LslidarPoint * input,
  lslidar_msgs__msg__LslidarPoint * output);

/// Initialize array of msg/LslidarPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * lslidar_msgs__msg__LslidarPoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
bool
lslidar_msgs__msg__LslidarPoint__Sequence__init(lslidar_msgs__msg__LslidarPoint__Sequence * array, size_t size);

/// Finalize array of msg/LslidarPoint messages.
/**
 * It calls
 * lslidar_msgs__msg__LslidarPoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
void
lslidar_msgs__msg__LslidarPoint__Sequence__fini(lslidar_msgs__msg__LslidarPoint__Sequence * array);

/// Create array of msg/LslidarPoint messages.
/**
 * It allocates the memory for the array and calls
 * lslidar_msgs__msg__LslidarPoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
lslidar_msgs__msg__LslidarPoint__Sequence *
lslidar_msgs__msg__LslidarPoint__Sequence__create(size_t size);

/// Destroy array of msg/LslidarPoint messages.
/**
 * It calls
 * lslidar_msgs__msg__LslidarPoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
void
lslidar_msgs__msg__LslidarPoint__Sequence__destroy(lslidar_msgs__msg__LslidarPoint__Sequence * array);

/// Check for msg/LslidarPoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
bool
lslidar_msgs__msg__LslidarPoint__Sequence__are_equal(const lslidar_msgs__msg__LslidarPoint__Sequence * lhs, const lslidar_msgs__msg__LslidarPoint__Sequence * rhs);

/// Copy an array of msg/LslidarPoint messages.
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
ROSIDL_GENERATOR_C_PUBLIC_lslidar_msgs
bool
lslidar_msgs__msg__LslidarPoint__Sequence__copy(
  const lslidar_msgs__msg__LslidarPoint__Sequence * input,
  lslidar_msgs__msg__LslidarPoint__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__FUNCTIONS_H_
