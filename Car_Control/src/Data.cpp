#include "../include/Data.hpp"

SemaphoreHandle_t xMutexImu = NULL; //创建信号量Handler
TickType_t timeOut = 1; //用于获取信号量的Timeout 1 ticks
SPIClass Imu_SPI(0);
Bmi088 Imu(Imu_SPI,39,38);
BMI088_Data_t Imu_Data;
volatile uint32_t System_Work_Flag = 0;
LEDs LED;
WIFI_Data_t Wifi_input;
sensor_msgs__msg__Imu Imu_msg; // 定义Imu消息
nav_msgs__msg__Odometry Odom_msg;//定义轮式编码器消息
Car_control_t Car_control;//机器人控制数据
int timeout_ms = 1000;
uint64_t time_ms = 0;

