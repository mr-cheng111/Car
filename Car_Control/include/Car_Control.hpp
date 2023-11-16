#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <string>

#include "car_interfaces/msg/car.h"
// #include "std_msgs/msg/int32.h"
#include <micro_ros_utilities/string_utilities.h>

#include "BMI088.h"
#include "MahonyAHRS.h"
#include "Data.hpp"

using namespace std;

#define LED_Pin 4

class Car_t
{
public:
    HardwareSerial *MOTOR_L_Serial;
    HardwareSerial *MOTOR_R_Serial;
    System_Status_t System_Status_Flag;
    Bmi088 *BMI;
private:
    float q[4] = {1,0,0,0};

public:
    Car_t(uint16_t Serial_Num,Bmi088 *_Mpu = &Imu) : BMI(_Mpu)
    {
        this->System_Status_Flag.System_Status = SYSTEM_INIT;

        IMU_Init();

        /**
         * @brief 创建一个任务在Core 0 上
         * Lidar_Data_Task    任务函数
         * "Lidar_Data_Task"  任务名称
         * 1024      任务占用内存大小
         * this         任务参数，为空
         * 0               任务优先级
         * NULL     任务Handle可以为空
         * 1                 内核编号
         */
        xTaskCreatePinnedToCore([](void*param)->void
                                {Car_t *I = static_cast<Car_t*>(param);
                                I->Car_Control_Task();},
                                "Car_Control_Task", 
                                20*1024, 
                                this, 
                                1,
                                NULL, 
                                0);
        
        /**
         * @brief 创建一个任务在Core 0 上
         * Lidar_Data_Task    任务函数
         * "Lidar_Data_Task"  任务名称
         * 1024      任务占用内存大小
         * this         任务参数，为空
         * 0               任务优先级
         * NULL     任务Handle可以为空
         * 1                 内核编号
         */
        xTaskCreatePinnedToCore([](void*param)->void
                                {Car_t *I = static_cast<Car_t*>(param);
                                I->IMU_Task();},
                                "IMU_Task", 
                                20*1024, 
                                this, 
                                1,
                                NULL,
                                0);
        Car_Serial_Init(Serial_Num);
        this->System_Status_Flag.System_Status = SYSTEM_START;
    }

    void Car_Control_Task()
    {
        
        uint32_t Counter2 = 0;
        while(true)
        {
            Counter2++;
            Serial.printf("Counter2 = %d\r\n",Counter2);
            vTaskDelay(1);
        }
    }
    void IMU_Init(void)
    {   
        int status = 0;
        Serial.begin(921600);
        this->System_Status_Flag.Sensor_Work_Flag = IMU_INIT;

        status = Imu.begin();
        
        this->System_Status_Flag.Sensor_Work_Flag = IMU_START_WORK;

        status = Imu.setRange(Bmi088::ACCEL_RANGE_6G,Bmi088::GYRO_RANGE_500DPS);

        status = Imu.setOdr(Bmi088::ODR_2000HZ);

        Serial.printf("Imu status: %d\r\n",status);

        while(status != 1)
        { 
            Serial.printf("connect error\r\n");
            this->System_Status_Flag.Sensor_Work_Flag = IMU_CONNT_ERROR;
        } 

        Serial.println("Done!\n");
    }
    void IMU_Task(void)
    {
        uint32_t Counter3 = 0;
        LED.LED_Work(LED_COLOR::ORANGE,0.1);
        while(true)
        {
            // if(xSemaphoreTake(xMutexImu,timeOut) == pdPASS)
            // {
                BMI->readSensor();
                //Imu_Data.temp = BMI->getTemperature_C();
                Imu_Data.accX = BMI->getAccelY_mss();
                Imu_Data.accY =-BMI->getAccelX_mss();
                Imu_Data.accZ = BMI->getAccelZ_mss();
                Imu_Data.gyroX = BMI->getGyroY_rads();
                Imu_Data.gyroY =-BMI->getGyroX_rads();
                Imu_Data.gyroZ = BMI->getGyroZ_rads();

                MahonyAHRSupdateIMU(q,Imu_Data.gyroX,Imu_Data.gyroY,Imu_Data.gyroZ + 0.00521,Imu_Data.accX,Imu_Data.accY,Imu_Data.accZ);
                //Serial.printf("%f,%f,%f,%f,%f,%f\n",Imu_Data.accX,Imu_Data.accY,Imu_Data.accZ,Imu_Data.gyroX,Imu_Data.gyroY,Imu_Data.gyroZ);
                
            //     xSemaphoreGive(xMutexImu);
            // }
            // else 
            // {

            // }
            // Counter3++;
            // Serial.printf("Counter3 = %d\r\n",Counter3);
            vTaskDelay(10);
        }

    }

                    
    void Car_Serial_Init(const int Serial_Num)
    {
        /*
        *设置电机串口
        */
        switch(Serial_Num>>8 & 0xFF)
        {
            case 0:this->MOTOR_L_Serial = &Serial0;break;

            case 1:this->MOTOR_L_Serial = &Serial1;break;

            case 2:this->MOTOR_L_Serial = &Serial2;break;

            default :this->MOTOR_L_Serial = &Serial0;break;
        }
        switch(Serial_Num & 0xFF)
        {
            case 0:this->MOTOR_R_Serial = &Serial0;break;

            case 1:this->MOTOR_R_Serial = &Serial1;break;

            case 2:this->MOTOR_R_Serial = &Serial2;break;

            default :this->MOTOR_R_Serial = &Serial0;break;
        }
        this->MOTOR_L_Serial->begin(230400);
        this->MOTOR_L_Serial->setPins(17,18);
        this->MOTOR_L_Serial->onReceive(this->Serial_Get_L_Motor_Data());
        this->MOTOR_R_Serial->begin(230400);
        this->MOTOR_R_Serial->setPins(15,16);
        this->MOTOR_R_Serial->onReceive(this->Serial_Get_R_Motor_Data());
        /*
        *设置系统调试串口
        */
        Serial.begin(115200);
        this->System_Status_Flag.Serial_Work_Flag = true;
    }

    /**
     * @brief 电机串口回调
     * 
     */
    OnReceiveCb Serial_Get_L_Motor_Data(void)
    {
        while(this->MOTOR_L_Serial->available())
        {

        }
    }
    OnReceiveCb Serial_Get_R_Motor_Data(void)
    {
        while(this->MOTOR_R_Serial->available())
        {

        }
    }

};



