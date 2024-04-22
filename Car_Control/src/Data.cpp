#include "../include/Data.hpp"
#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include "../lib/Odom/Odom_Data_Process.hpp"

SemaphoreHandle_t xMutexImu_ = NULL; //创建信号量Handler
TickType_t timeOut_ = 1; //用于获取信号量的Timeout 1 ticks

SPIClass Imu_SPI(0);
Bmi088 Imu_(Imu_SPI,39,38);
BMI088_Data_t Imu_Data_;

LEDs LED_;
WIFI_Data_t Wifi_input_;
System_Status_t System_Status_Flag;

Motor_Data_t Wheel_L_Data_;
Motor_Data_t Wheel_R_Data_;

Car_Control_t Car_Control_;//机器人控制数据
Odom_Data_Process_t Odom_Data_Processer_(&Wheel_L_Data_, &Wheel_R_Data_);

/**********************Micro ROS相关*************************/
rclc_executor_t Executor_;
rclc_support_t Support_;
rcl_allocator_t Allocator_;
rcl_node_t Node_;
/***********Micro ROS相关变量************/
rcl_subscription_t Subscriber_; // 订阅Cmd_vel话题
rcl_publisher_t Publisher_Imu_; // 定义Imu话题发布者
rcl_publisher_t Publisher_Odom_;// 定义Odom话题发布者
rcl_ret_t Rcl_Ret_;
rcl_timer_t Timer_;         // 用于在指定的时间间隔内执行回调函数

/**********Micro ROS消息定义************/
sensor_msgs__msg__Imu Imu_msg_; // 定义Imu消息
nav_msgs__msg__Odometry Odom_msg_;//定义轮式编码器消息