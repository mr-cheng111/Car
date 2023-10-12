// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "wireless_lidar/msg/detail/point_data__functions.h"
#include "wireless_lidar/msg/detail/point_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace wireless_lidar
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PointData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) wireless_lidar::msg::PointData(_init);
}

void PointData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<wireless_lidar::msg::PointData *>(message_memory);
  typed_message->~PointData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PointData_message_member_array[2] = {
  {
    "distance",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::PointData, distance),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "strength",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::PointData, strength),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PointData_message_members = {
  "wireless_lidar::msg",  // message namespace
  "PointData",  // message name
  2,  // number of fields
  sizeof(wireless_lidar::msg::PointData),
  PointData_message_member_array,  // message members
  PointData_init_function,  // function to initialize message memory (memory has to be allocated)
  PointData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PointData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PointData_message_members,
  get_message_typesupport_handle_function,
  &wireless_lidar__msg__PointData__get_type_hash,
  &wireless_lidar__msg__PointData__get_type_description,
  &wireless_lidar__msg__PointData__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace wireless_lidar


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wireless_lidar::msg::PointData>()
{
  return &::wireless_lidar::msg::rosidl_typesupport_introspection_cpp::PointData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wireless_lidar, msg, PointData)() {
  return &::wireless_lidar::msg::rosidl_typesupport_introspection_cpp::PointData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
