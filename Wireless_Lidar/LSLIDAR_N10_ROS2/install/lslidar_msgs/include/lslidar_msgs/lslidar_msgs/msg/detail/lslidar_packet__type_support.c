// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lslidar_msgs:msg/LslidarPacket.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lslidar_msgs/msg/detail/lslidar_packet__rosidl_typesupport_introspection_c.h"
#include "lslidar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lslidar_msgs/msg/detail/lslidar_packet__functions.h"
#include "lslidar_msgs/msg/detail/lslidar_packet__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lslidar_msgs__msg__LslidarPacket__init(message_memory);
}

void lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_fini_function(void * message_memory)
{
  lslidar_msgs__msg__LslidarPacket__fini(message_memory);
}

size_t lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__size_function__LslidarPacket__data(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2000;
}

const void * lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__get_const_function__LslidarPacket__data(
  const void * untyped_member, size_t index)
{
  const uint8_t * member =
    (const uint8_t *)(untyped_member);
  return &member[index];
}

void * lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__get_function__LslidarPacket__data(
  void * untyped_member, size_t index)
{
  uint8_t * member =
    (uint8_t *)(untyped_member);
  return &member[index];
}

void lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__fetch_function__LslidarPacket__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__get_const_function__LslidarPacket__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__assign_function__LslidarPacket__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__get_function__LslidarPacket__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_member_array[2] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPacket, stamp),  // bytes offset in struct
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
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2000,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarPacket, data),  // bytes offset in struct
    NULL,  // default value
    lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__size_function__LslidarPacket__data,  // size() function pointer
    lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__get_const_function__LslidarPacket__data,  // get_const(index) function pointer
    lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__get_function__LslidarPacket__data,  // get(index) function pointer
    lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__fetch_function__LslidarPacket__data,  // fetch(index, &value) function pointer
    lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__assign_function__LslidarPacket__data,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_members = {
  "lslidar_msgs__msg",  // message namespace
  "LslidarPacket",  // message name
  2,  // number of fields
  sizeof(lslidar_msgs__msg__LslidarPacket),
  lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_member_array,  // message members
  lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_init_function,  // function to initialize message memory (memory has to be allocated)
  lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_type_support_handle = {
  0,
  &lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lslidar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lslidar_msgs, msg, LslidarPacket)() {
  lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_type_support_handle.typesupport_identifier) {
    lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lslidar_msgs__msg__LslidarPacket__rosidl_typesupport_introspection_c__LslidarPacket_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
