// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice

#ifndef WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__STRUCT_HPP_
#define WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'data'
#include "wireless_lidar/msg/detail/point_data__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wireless_lidar__msg__LidarData __attribute__((deprecated))
#else
# define DEPRECATED__wireless_lidar__msg__LidarData __declspec(deprecated)
#endif

namespace wireless_lidar
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LidarData_
{
  using Type = LidarData_<ContainerAllocator>;

  explicit LidarData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->header = 0;
      this->pkg_length = 0;
      this->rate = 0;
      this->start_angle = 0;
      this->data.fill(wireless_lidar::msg::PointData_<ContainerAllocator>{_init});
      this->stop_angle = 0;
      this->sum_data = 0;
    }
  }

  explicit LidarData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->header = 0;
      this->pkg_length = 0;
      this->rate = 0;
      this->start_angle = 0;
      this->data.fill(wireless_lidar::msg::PointData_<ContainerAllocator>{_alloc, _init});
      this->stop_angle = 0;
      this->sum_data = 0;
    }
  }

  // field types and members
  using _header_type =
    uint16_t;
  _header_type header;
  using _pkg_length_type =
    uint8_t;
  _pkg_length_type pkg_length;
  using _rate_type =
    uint16_t;
  _rate_type rate;
  using _start_angle_type =
    uint16_t;
  _start_angle_type start_angle;
  using _data_type =
    std::array<wireless_lidar::msg::PointData_<ContainerAllocator>, 16>;
  _data_type data;
  using _stop_angle_type =
    uint16_t;
  _stop_angle_type stop_angle;
  using _sum_data_type =
    uint8_t;
  _sum_data_type sum_data;

  // setters for named parameter idiom
  Type & set__header(
    const uint16_t & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pkg_length(
    const uint8_t & _arg)
  {
    this->pkg_length = _arg;
    return *this;
  }
  Type & set__rate(
    const uint16_t & _arg)
  {
    this->rate = _arg;
    return *this;
  }
  Type & set__start_angle(
    const uint16_t & _arg)
  {
    this->start_angle = _arg;
    return *this;
  }
  Type & set__data(
    const std::array<wireless_lidar::msg::PointData_<ContainerAllocator>, 16> & _arg)
  {
    this->data = _arg;
    return *this;
  }
  Type & set__stop_angle(
    const uint16_t & _arg)
  {
    this->stop_angle = _arg;
    return *this;
  }
  Type & set__sum_data(
    const uint8_t & _arg)
  {
    this->sum_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wireless_lidar::msg::LidarData_<ContainerAllocator> *;
  using ConstRawPtr =
    const wireless_lidar::msg::LidarData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wireless_lidar::msg::LidarData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wireless_lidar::msg::LidarData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wireless_lidar::msg::LidarData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wireless_lidar::msg::LidarData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wireless_lidar::msg::LidarData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wireless_lidar::msg::LidarData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wireless_lidar::msg::LidarData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wireless_lidar::msg::LidarData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wireless_lidar__msg__LidarData
    std::shared_ptr<wireless_lidar::msg::LidarData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wireless_lidar__msg__LidarData
    std::shared_ptr<wireless_lidar::msg::LidarData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LidarData_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pkg_length != other.pkg_length) {
      return false;
    }
    if (this->rate != other.rate) {
      return false;
    }
    if (this->start_angle != other.start_angle) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    if (this->stop_angle != other.stop_angle) {
      return false;
    }
    if (this->sum_data != other.sum_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const LidarData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LidarData_

// alias to use template instance with default allocator
using LidarData =
  wireless_lidar::msg::LidarData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wireless_lidar

#endif  // WIRELESS_LIDAR__MSG__DETAIL__LIDAR_DATA__STRUCT_HPP_
