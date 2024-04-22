#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <string>
#include <driver/uart.h>

#include <micro_ros_utilities/string_utilities.h>

#include "Data.hpp"
#include "ROS.hpp"
#include "../lib/Imu/BMI088.h"
#include "../lib/Imu/MahonyAHRS.h"
#include "../lib/CRC_Calc/CRC16_Modbus.hpp"
#include "../lib/Odom/Odom_Data_Process.hpp"

using namespace std;

class Car_t
{
public:
    HardwareSerial *MOTOR_Serial;
    Bmi088 *BMI;
    Micro_ROS_t *ROS;
    Odom_Data_Process_t *Odom_Data_Processer;

    Motor_Data_t *Wheel_L;
    Motor_Data_t *Wheel_R;
    
    uint64_t Get_MOTOR_Data_Counter1 = 0;
    uint64_t Get_MOTOR_Data_Counter2 = 0;

public:
    Car_t(uint8_t Serial_Num,Bmi088 *_Mpu = &Imu_,Micro_ROS_t *ROS_Pointer = NULL,Odom_Data_Process_t *Odom_Data_Processer = NULL, Motor_Data_t *Wheel_L = &Wheel_L_Data_,  Motor_Data_t *Wheel_R = &Wheel_R_Data_) : BMI(_Mpu)
    {
        System_Status_Flag.System_Status = SYSTEM_INIT;
        if(ROS_Pointer != NULL)
        {
            ROS = ROS_Pointer;
        }
        else
        {
            while(true)
            {
                Serial.printf("Init Error! No ROS POinter");
                delay(1000);
            }
        }
        if(Odom_Data_Processer != NULL)
        {
            this->Odom_Data_Processer = Odom_Data_Processer;
        }
        IMU_Init();
        /**
         * @brief 创建一个任务在Core 1 上
         * Car_Control_Task    任务函数
         * "Car_Control_Task"  任务名称
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
                                100*1024, 
                                this, 
                                configMAX_PRIORITIES - 1,
                                NULL, 
                                1);
        
        // /**
        //  * @brief 创建一个任务在Core 1 上
        //  * Imu_Task    任务函数
        //  * "Imu_Task"  任务名称
        //  * 1024      任务占用内存大小
        //  * this         任务参数，为空
        //  * 0               任务优先级
        //  * NULL     任务Handle可以为空
        //  * 1                 内核编号
        //  */
        // xTaskCreatePinnedToCore([](void*param)->void
        //                         {Car_t *I = static_cast<Car_t*>(param);
        //                         I->IMU_Task();},
        //                         "IMU_Task", 
        //                         100*1024, 
        //                         this, 
        //                         configMAX_PRIORITIES - 2,
        //                         NULL,
        //                         1);
        
        Car_Serial_Init(Serial_Num);
        Motor_Init();
        System_Status_Flag.System_Status = SYSTEM_START;
    }

    void Car_Control_Task()
    {
        uint64_t Counter2 = 0;
        
        while(true)
        {
            Counter2++;
            if(System_Status_Flag.Serial_Work_Flag == true)
            {
                if(System_Status_Flag.Get_ROS_Control_Flag > 0)
                {
                    System_Status_Flag.Get_ROS_Control_Flag --;
                    // Serial.printf("VV1= %f\r\n",Car_Control.Forward_Speed);
                    Set_Motor_Speed(Car_Control_);
                }
                else
                {
                    Car_Control_t Temp;
                    Set_Motor_Speed(Temp);
                }
            }
            vTaskDelay(1);
        }
    }
    void IMU_Task(void)
    {
        uint64_t Counter3 = 0;
        LED_.LED_Work(LED_COLOR::BLUE,0.1);
        while(true)
        {
   
            vTaskDelay(1);
        }

    }

    void Car_Serial_Init(const int Serial_Num)
    {
        /*
        *设置电机串口
        */
        switch(Serial_Num)
        {
            case 0:this->MOTOR_Serial = &Serial0;break;

            case 1:this->MOTOR_Serial = &Serial1;break;

            case 2:this->MOTOR_Serial = &Serial2;break;

            default :this->MOTOR_Serial = &Serial1;break;
        }

        this->MOTOR_Serial->begin(1000000);
        this->MOTOR_Serial->setMode(UART_MODE_RS485_HALF_DUPLEX);
        this->MOTOR_Serial->setPins(18,8,UART_PIN_NO_CHANGE,17);
        this->MOTOR_Serial->setTimeout(1);
    }

    void IMU_Init(void)
    {   
        int status = 0;

        System_Status_Flag.Sensor_Work_Flag = IMU_INIT;

        status = Imu_.begin();
        
        System_Status_Flag.Sensor_Work_Flag = IMU_START_WORK;

        status = Imu_.setRange(Bmi088::ACCEL_RANGE_6G,Bmi088::GYRO_RANGE_500DPS);

        status = Imu_.setOdr(Bmi088::ODR_2000HZ);

        Serial.printf("Imu status: %d\r\n",status);

        while(status != 1)
        { 
            Serial.printf("Imu status: %d\r\n",status);
            Serial.printf("Imu connect error\r\n");
            System_Status_Flag.Sensor_Work_Flag = IMU_CONNT_ERROR;
            delay(1000);
        } 
        Serial.println("Imu Init Done!\n");
    }

    void Motor_Init(void)
    {
        uint8_t Temp_Data1[13] = {0x3E,0x01,0x08,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        uint16_t Temp_CRC = 0;
        Temp_CRC = crc16tablefast(Temp_Data1,11);

        Temp_Data1[11] = Temp_CRC;
        Temp_Data1[12] = Temp_CRC>>8;
        this->MOTOR_Serial->write((char *)Temp_Data1,13);
        Serial.write((char *)Temp_Data1);

        delay(100);
        uint8_t Temp_Data2[13] = {0x3E,0x02,0x08,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        Temp_CRC = crc16tablefast(Temp_Data2,11);

        Temp_Data2[11] = Temp_CRC;
        Temp_Data2[12] = Temp_CRC>>8;
        this->MOTOR_Serial->write((char *)Temp_Data2,13);
        Serial.write((char *)Temp_Data2);
        
        this->MOTOR_Serial->onReceive(this->Serial_Get_Motor_Data(),true);
    }

    void Set_Motor_Speed(Car_Control_t Control_Data)
    {
        // uint16_t Temp_CRC  = 0;
        // float Weel_L_Speed = Control_Data.Forward_Speed;

        // int32_t Speed_L = Weel_L_Speed * 100;
        

        // uint8_t Temp_Data1[13] = {0x3E,0x01,0x08,0xA2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        // memcpy(Temp_Data1 + 7, (void*)&Speed_L, 4);
        // Temp_CRC = crc16tablefast(Temp_Data1,11);

        // Temp_Data1[11] = Temp_CRC;
        // Temp_Data1[12] = Temp_CRC>>8;
        // this->MOTOR_Serial->write((char *)Temp_Data1,13);
        
        // vTaskDelay(1);

        // float Weel_R_Speed = Control_Data.Forward_Speed;
        // Weel_R_Speed *= 180;
        // Weel_R_Speed /= PI;
        
        // int32_t Speed_R =-Weel_R_Speed * 100;

        // uint8_t Temp_Data2[13] = {0x3E,0x02,0x08,0xA2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        // memcpy(Temp_Data2 + 7, (void*)&Speed_R, 4);
        // Temp_CRC = crc16tablefast(Temp_Data2,11);

        // Temp_Data2[11] = Temp_CRC;
        // Temp_Data2[12] = Temp_CRC>>8;
        // this->MOTOR_Serial->write((char *)Temp_Data2,13);   
    }
    /**
     * @brief 电机串口回调
     * 
     */
    OnReceiveCb IRAM_ATTR Serial_Get_Motor_Data(void)
    {
        System_Status_Flag.Serial_Work_Flag = true;
        Serial.printf("Serial Init finished\n");
        uint8_t Temp_Data_Buffer[13];
        while(true)
        {
            if(this->MOTOR_Serial->available() >= 13)
            {
                this->MOTOR_Serial->read(Temp_Data_Buffer,13);
                if(crc16tablefast(Temp_Data_Buffer,11) == (Temp_Data_Buffer[12]<<8 | Temp_Data_Buffer[11]))
                {
                    if(Temp_Data_Buffer[1] == 0x01)
                    {
                        memcpy(this->Wheel_L,(Temp_Data_Buffer + 3),8);                       
                    }
                    else if(Temp_Data_Buffer[1] == 0x02)
                    {
                        memcpy(this->Wheel_R,(Temp_Data_Buffer + 3),8);
                    }
                }
            }
            
        }
    }
};



