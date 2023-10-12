// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__STRUCT_HPP_
#define WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__wireless_lidar__msg__PointData __attribute__((deprecated))
#else
# define DEPRECATED__wireless_lidar__msg__PointData __declspec(deprecated)
#endif

namespace wireless_lidar
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PointData_
{
  using Type = PointData_<ContainerAllocator>;

  explicit PointData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0;
      this->strength = 0;
    }
  }

  explicit PointData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0;
      this->strength = 0;
    }
  }

  // field types and members
  using _distance_type =
    uint16_t;
  _distance_type distance;
  using _strength_type =
    uint8_t;
  _strength_type strength;

  // setters for named parameter idiom
  Type & set__distance(
    const uint16_t & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__strength(
    const uint8_t & _arg)
  {
    this->strength = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wireless_lidar::msg::PointData_<ContainerAllocator> *;
  using ConstRawPtr =
    const wireless_lidar::msg::PointData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wireless_lidar::msg::PointData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wireless_lidar::msg::PointData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wireless_lidar::msg::PointData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wireless_lidar::msg::PointData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wireless_lidar::msg::PointData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wireless_lidar::msg::PointData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wireless_lidar::msg::PointData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wireless_lidar::msg::PointData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wireless_lidar__msg__PointData
    std::shared_ptr<wireless_lidar::msg::PointData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wireless_lidar__msg__PointData
    std::shared_ptr<wireless_lidar::msg::PointData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PointData_ & other) const
  {
    if (this->distance != other.distance) {
      return false;
    }
    if (this->strength != other.strength) {
      return false;
    }
    return true;
  }
  bool operator!=(const PointData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PointData_

// alias to use template instance with default allocator
using PointData =
  wireless_lidar::msg::PointData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wireless_lidar

#endif  // WIRELESS_LIDAR__MSG__DETAIL__POINT_DATA__STRUCT_HPP_
