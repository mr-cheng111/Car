// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice
#include "wireless_lidar/msg/detail/lidar_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "wireless_lidar/msg/detail/point_data__functions.h"

bool
wireless_lidar__msg__LidarData__init(wireless_lidar__msg__LidarData * msg)
{
  if (!msg) {
    return false;
  }
  // header
  // pkg_length
  // rate
  // start_angle
  // data
  for (size_t i = 0; i < 16; ++i) {
    if (!wireless_lidar__msg__PointData__init(&msg->data[i])) {
      wireless_lidar__msg__LidarData__fini(msg);
      return false;
    }
  }
  // stop_angle
  // sum_data
  // time
  return true;
}

void
wireless_lidar__msg__LidarData__fini(wireless_lidar__msg__LidarData * msg)
{
  if (!msg) {
    return;
  }
  // header
  // pkg_length
  // rate
  // start_angle
  // data
  for (size_t i = 0; i < 16; ++i) {
    wireless_lidar__msg__PointData__fini(&msg->data[i]);
  }
  // stop_angle
  // sum_data
  // time
}

bool
wireless_lidar__msg__LidarData__are_equal(const wireless_lidar__msg__LidarData * lhs, const wireless_lidar__msg__LidarData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (lhs->header != rhs->header) {
    return false;
  }
  // pkg_length
  if (lhs->pkg_length != rhs->pkg_length) {
    return false;
  }
  // rate
  if (lhs->rate != rhs->rate) {
    return false;
  }
  // start_angle
  if (lhs->start_angle != rhs->start_angle) {
    return false;
  }
  // data
  for (size_t i = 0; i < 16; ++i) {
    if (!wireless_lidar__msg__PointData__are_equal(
        &(lhs->data[i]), &(rhs->data[i])))
    {
      return false;
    }
  }
  // stop_angle
  if (lhs->stop_angle != rhs->stop_angle) {
    return false;
  }
  // sum_data
  if (lhs->sum_data != rhs->sum_data) {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  return true;
}

bool
wireless_lidar__msg__LidarData__copy(
  const wireless_lidar__msg__LidarData * input,
  wireless_lidar__msg__LidarData * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  output->header = input->header;
  // pkg_length
  output->pkg_length = input->pkg_length;
  // rate
  output->rate = input->rate;
  // start_angle
  output->start_angle = input->start_angle;
  // data
  for (size_t i = 0; i < 16; ++i) {
    if (!wireless_lidar__msg__PointData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  // stop_angle
  output->stop_angle = input->stop_angle;
  // sum_data
  output->sum_data = input->sum_data;
  // time
  output->time = input->time;
  return true;
}

wireless_lidar__msg__LidarData *
wireless_lidar__msg__LidarData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wireless_lidar__msg__LidarData * msg = (wireless_lidar__msg__LidarData *)allocator.allocate(sizeof(wireless_lidar__msg__LidarData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wireless_lidar__msg__LidarData));
  bool success = wireless_lidar__msg__LidarData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wireless_lidar__msg__LidarData__destroy(wireless_lidar__msg__LidarData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wireless_lidar__msg__LidarData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wireless_lidar__msg__LidarData__Sequence__init(wireless_lidar__msg__LidarData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wireless_lidar__msg__LidarData * data = NULL;

  if (size) {
    data = (wireless_lidar__msg__LidarData *)allocator.zero_allocate(size, sizeof(wireless_lidar__msg__LidarData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wireless_lidar__msg__LidarData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wireless_lidar__msg__LidarData__fini(&data[i - 1]);
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
wireless_lidar__msg__LidarData__Sequence__fini(wireless_lidar__msg__LidarData__Sequence * array)
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
      wireless_lidar__msg__LidarData__fini(&array->data[i]);
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

wireless_lidar__msg__LidarData__Sequence *
wireless_lidar__msg__LidarData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wireless_lidar__msg__LidarData__Sequence * array = (wireless_lidar__msg__LidarData__Sequence *)allocator.allocate(sizeof(wireless_lidar__msg__LidarData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wireless_lidar__msg__LidarData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wireless_lidar__msg__LidarData__Sequence__destroy(wireless_lidar__msg__LidarData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wireless_lidar__msg__LidarData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wireless_lidar__msg__LidarData__Sequence__are_equal(const wireless_lidar__msg__LidarData__Sequence * lhs, const wireless_lidar__msg__LidarData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wireless_lidar__msg__LidarData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wireless_lidar__msg__LidarData__Sequence__copy(
  const wireless_lidar__msg__LidarData__Sequence * input,
  wireless_lidar__msg__LidarData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wireless_lidar__msg__LidarData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wireless_lidar__msg__LidarData * data =
      (wireless_lidar__msg__LidarData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wireless_lidar__msg__LidarData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wireless_lidar__msg__LidarData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wireless_lidar__msg__LidarData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
