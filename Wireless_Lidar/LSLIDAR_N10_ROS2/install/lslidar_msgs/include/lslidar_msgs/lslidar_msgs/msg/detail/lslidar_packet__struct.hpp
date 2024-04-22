// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lslidar_msgs:msg/LslidarPacket.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__STRUCT_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lslidar_msgs__msg__LslidarPacket __attribute__((deprecated))
#else
# define DEPRECATED__lslidar_msgs__msg__LslidarPacket __declspec(deprecated)
#endif

namespace lslidar_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LslidarPacket_
{
  using Type = LslidarPacket_<ContainerAllocator>;

  explicit LslidarPacket_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 2000>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
    }
  }

  explicit LslidarPacket_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 2000>::iterator, uint8_t>(this->data.begin(), this->data.end(), 0);
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _data_type =
    std::array<uint8_t, 2000>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__data(
    const std::array<uint8_t, 2000> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lslidar_msgs::msg::LslidarPacket_<ContainerAllocator> *;
  using ConstRawPtr =
    const lslidar_msgs::msg::LslidarPacket_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarPacket_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarPacket_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarPacket_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarPacket_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarPacket_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarPacket_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarPacket_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarPacket_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lslidar_msgs__msg__LslidarPacket
    std::shared_ptr<lslidar_msgs::msg::LslidarPacket_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lslidar_msgs__msg__LslidarPacket
    std::shared_ptr<lslidar_msgs::msg::LslidarPacket_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LslidarPacket_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const LslidarPacket_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LslidarPacket_

// alias to use template instance with default allocator
using LslidarPacket =
  lslidar_msgs::msg::LslidarPacket_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_PACKET__STRUCT_HPP_
