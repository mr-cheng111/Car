// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lslidar_msgs:msg/LslidarPoint.idl
// generated code does not contain a copyright notice
#include "lslidar_msgs/msg/detail/lslidar_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
lslidar_msgs__msg__LslidarPoint__init(lslidar_msgs__msg__LslidarPoint * msg)
{
  if (!msg) {
    return false;
  }
  // time
  // x
  // y
  // z
  // azimuth
  // distance
  // intensity
  return true;
}

void
lslidar_msgs__msg__LslidarPoint__fini(lslidar_msgs__msg__LslidarPoint * msg)
{
  if (!msg) {
    return;
  }
  // time
  // x
  // y
  // z
  // azimuth
  // distance
  // intensity
}

bool
lslidar_msgs__msg__LslidarPoint__are_equal(const lslidar_msgs__msg__LslidarPoint * lhs, const lslidar_msgs__msg__LslidarPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // azimuth
  if (lhs->azimuth != rhs->azimuth) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // intensity
  if (lhs->intensity != rhs->intensity) {
    return false;
  }
  return true;
}

bool
lslidar_msgs__msg__LslidarPoint__copy(
  const lslidar_msgs__msg__LslidarPoint * input,
  lslidar_msgs__msg__LslidarPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // time
  output->time = input->time;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // azimuth
  output->azimuth = input->azimuth;
  // distance
  output->distance = input->distance;
  // intensity
  output->intensity = input->intensity;
  return true;
}

lslidar_msgs__msg__LslidarPoint *
lslidar_msgs__msg__LslidarPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lslidar_msgs__msg__LslidarPoint * msg = (lslidar_msgs__msg__LslidarPoint *)allocator.allocate(sizeof(lslidar_msgs__msg__LslidarPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lslidar_msgs__msg__LslidarPoint));
  bool success = lslidar_msgs__msg__LslidarPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lslidar_msgs__msg__LslidarPoint__destroy(lslidar_msgs__msg__LslidarPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lslidar_msgs__msg__LslidarPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lslidar_msgs__msg__LslidarPoint__Sequence__init(lslidar_msgs__msg__LslidarPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lslidar_msgs__msg__LslidarPoint * data = NULL;

  if (size) {
    data = (lslidar_msgs__msg__LslidarPoint *)allocator.zero_allocate(size, sizeof(lslidar_msgs__msg__LslidarPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lslidar_msgs__msg__LslidarPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lslidar_msgs__msg__LslidarPoint__fini(&data[i - 1]);
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
lslidar_msgs__msg__LslidarPoint__Sequence__fini(lslidar_msgs__msg__LslidarPoint__Sequence * array)
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
      lslidar_msgs__msg__LslidarPoint__fini(&array->data[i]);
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

lslidar_msgs__msg__LslidarPoint__Sequence *
lslidar_msgs__msg__LslidarPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lslidar_msgs__msg__LslidarPoint__Sequence * array = (lslidar_msgs__msg__LslidarPoint__Sequence *)allocator.allocate(sizeof(lslidar_msgs__msg__LslidarPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lslidar_msgs__msg__LslidarPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lslidar_msgs__msg__LslidarPoint__Sequence__destroy(lslidar_msgs__msg__LslidarPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lslidar_msgs__msg__LslidarPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lslidar_msgs__msg__LslidarPoint__Sequence__are_equal(const lslidar_msgs__msg__LslidarPoint__Sequence * lhs, const lslidar_msgs__msg__LslidarPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lslidar_msgs__msg__LslidarPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lslidar_msgs__msg__LslidarPoint__Sequence__copy(
  const lslidar_msgs__msg__LslidarPoint__Sequence * input,
  lslidar_msgs__msg__LslidarPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lslidar_msgs__msg__LslidarPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lslidar_msgs__msg__LslidarPoint * data =
      (lslidar_msgs__msg__LslidarPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lslidar_msgs__msg__LslidarPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lslidar_msgs__msg__LslidarPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lslidar_msgs__msg__LslidarPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
