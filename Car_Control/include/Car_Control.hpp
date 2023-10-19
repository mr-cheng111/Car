#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <string>

// #include "wireless_lidar/msg/lidar_data.h"
#include "std_msgs/msg/int32.h"
#include <micro_ros_utilities/string_utilities.h>

#include "MPU6050_light.h"
#include "Data.hpp"

// enum SYSTEM_FLAG
// {
//     SYSTEM_INIT = 0,
//     SYSTEM_START,
//     SYSTEM_STOP
// };

// typedef struct
// {   
//     uint32_t System_Status;
//     bool Wifi_Work_Flag;
//     bool ROS_Work_Flag;
//     bool Sensor_Work_Flag;
//     bool Serial_Work_Flag;
//     bool Serial_Get_Data_Flag;
//     bool System_Time_Sync;
//     rcl_ret_t Rcl_Pub_Flag;

// }System_Status_t;

// typedef struct 
// {
//     String Wifi_SSID;
//     String Pass_Word;
//     String Host_Ip;
//     uint16_t Port;
    
// }WIFI_Data_t;

using namespace std;

#define LED_Pin 4

class Car_t
{
public:
    HardwareSerial *MOTOR_L_Serial;
    HardwareSerial *MOTOR_R_Serial;
    System_Status_t System_Status_Flag;
    TwoWire *Mpu_Wire;
    MPU6050 *Mpu;
private:
    rclc_executor_t executor;
    rclc_support_t support;
    rcl_allocator_t allocator;
    rcl_node_t node;
    // 声明话题订阅者
    rcl_subscription_t subscriber;
    // 声明消息文件
    std_msgs__msg__Int32 sub_msg;

    const WIFI_Data_t Wifi_Data;
    uint8_t Temp_Data[256];
    uint32_t WiFi_DisCon_Time = 0;

public:
    Car_t(WIFI_Data_t Wifi_Input,uint16_t Serial_Num,TwoWire *_Wire = &Wire1,MPU6050 *_Mpu = &_Mpu) : Wifi_Data(Wifi_Input) , Mpu_Wire(_Wire) , Mpu(_Mpu)
    {
        this->System_Status_Flag.System_Status = SYSTEM_INIT;

        MPU_Init();

        Wifi_Init(this->Wifi_Data,2000);
        
        Ros_Init();

        // 初始化LED
        pinMode(LED_Pin, OUTPUT);

        
        /**
         * @brief 创建一个任务在Core 1 上
         * microros_task    任务函数
         * "microros_task"  任务名称
         * 10240      任务占用内存大小
         * NULL         任务参数，为空
         * 0               任务优先级
         * NULL     任务Handle可以为空
         * 1                 内核编号
         */
        xTaskCreatePinnedToCore([](void*param)->void
                                {Car_t *I = static_cast<Car_t*>(param);
                                I->Micro_Ros_Task();},
                                "Micro_Ros_Task", 
                                100*1024, 
                                this, 
                                1, 
                                NULL, 
                                1);

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
        Ros_Serial_Init(Serial_Num);
        this->System_Status_Flag.System_Status = SYSTEM_START;
    }

    void Micro_Ros_Task()
    {
        digitalWrite(LED_Pin, HIGH);
        uint32_t Counter1 = 0;
        while(true)
        {
            // if(this->System_Status_Flag.Wifi_Work_Flag)
            // {
            //     if (!rmw_uros_epoch_synchronized()) // 判断时间是否同步
            //     {
            //         this->System_Status_Flag.System_Time_Sync = false;

            //         rmw_uros_sync_session(1); //  同步时间

            //         continue;
            //     }

            //     this->System_Status_Flag.System_Time_Sync = true;

            rclc_executor_spin_some(&this->executor, RCL_MS_TO_NS(1));
            // }
            Serial.printf("Counter1 = %d\r\n",Counter1);
            Counter1++;
            vTaskDelay(1);
        }
    }

    void Car_Control_Task()
    {
        
        uint32_t Counter2 = 0;
        while(true)
        {
            // if(this->System_Status_Flag.Wifi_Work_Flag)
            // {
            // }
            if(xSemaphoreTake(xMutexMPU6050,timeOut) == pdPASS)
            {
                Mpu->update();
                MPU_Data.temp = Mpu->getTemp();
                MPU_Data.accX = Mpu->getAngleX();
                MPU_Data.accY = Mpu->getAngleY();
                MPU_Data.accZ = Mpu->getAngleZ();
                MPU_Data.gyroX = Mpu->getGyroX();
                MPU_Data.gyroY = Mpu->getGyroY();
                MPU_Data.gyroZ = Mpu->getGyroZ();
                xSemaphoreGive(xMutexMPU6050);
            }
            else 
            {

            }
            Counter2++;
            Serial.printf("Counter2 = %d\r\n",Counter2);
            vTaskDelay(1);
        }
    }
    void MPU_Init(void)
    {   
        Serial.begin(115200);
        this->System_Status_Flag.Sensor_Work_Flag = MPU6050_INIT;
        Mpu_Wire->setPins(42,41);
        Mpu_Wire->setClock(800000);
        Mpu_Wire->begin();
        byte status = Mpu->begin();
        this->System_Status_Flag.Sensor_Work_Flag = MPU6050_START_WIRE;

        Serial.printf("MPU6050 status: %d\r\n",status);

        while(status != 0)
        { 
            Serial.printf("cpnnect error\r\n");
            this->System_Status_Flag.Sensor_Work_Flag = MPU6050_CONNT_ERROR;
        } // stop Task if could not connect to MPU6050
        
        Serial.println(F("Calculating offsets, do not move MPU6050 After 1s\r\n"));
        this->System_Status_Flag.Sensor_Work_Flag = MPU6050_CALC_OFFSET;
        delay(1000);

        Mpu->calcOffsets(true,true); // gyro and accelero

        Serial.println("Done!\n");
        this->System_Status_Flag.Sensor_Work_Flag = MPU6050_START_WORK;

    }

    void Wifi_Init(const WIFI_Data_t Wifi_Input,const uint16_t Wait_Time)
    {
        // 设置通过WIFI进行MicroROS通信
        IPAddress agent_ip;

        agent_ip.fromString(Wifi_Input.Host_Ip.c_str());

        char* Wifi_Data_Temp = new char[Wifi_Input.Wifi_SSID.length() + 1];  // 额外空间用于存储字符串的结束符 '\0'  

        strcpy(Wifi_Data_Temp, Wifi_Input.Wifi_SSID.c_str());
        
        char* Pass_Word_Temp = new char[Wifi_Input.Pass_Word.length() + 1];  // 额外空间用于存储字符串的结束符 '\0'  

        strcpy(Pass_Word_Temp, Wifi_Input.Pass_Word.c_str());

        //设定WiFi的发送功率
        WiFi.setTxPower(WIFI_POWER_19_5dBm);

        // 设置wifi名称，密码，电脑IP,端口号
        set_microros_wifi_transports(Wifi_Data_Temp, Pass_Word_Temp, agent_ip, Wifi_Input.Port);

        delay(Wait_Time);

        delete[] Wifi_Data_Temp;

        delete[] Pass_Word_Temp;

        this->System_Status_Flag.Wifi_Work_Flag = true;
    
    }

    void Ros_Init()
    {
        this->System_Status_Flag.ROS_Work_Flag = ROS_INIT;
        // 初始化内存分配器
        this->allocator = rcl_get_default_allocator();
        // 创建初始化选项
        rclc_support_init(&this->support, 0, NULL, &this->allocator);
        // 创建节点 microros_wifi
        rclc_node_init_default(&this->node, "microros_wifi_car", "", &this->support);
        //定义一个话题发布者
        rclc_subscription_init_default(
        &this->subscriber,
        &this->node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        "Car_Control");

        // 创建执行器
        rclc_executor_init(&this->executor, &this->support.context, 1, &this->allocator);
        // 为执行器添加一个订阅者
        rclc_executor_add_subscription(&this->executor, &this->subscriber, &this->sub_msg, &Car_t::callback_subscription_, ON_NEW_DATA);
        // 初始化LED
        pinMode(LED_Pin, OUTPUT);
        
        this->System_Status_Flag.ROS_Work_Flag = ROS_START_WORK;
    }
    
    static void callback_subscription_(const void *msgin)
    {
        const std_msgs__msg__Int32 *msg = (const std_msgs__msg__Int32 *)msgin;
        if(msg->data == 0)
        {
            digitalWrite(LED_Pin, LOW);
        }
        else
        {
            digitalWrite(LED_Pin, HIGH);
        }
    }

                    
    void Ros_Serial_Init(const int Serial_Num)
    {
        /*
        *设置雷达串口
        */
        switch(Serial_Num>>8 & 0xFF)
        {
            case 0:this->MOTOR_L_Serial = &Serial;break;

            case 1:this->MOTOR_L_Serial = &Serial1;break;

            case 2:this->MOTOR_L_Serial = &Serial2;break;

            default :this->MOTOR_L_Serial = &Serial;break;
        }
        switch(Serial_Num & 0xFF)
        {
            case 0:this->MOTOR_R_Serial = &Serial;break;

            case 1:this->MOTOR_R_Serial = &Serial1;break;

            case 2:this->MOTOR_R_Serial = &Serial2;break;

            default :this->MOTOR_R_Serial = &Serial;break;
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



