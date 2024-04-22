// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lslidar_msgs:msg/LslidarSweep.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lslidar_msgs/msg/detail/lslidar_sweep__rosidl_typesupport_introspection_c.h"
#include "lslidar_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lslidar_msgs/msg/detail/lslidar_sweep__functions.h"
#include "lslidar_msgs/msg/detail/lslidar_sweep__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `scans`
#include "lslidar_msgs/msg/lslidar_scan.h"
// Member `scans`
#include "lslidar_msgs/msg/detail/lslidar_scan__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lslidar_msgs__msg__LslidarSweep__init(message_memory);
}

void lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_fini_function(void * message_memory)
{
  lslidar_msgs__msg__LslidarSweep__fini(message_memory);
}

size_t lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__size_function__LslidarSweep__scans(
  const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__get_const_function__LslidarSweep__scans(
  const void * untyped_member, size_t index)
{
  const lslidar_msgs__msg__LslidarScan * member =
    (const lslidar_msgs__msg__LslidarScan *)(untyped_member);
  return &member[index];
}

void * lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__get_function__LslidarSweep__scans(
  void * untyped_member, size_t index)
{
  lslidar_msgs__msg__LslidarScan * member =
    (lslidar_msgs__msg__LslidarScan *)(untyped_member);
  return &member[index];
}

void lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__fetch_function__LslidarSweep__scans(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lslidar_msgs__msg__LslidarScan * item =
    ((const lslidar_msgs__msg__LslidarScan *)
    lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__get_const_function__LslidarSweep__scans(untyped_member, index));
  lslidar_msgs__msg__LslidarScan * value =
    (lslidar_msgs__msg__LslidarScan *)(untyped_value);
  *value = *item;
}

void lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__assign_function__LslidarSweep__scans(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lslidar_msgs__msg__LslidarScan * item =
    ((lslidar_msgs__msg__LslidarScan *)
    lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__get_function__LslidarSweep__scans(untyped_member, index));
  const lslidar_msgs__msg__LslidarScan * value =
    (const lslidar_msgs__msg__LslidarScan *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarSweep, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scans",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(lslidar_msgs__msg__LslidarSweep, scans),  // bytes offset in struct
    NULL,  // default value
    lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__size_function__LslidarSweep__scans,  // size() function pointer
    lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__get_const_function__LslidarSweep__scans,  // get_const(index) function pointer
    lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__get_function__LslidarSweep__scans,  // get(index) function pointer
    lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__fetch_function__LslidarSweep__scans,  // fetch(index, &value) function pointer
    lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__assign_function__LslidarSweep__scans,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_members = {
  "lslidar_msgs__msg",  // message namespace
  "LslidarSweep",  // message name
  2,  // number of fields
  sizeof(lslidar_msgs__msg__LslidarSweep),
  lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_member_array,  // message members
  lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_init_function,  // function to initialize message memory (memory has to be allocated)
  lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_type_support_handle = {
  0,
  &lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lslidar_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lslidar_msgs, msg, LslidarSweep)() {
  lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lslidar_msgs, msg, LslidarScan)();
  if (!lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_type_support_handle.typesupport_identifier) {
    lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lslidar_msgs__msg__LslidarSweep__rosidl_typesupport_introspection_c__LslidarSweep_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
