// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lslidar_msgs:msg/LslidarScan.idl
// generated code does not contain a copyright notice
#include "lslidar_msgs/msg/detail/lslidar_scan__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `points`
#include "lslidar_msgs/msg/detail/lslidar_point__functions.h"

bool
lslidar_msgs__msg__LslidarScan__init(lslidar_msgs__msg__LslidarScan * msg)
{
  if (!msg) {
    return false;
  }
  // altitude
  // points
  if (!lslidar_msgs__msg__LslidarPoint__Sequence__init(&msg->points, 0)) {
    lslidar_msgs__msg__LslidarScan__fini(msg);
    return false;
  }
  return true;
}

void
lslidar_msgs__msg__LslidarScan__fini(lslidar_msgs__msg__LslidarScan * msg)
{
  if (!msg) {
    return;
  }
  // altitude
  // points
  lslidar_msgs__msg__LslidarPoint__Sequence__fini(&msg->points);
}

bool
lslidar_msgs__msg__LslidarScan__are_equal(const lslidar_msgs__msg__LslidarScan * lhs, const lslidar_msgs__msg__LslidarScan * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  // points
  if (!lslidar_msgs__msg__LslidarPoint__Sequence__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  return true;
}

bool
lslidar_msgs__msg__LslidarScan__copy(
  const lslidar_msgs__msg__LslidarScan * input,
  lslidar_msgs__msg__LslidarScan * output)
{
  if (!input || !output) {
    return false;
  }
  // altitude
  output->altitude = input->altitude;
  // points
  if (!lslidar_msgs__msg__LslidarPoint__Sequence__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  return true;
}

lslidar_msgs__msg__LslidarScan *
lslidar_msgs__msg__LslidarScan__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lslidar_msgs__msg__LslidarScan * msg = (lslidar_msgs__msg__LslidarScan *)allocator.allocate(sizeof(lslidar_msgs__msg__LslidarScan), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lslidar_msgs__msg__LslidarScan));
  bool success = lslidar_msgs__msg__LslidarScan__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lslidar_msgs__msg__LslidarScan__destroy(lslidar_msgs__msg__LslidarScan * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lslidar_msgs__msg__LslidarScan__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lslidar_msgs__msg__LslidarScan__Sequence__init(lslidar_msgs__msg__LslidarScan__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lslidar_msgs__msg__LslidarScan * data = NULL;

  if (size) {
    data = (lslidar_msgs__msg__LslidarScan *)allocator.zero_allocate(size, sizeof(lslidar_msgs__msg__LslidarScan), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lslidar_msgs__msg__LslidarScan__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lslidar_msgs__msg__LslidarScan__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
lslidar_msgs__msg__LslidarScan__Sequence__fini(lslidar_msgs__msg__LslidarScan__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lslidar_msgs__msg__LslidarScan__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

lslidar_msgs__msg__LslidarScan__Sequence *
lslidar_msgs__msg__LslidarScan__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lslidar_msgs__msg__LslidarScan__Sequence * array = (lslidar_msgs__msg__LslidarScan__Sequence *)allocator.allocate(sizeof(lslidar_msgs__msg__LslidarScan__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lslidar_msgs__msg__LslidarScan__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lslidar_msgs__msg__LslidarScan__Sequence__destroy(lslidar_msgs__msg__LslidarScan__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lslidar_msgs__msg__LslidarScan__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lslidar_msgs__msg__LslidarScan__Sequence__are_equal(const lslidar_msgs__msg__LslidarScan__Sequence * lhs, const lslidar_msgs__msg__LslidarScan__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lslidar_msgs__msg__LslidarScan__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lslidar_msgs__msg__LslidarScan__Sequence__copy(
  const lslidar_msgs__msg__LslidarScan__Sequence * input,
  lslidar_msgs__msg__LslidarScan__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lslidar_msgs__msg__LslidarScan);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lslidar_msgs__msg__LslidarScan * data =
      (lslidar_msgs__msg__LslidarScan *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lslidar_msgs__msg__LslidarScan__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lslidar_msgs__msg__LslidarScan__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lslidar_msgs__msg__LslidarScan__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
