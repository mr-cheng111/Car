// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from car_interfaces:msg/Car.idl
// generated code does not contain a copyright notice

#ifndef CAR_INTERFACES__MSG__DETAIL__CAR__BUILDER_HPP_
#define CAR_INTERFACES__MSG__DETAIL__CAR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "car_interfaces/msg/detail/car__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace car_interfaces
{

namespace msg
{

namespace builder
{

class Init_Car_y
{
public:
  explicit Init_Car_y(::car_interfaces::msg::Car & msg)
  : msg_(msg)
  {}
  ::car_interfaces::msg::Car y(::car_interfaces::msg::Car::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::car_interfaces::msg::Car msg_;
};

class Init_Car_x
{
public:
  explicit Init_Car_x(::car_interfaces::msg::Car & msg)
  : msg_(msg)
  {}
  Init_Car_y x(::car_interfaces::msg::Car::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Car_y(msg_);
  }

private:
  ::car_interfaces::msg::Car msg_;
};

class Init_Car_w
{
public:
  explicit Init_Car_w(::car_interfaces::msg::Car & msg)
  : msg_(msg)
  {}
  Init_Car_x w(::car_interfaces::msg::Car::_w_type arg)
  {
    msg_.w = std::move(arg);
    return Init_Car_x(msg_);
  }

private:
  ::car_interfaces::msg::Car msg_;
};

class Init_Car_speed
{
public:
  Init_Car_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Car_w speed(::car_interfaces::msg::Car::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_Car_w(msg_);
  }

private:
  ::car_interfaces::msg::Car msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::car_interfaces::msg::Car>()
{
  return car_interfaces::msg::builder::Init_Car_speed();
}

}  // namespace car_interfaces

#endif  // CAR_INTERFACES__MSG__DETAIL__CAR__BUILDER_HPP_
