// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lslidar_msgs:msg/LslidarPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lslidar_msgs/msg/detail/lslidar_point__rosidl_typesupport_introspection_c.h"
#include "lslidar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lslidar_msgs/msg/detail/lslidar_point__functions.h"
#include "lslidar_msgs/msg/detail/lslidar_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lslidar_msgs__msg__LslidarPoint__init(message_memory);
}

void lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_fini_function(void * message_memory)
{
  lslidar_msgs__msg__LslidarPoint__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_message_member_array[7] = {
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPoint, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPoint, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPoint, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPoint, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "azimuth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPoint, azimuth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPoint, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "intensity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPoint, intensity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_message_members = {
  "lslidar_msgs__msg",  // message namespace
  "LslidarPoint",  // message name
  7,  // number of fields
  sizeof(lslidar_msgs__msg__LslidarPoint),
  lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_message_member_array,  // message members
  lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_message_type_support_handle = {
  0,
  &lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lslidar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lslidar_msgs, msg, LslidarPoint)() {
  if (!lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_message_type_support_handle.typesupport_identifier) {
    lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lslidar_msgs__msg__LslidarPoint__rosidl_typesupport_introspection_c__LslidarPoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
