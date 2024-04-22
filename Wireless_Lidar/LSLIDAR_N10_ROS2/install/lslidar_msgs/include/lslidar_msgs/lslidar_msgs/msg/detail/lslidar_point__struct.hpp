// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lslidar_msgs:msg/LslidarPoint.idl
// generated code does not contain a copyright notice

#ifndef LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__STRUCT_HPP_
#define LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lslidar_msgs__msg__LslidarPoint __attribute__((deprecated))
#else
# define DEPRECATED__lslidar_msgs__msg__LslidarPoint __declspec(deprecated)
#endif

namespace lslidar_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LslidarPoint_
{
  using Type = LslidarPoint_<ContainerAllocator>;

  explicit LslidarPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0f;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->azimuth = 0.0;
      this->distance = 0.0;
      this->intensity = 0.0;
    }
  }

  explicit LslidarPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0f;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->azimuth = 0.0;
      this->distance = 0.0;
      this->intensity = 0.0;
    }
  }

  // field types and members
  using _time_type =
    float;
  _time_type time;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _azimuth_type =
    double;
  _azimuth_type azimuth;
  using _distance_type =
    double;
  _distance_type distance;
  using _intensity_type =
    double;
  _intensity_type intensity;

  // setters for named parameter idiom
  Type & set__time(
    const float & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__azimuth(
    const double & _arg)
  {
    this->azimuth = _arg;
    return *this;
  }
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__intensity(
    const double & _arg)
  {
    this->intensity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lslidar_msgs::msg::LslidarPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const lslidar_msgs::msg::LslidarPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lslidar_msgs__msg__LslidarPoint
    std::shared_ptr<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lslidar_msgs__msg__LslidarPoint
    std::shared_ptr<lslidar_msgs::msg::LslidarPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LslidarPoint_ & other) const
  {
    if (this->time != other.time) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->azimuth != other.azimuth) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->intensity != other.intensity) {
      return false;
    }
    return true;
  }
  bool operator!=(const LslidarPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LslidarPoint_

// alias to use template instance with default allocator
using LslidarPoint =
  lslidar_msgs::msg::LslidarPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lslidar_msgs

#endif  // LSLIDAR_MSGS__MSG__DETAIL__LSLIDAR_POINT__STRUCT_HPP_
