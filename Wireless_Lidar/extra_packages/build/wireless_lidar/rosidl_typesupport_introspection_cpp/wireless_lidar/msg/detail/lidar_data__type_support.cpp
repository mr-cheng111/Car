// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "wireless_lidar/msg/detail/lidar_data__functions.h"
#include "wireless_lidar/msg/detail/lidar_data__struct.hpp"
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

void LidarData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) wireless_lidar::msg::LidarData(_init);
}

void LidarData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<wireless_lidar::msg::LidarData *>(message_memory);
  typed_message->~LidarData();
}

size_t size_function__LidarData__data(const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * get_const_function__LidarData__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<wireless_lidar::msg::PointData, 16> *>(untyped_member);
  return &member[index];
}

void * get_function__LidarData__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<wireless_lidar::msg::PointData, 16> *>(untyped_member);
  return &member[index];
}

void fetch_function__LidarData__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const wireless_lidar::msg::PointData *>(
    get_const_function__LidarData__data(untyped_member, index));
  auto & value = *reinterpret_cast<wireless_lidar::msg::PointData *>(untyped_value);
  value = item;
}

void assign_function__LidarData__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<wireless_lidar::msg::PointData *>(
    get_function__LidarData__data(untyped_member, index));
  const auto & value = *reinterpret_cast<const wireless_lidar::msg::PointData *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember LidarData_message_member_array[7] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::LidarData, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pkg_length",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::LidarData, pkg_length),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "rate",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::LidarData, rate),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "start_angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::LidarData, start_angle),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<wireless_lidar::msg::PointData>(),  // members of sub message
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::LidarData, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__LidarData__data,  // size() function pointer
    get_const_function__LidarData__data,  // get_const(index) function pointer
    get_function__LidarData__data,  // get(index) function pointer
    fetch_function__LidarData__data,  // fetch(index, &value) function pointer
    assign_function__LidarData__data,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stop_angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::LidarData, stop_angle),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "sum_data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wireless_lidar::msg::LidarData, sum_data),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers LidarData_message_members = {
  "wireless_lidar::msg",  // message namespace
  "LidarData",  // message name
  7,  // number of fields
  sizeof(wireless_lidar::msg::LidarData),
  LidarData_message_member_array,  // message members
  LidarData_init_function,  // function to initialize message memory (memory has to be allocated)
  LidarData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t LidarData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &LidarData_message_members,
  get_message_typesupport_handle_function,
  &wireless_lidar__msg__LidarData__get_type_hash,
  &wireless_lidar__msg__LidarData__get_type_description,
  &wireless_lidar__msg__LidarData__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace wireless_lidar


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wireless_lidar::msg::LidarData>()
{
  return &::wireless_lidar::msg::rosidl_typesupport_introspection_cpp::LidarData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wireless_lidar, msg, LidarData)() {
  return &::wireless_lidar::msg::rosidl_typesupport_introspection_cpp::LidarData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
