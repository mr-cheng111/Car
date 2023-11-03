#include "../include/Data.hpp"

SemaphoreHandle_t xMutexMPU6050 = NULL; //创建信号量Handler
TickType_t timeOut = 1; //用于获取信号量的Timeout 1 ticks
MPU6050 _Mpu(Wire1);
MPU6050_t MPU_Data;
volatile uint32_t System_Work_Flag = 0;



