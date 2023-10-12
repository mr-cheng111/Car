// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "wireless_lidar/msg/detail/point_data__rosidl_typesupport_introspection_c.h"
#include "wireless_lidar/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "wireless_lidar/msg/detail/point_data__functions.h"
#include "wireless_lidar/msg/detail/point_data__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wireless_lidar__msg__PointData__init(message_memory);
}

void wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_fini_function(void * message_memory)
{
  wireless_lidar__msg__PointData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_message_member_array[2] = {
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__PointData, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "strength",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar__msg__PointData, strength),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_message_members = {
  "wireless_lidar__msg",  // message namespace
  "PointData",  // message name
  2,  // number of fields
  sizeof(wireless_lidar__msg__PointData),
  wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_message_member_array,  // message members
  wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_init_function,  // function to initialize message memory (memory has to be allocated)
  wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_message_type_support_handle = {
  0,
  &wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_message_members,
  get_message_typesupport_handle_function,
  &wireless_lidar__msg__PointData__get_type_hash,
  &wireless_lidar__msg__PointData__get_type_description,
  &wireless_lidar__msg__PointData__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wireless_lidar
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wireless_lidar, msg, PointData)() {
  if (!wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_message_type_support_handle.typesupport_identifier) {
    wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &wireless_lidar__msg__PointData__rosidl_typesupport_introspection_c__PointData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
