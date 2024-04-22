#ifndef DATA
#define DATA
#include <Arduino.h>
#include <rcl/rcl.h>
#include <sensor_msgs/msg/imu.h>
#include <nav_msgs/msg/odometry.h>
#include <string>
#include "SPI.h"
#include "BMI088.h"
#include "../lib/Odom/Odom_Data_Process.hpp"
#include "LED.h"
#include "search.h"
#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

enum SYSTEM_FLAG
{
    SYSTEM_INIT = 0,
    SYSTEM_START,
    SYSTEM_STOP
};

enum ROS_WORK_FLAG
{
    ROS_INIT = 0,
    ROS_GET_IP,
    ROS_GET_SSID,
    ROS_GET_PASSWORD,
    ROS_CONNECTTING,
    ROS_START_WORK
};

enum SENSE_FLAG
{
    IMU_INIT = 0,
    IMU_START_SPI,
    IMU_CONNT_ERROR,
    IMU_START_WORK,
    IMU_CALC_OFFSET
};

enum SERIAL_FLAG
{
    Serial_Init = 0,
    Serial_Start_Work
};

enum ROS_TIME_FLAG
{
    ROS_TIME_SYNC_INITTING = 0,
    ROS_TIME_SYNC_FINISH
};

typedef struct
{   
    uint32_t System_Status;
    uint8_t ROS_Work_Flag;
    uint8_t Sensor_Work_Flag;
    uint8_t Serial_Work_Flag;
    uint8_t System_Time_Sync;
    rcl_ret_t Rcl_Pub_Flag;
    uint8_t Seria_Get_Data_Flag1;
    uint8_t Seria_Get_Data_Flag2;
    uint32_t Get_ROS_Control_Flag;

}System_Status_t;

typedef struct 
{
    String Wifi_SSID = "Xiaomi_WIFI";
    String Pass_Word = "12345678910";
    String Host_Ip = "192.168.31.255";
    uint16_t Port = 9999;
    
}WIFI_Data_t;

typedef struct 
{
    float Forward_Speed;    //输入速度控制数据，单位：m/s
    float Spinning_Speed;   //输入旋转速度控制，单位：rad/s
    
}Car_Control_t;

extern SemaphoreHandle_t xMutexImu_; //创建信号量Handler
extern TickType_t timeOut_; //用于获取信号量的Timeout 1 ticks
extern SPIClass Imu_SPI_;
extern Bmi088 Imu_;
extern BMI088_Data_t Imu_Data_;
extern volatile uint32_t System_Work_Flag_;
extern LEDs LED_;
extern WIFI_Data_t Wifi_input_;
extern sensor_msgs__msg__Imu Imu_msg_;
extern nav_msgs__msg__Odometry Odom_msg_;

extern Car_Control_t Car_Control_;//机器人控制数据
extern Odom_Data_Process_t Odom_Data_Processer_;
extern System_Status_t System_Status_Flag;
extern Motor_Data_t Wheel_L_Data_;
extern Motor_Data_t Wheel_R_Data_;

extern rclc_executor_t Executor_;
extern rclc_support_t Support_;
extern rcl_allocator_t Allocator_;
extern rcl_node_t Node_;
// 声明话题订阅者
extern rcl_subscription_t Subscriber_;
extern rcl_publisher_t Publisher_Imu_; // 定义Imu话题发布者
extern rcl_publisher_t Publisher_Odom_;// 声明话题发布者
extern rcl_ret_t Rcl_Ret_;
extern rcl_timer_t Timer_;         // 用于在指定的时间间隔内执行回调函数

#endif