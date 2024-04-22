// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lslidar_msgs:msg/LslidarDifop.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__STRUCT_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lslidar_msgs__msg__LslidarDifop __attribute__((deprecated))
#else
# define DEPRECATED__lslidar_msgs__msg__LslidarDifop __declspec(deprecated)
#endif

namespace lslidar_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LslidarDifop_
{
  using Type = LslidarDifop_<ContainerAllocator>;

  explicit LslidarDifop_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temperature = 0ll;
      this->rpm = 0ll;
    }
  }

  explicit LslidarDifop_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temperature = 0ll;
      this->rpm = 0ll;
    }
  }

  // field types and members
  using _temperature_type =
    int64_t;
  _temperature_type temperature;
  using _rpm_type =
    int64_t;
  _rpm_type rpm;

  // setters for named parameter idiom
  Type & set__temperature(
    const int64_t & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__rpm(
    const int64_t & _arg)
  {
    this->rpm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lslidar_msgs::msg::LslidarDifop_<ContainerAllocator> *;
  using ConstRawPtr =
    const lslidar_msgs::msg::LslidarDifop_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarDifop_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarDifop_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarDifop_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarDifop_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarDifop_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarDifop_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarDifop_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarDifop_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lslidar_msgs__msg__LslidarDifop
    std::shared_ptr<lslidar_msgs::msg::LslidarDifop_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lslidar_msgs__msg__LslidarDifop
    std::shared_ptr<lslidar_msgs::msg::LslidarDifop_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LslidarDifop_ & other) const
  {
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->rpm != other.rpm) {
      return false;
    }
    return true;
  }
  bool operator!=(const LslidarDifop_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LslidarDifop_

// alias to use template instance with default allocator
using LslidarDifop =
  lslidar_msgs::msg::LslidarDifop_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_DIFOP__STRUCT_HPP_
