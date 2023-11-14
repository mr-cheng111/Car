#ifndef DATA
#define DATA
#include <Arduino.h>
#include <rcl/rcl.h>

#include <string>
#include "SPI.h"
#include "BMI088.h"
#include "LED.h"
#include "search.h"

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

}System_Status_t;

typedef struct 
{
    String Wifi_SSID;
    String Pass_Word;
    String Host_Ip;
    uint16_t Port;
    
}WIFI_Data_t;

typedef struct {
  float temp;
  float accX;
  float accY;
  float accZ;
  float gyroX;
  float gyroY;
  float gyroZ;
} BMI088_Data_t;

extern SemaphoreHandle_t xMutexImu; //创建信号量Handler
extern TickType_t timeOut; //用于获取信号量的Timeout 1 ticks
extern SPIClass Imu_SPI;
extern Bmi088 Imu;
extern BMI088_Data_t Imu_Data;
extern volatile uint32_t System_Work_Flag;
extern LEDs LED;
#endif