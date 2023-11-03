// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from car_interfaces:msg/Car.idl
// generated code does not contain a copyright notice

#ifndef CAR_INTERFACES__MSG__DETAIL__CAR__STRUCT_HPP_
#define CAR_INTERFACES__MSG__DETAIL__CAR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__car_interfaces__msg__Car __attribute__((deprecated))
#else
# define DEPRECATED__car_interfaces__msg__Car __declspec(deprecated)
#endif

namespace car_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Car_
{
  using Type = Car_<ContainerAllocator>;

  explicit Car_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0f;
      this->w = 0.0f;
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  explicit Car_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed = 0.0f;
      this->w = 0.0f;
      this->x = 0.0f;
      this->y = 0.0f;
    }
  }

  // field types and members
  using _speed_type =
    float;
  _speed_type speed;
  using _w_type =
    float;
  _w_type w;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;

  // setters for named parameter idiom
  Type & set__speed(
    const float & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__w(
    const float & _arg)
  {
    this->w = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    car_interfaces::msg::Car_<ContainerAllocator> *;
  using ConstRawPtr =
    const car_interfaces::msg::Car_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<car_interfaces::msg::Car_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<car_interfaces::msg::Car_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      car_interfaces::msg::Car_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<car_interfaces::msg::Car_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      car_interfaces::msg::Car_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<car_interfaces::msg::Car_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<car_interfaces::msg::Car_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<car_interfaces::msg::Car_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__car_interfaces__msg__Car
    std::shared_ptr<car_interfaces::msg::Car_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__car_interfaces__msg__Car
    std::shared_ptr<car_interfaces::msg::Car_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Car_ & other) const
  {
    if (this->speed != other.speed) {
      return false;
    }
    if (this->w != other.w) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Car_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Car_

// alias to use template instance with default allocator
using Car =
  car_interfaces::msg::Car_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace car_interfaces

#endif  // CAR_INTERFACES__MSG__DETAIL__CAR__STRUCT_HPP_
