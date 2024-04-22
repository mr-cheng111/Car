// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lslidar_msgs:msg/LslidarSweep.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__STRUCT_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'scans'
#include "lslidar_msgs/msg/detail/lslidar_scan__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lslidar_msgs__msg__LslidarSweep __attribute__((deprecated))
#else
# define DEPRECATED__lslidar_msgs__msg__LslidarSweep __declspec(deprecated)
#endif

namespace lslidar_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LslidarSweep_
{
  using Type = LslidarSweep_<ContainerAllocator>;

  explicit LslidarSweep_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->scans.fill(lslidar_msgs::msg::LslidarScan_<ContainerAllocator>{_init});
    }
  }

  explicit LslidarSweep_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    scans(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->scans.fill(lslidar_msgs::msg::LslidarScan_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _scans_type =
    std::array<lslidar_msgs::msg::LslidarScan_<ContainerAllocator>, 16>;
  _scans_type scans;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__scans(
    const std::array<lslidar_msgs::msg::LslidarScan_<ContainerAllocator>, 16> & _arg)
  {
    this->scans = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lslidar_msgs::msg::LslidarSweep_<ContainerAllocator> *;
  using ConstRawPtr =
    const lslidar_msgs::msg::LslidarSweep_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarSweep_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarSweep_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarSweep_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarSweep_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarSweep_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarSweep_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarSweep_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarSweep_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lslidar_msgs__msg__LslidarSweep
    std::shared_ptr<lslidar_msgs::msg::LslidarSweep_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lslidar_msgs__msg__LslidarSweep
    std::shared_ptr<lslidar_msgs::msg::LslidarSweep_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LslidarSweep_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->scans != other.scans) {
      return false;
    }
    return true;
  }
  bool operator!=(const LslidarSweep_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LslidarSweep_

// alias to use template instance with default allocator
using LslidarSweep =
  lslidar_msgs::msg::LslidarSweep_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SWEEP__STRUCT_HPP_
