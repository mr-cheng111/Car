#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <string>
#include <driver/uart.h>

#include "car_interfaces/msg/car.h"
#include <micro_ros_utilities/string_utilities.h>

#include "BMI088.h"
#include "Data.hpp"
#include "ROS.hpp"
#include "MahonyAHRS.h"

using namespace std;

class Car_t
{
public:
    HardwareSerial *MOTOR_Serial;
    System_Status_t System_Status_Flag;
    Bmi088 *BMI;
    float q[4] = {1,0,0,0};
    float Angle[3] = {0,0,0};

public:
    Car_t(uint16_t Serial_Num,Bmi088 *_Mpu = &Imu) : BMI(_Mpu)
    {
        this->System_Status_Flag.System_Status = SYSTEM_INIT;
        
        IMU_Init();
        /**
         * @brief 创建一个任务在Core 1 上
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
                                configMAX_PRIORITIES - 1,
                                NULL, 
                                1);
        
        /**
         * @brief 创建一个任务在Core 1 上
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
                                configMAX_PRIORITIES - 1,
                                NULL,
                                1);

        Car_Serial_Init(Serial_Num);
        this->System_Status_Flag.System_Status = SYSTEM_START;
    }

    void Car_Control_Task()
    {
        
        uint64_t Counter2 = 0;
        while(true)
        {
            Counter2++;
            Serial.printf("Car Control Task Counter = %lld\r\n",Counter2);
            if(this->System_Status_Flag.Serial_Work_Flag == true)
            {
                this->MOTOR_Serial->printf("Hello\r\n");
                Serial.printf("RS485 Send Finish\r\n");
            }
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
            Serial.printf("Imu status: %d\r\n",status);
            Serial.printf("Imu connect error\r\n");
            this->System_Status_Flag.Sensor_Work_Flag = IMU_CONNT_ERROR;
            delay(1000);
        } 
        Serial.println("Imu Init Done!\n");
    }
    void IMU_Task(void)
    {
        uint64_t Counter3 = 0;
        LED.LED_Work(LED_COLOR::ORANGE,0.1);
        while(true)
        {
            Imu.readSensor(&Imu_Data);
            MahonyAHRSupdateIMU(q,Imu_Data.gyroX,Imu_Data.gyroY,Imu_Data.gyroZ + 0.00520,Imu_Data.accX,Imu_Data.accY,Imu_Data.accZ);
            get_angle(q,&Angle[0],&Angle[1],&Angle[2]);
            Imu_msg.header.stamp.sec = rmw_uros_epoch_millis() * 1e-3;
            Imu_msg.header.stamp.nanosec = rmw_uros_epoch_nanos();
            Imu_msg.orientation.w = q[0];
            Imu_msg.orientation.x = q[1];
            Imu_msg.orientation.y = q[2];
            Imu_msg.orientation.z = q[3];
            Imu_msg.angular_velocity.x = Imu_Data.gyroX;
            Imu_msg.angular_velocity.y = Imu_Data.gyroY;
            Imu_msg.angular_velocity.z = Imu_Data.gyroZ;
            Imu_msg.linear_acceleration.x = Imu_Data.accX;
            Imu_msg.linear_acceleration.y = Imu_Data.accY;
            Imu_msg.linear_acceleration.z = Imu_Data.accZ;
            Counter3++;
            Serial.printf("Imu Task Counter = %lld\r\n",Counter3);
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

        this->MOTOR_Serial->begin(115200);
        this->MOTOR_Serial->setMode(UART_MODE_RS485_HALF_DUPLEX);
        this->MOTOR_Serial->setPins(18,8,UART_PIN_NO_CHANGE,17);

        this->MOTOR_Serial->onReceive(this->Serial_Get_Motor_Data());
        /*
        *设置系统调试串口
        */
        
        
    }

    /**
     * @brief 电机串口回调
     * 
     */
    OnReceiveCb IRAM_ATTR Serial_Get_Motor_Data(void)
    {
        this->System_Status_Flag.Serial_Work_Flag = true;
        Serial.printf("Serial Init finished\n");
        while(this->MOTOR_Serial->available())
        {

        }
    }
};



