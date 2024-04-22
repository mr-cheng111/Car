// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lslidar_msgs:msg/LslidarScan.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__STRUCT_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'points'
#include "lslidar_msgs/msg/detail/lslidar_point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lslidar_msgs__msg__LslidarScan __attribute__((deprecated))
#else
# define DEPRECATED__lslidar_msgs__msg__LslidarScan __declspec(deprecated)
#endif

namespace lslidar_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LslidarScan_
{
  using Type = LslidarScan_<ContainerAllocator>;

  explicit LslidarScan_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->altitude = 0.0;
    }
  }

  explicit LslidarScan_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->altitude = 0.0;
    }
  }

  // field types and members
  using _altitude_type =
    double;
  _altitude_type altitude;
  using _points_type =
    std::vector<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>>>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__altitude(
    const double & _arg)
  {
    this->altitude = _arg;
    return *this;
  }
  Type & set__points(
    const std::vector<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>>> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lslidar_msgs::msg::LslidarScan_<ContainerAllocator> *;
  using ConstRawPtr =
    const lslidar_msgs::msg::LslidarScan_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarScan_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarScan_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarScan_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarScan_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarScan_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarScan_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarScan_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarScan_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lslidar_msgs__msg__LslidarScan
    std::shared_ptr<lslidar_msgs::msg::LslidarScan_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lslidar_msgs__msg__LslidarScan
    std::shared_ptr<lslidar_msgs::msg::LslidarScan_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LslidarScan_ & other) const
  {
    if (this->altitude != other.altitude) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const LslidarScan_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LslidarScan_

// alias to use template instance with default allocator
using LslidarScan =
  lslidar_msgs::msg::LslidarScan_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_SCAN__STRUCT_HPP_
