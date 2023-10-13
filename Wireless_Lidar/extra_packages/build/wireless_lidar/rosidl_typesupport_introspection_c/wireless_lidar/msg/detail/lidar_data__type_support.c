// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "wireless_lidar/msg/detail/lidar_data__rosidl_typesupport_introspection_c.h"
#include "wireless_lidar/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "wireless_lidar/msg/detail/lidar_data__functions.h"
#include "wireless_lidar/msg/detail/lidar_data__struct.h"


// Include directives for member types
// Member `data`
#include "wireless_lidar/msg/point_data.h"
// Member `data`
#include "wireless_lidar/msg/detail/point_data__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wireless_lidar__msg__LidarData__init(message_memory);
}

void wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_fini_function(void * message_memory)
{
  wireless_lidar__msg__LidarData__fini(message_memory);
}

size_t wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__size_function__LidarData__data(
  const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__get_const_function__LidarData__data(
  const void * untyped_member, size_t index)
{
  const wireless_lidar__msg__PointData * member =
    (const wireless_lidar__msg__PointData *)(untyped_member);
  return &member[index];
}

void * wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__get_function__LidarData__data(
  void * untyped_member, size_t index)
{
  wireless_lidar__msg__PointData * member =
    (wireless_lidar__msg__PointData *)(untyped_member);
  return &member[index];
}

void wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__fetch_function__LidarData__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const wireless_lidar__msg__PointData * item =
    ((const wireless_lidar__msg__PointData *)
    wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__get_const_function__LidarData__data(untyped_member, index));
  wireless_lidar__msg__PointData * value =
    (wireless_lidar__msg__PointData *)(untyped_value);
  *value = *item;
}

void wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__assign_function__LidarData__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  wireless_lidar__msg__PointData * item =
    ((wireless_lidar__msg__PointData *)
    wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__get_function__LidarData__data(untyped_member, index));
  const wireless_lidar__msg__PointData * value =
    (const wireless_lidar__msg__PointData *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__LidarData, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pkg_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__LidarData, pkg_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__LidarData, rate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__LidarData, start_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__LidarData, data),  // bytes offset in struct
    NULL,  // default value
    wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__size_function__LidarData__data,  // size() function pointer
    wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__get_const_function__LidarData__data,  // get_const(index) function pointer
    wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__get_function__LidarData__data,  // get(index) function pointer
    wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__fetch_function__LidarData__data,  // fetch(index, &value) function pointer
    wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__assign_function__LidarData__data,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stop_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__LidarData, stop_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sum_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__LidarData, sum_data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__LidarData, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_members = {
  "wireless_lidar__msg",  // message namespace
  "LidarData",  // message name
  8,  // number of fields
  sizeof(wireless_lidar__msg__LidarData),
  wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_member_array,  // message members
  wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_init_function,  // function to initialize message memory (memory has to be allocated)
  wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_type_support_handle = {
  0,
  &wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_members,
  get_message_typesupport_handle_function,
  &wireless_lidar__msg__LidarData__get_type_hash,
  &wireless_lidar__msg__LidarData__get_type_description,
  &wireless_lidar__msg__LidarData__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wireless_lidar
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wireless_lidar, msg, LidarData)() {
  wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wireless_lidar, msg, PointData)();
  if (!wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_type_support_handle.typesupport_identifier) {
    wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &wireless_lidar__msg__LidarData__rosidl_typesupport_introspection_c__LidarData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
