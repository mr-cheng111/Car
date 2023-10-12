// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice
#include "wireless_lidar/msg/detail/point_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
wireless_lidar__msg__PointData__init(wireless_lidar__msg__PointData * msg)
{
  if (!msg) {
    return false;
  }
  // distance
  // strength
  return true;
}

void
wireless_lidar__msg__PointData__fini(wireless_lidar__msg__PointData * msg)
{
  if (!msg) {
    return;
  }
  // distance
  // strength
}

bool
wireless_lidar__msg__PointData__are_equal(const wireless_lidar__msg__PointData * lhs, const wireless_lidar__msg__PointData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // strength
  if (lhs->strength != rhs->strength) {
    return false;
  }
  return true;
}

bool
wireless_lidar__msg__PointData__copy(
  const wireless_lidar__msg__PointData * input,
  wireless_lidar__msg__PointData * output)
{
  if (!input || !output) {
    return false;
  }
  // distance
  output->distance = input->distance;
  // strength
  output->strength = input->strength;
  return true;
}

wireless_lidar__msg__PointData *
wireless_lidar__msg__PointData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wireless_lidar__msg__PointData * msg = (wireless_lidar__msg__PointData *)allocator.allocate(sizeof(wireless_lidar__msg__PointData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wireless_lidar__msg__PointData));
  bool success = wireless_lidar__msg__PointData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wireless_lidar__msg__PointData__destroy(wireless_lidar__msg__PointData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wireless_lidar__msg__PointData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wireless_lidar__msg__PointData__Sequence__init(wireless_lidar__msg__PointData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wireless_lidar__msg__PointData * data = NULL;

  if (size) {
    data = (wireless_lidar__msg__PointData *)allocator.zero_allocate(size, sizeof(wireless_lidar__msg__PointData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wireless_lidar__msg__PointData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wireless_lidar__msg__PointData__fini(&data[i - 1]);
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
wireless_lidar__msg__PointData__Sequence__fini(wireless_lidar__msg__PointData__Sequence * array)
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
      wireless_lidar__msg__PointData__fini(&array->data[i]);
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

wireless_lidar__msg__PointData__Sequence *
wireless_lidar__msg__PointData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wireless_lidar__msg__PointData__Sequence * array = (wireless_lidar__msg__PointData__Sequence *)allocator.allocate(sizeof(wireless_lidar__msg__PointData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wireless_lidar__msg__PointData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wireless_lidar__msg__PointData__Sequence__destroy(wireless_lidar__msg__PointData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wireless_lidar__msg__PointData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wireless_lidar__msg__PointData__Sequence__are_equal(const wireless_lidar__msg__PointData__Sequence * lhs, const wireless_lidar__msg__PointData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wireless_lidar__msg__PointData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wireless_lidar__msg__PointData__Sequence__copy(
  const wireless_lidar__msg__PointData__Sequence * input,
  wireless_lidar__msg__PointData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wireless_lidar__msg__PointData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    wireless_lidar__msg__PointData * data =
      (wireless_lidar__msg__PointData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wireless_lidar__msg__PointData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          wireless_lidar__msg__PointData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wireless_lidar__msg__PointData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
