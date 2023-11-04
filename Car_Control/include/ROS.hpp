#ifndef MICRO_ROS_TASK
#define MICRO_ROS_TASK

#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <string>

#include "car_interfaces/msg/car.h"
// #include "std_msgs/msg/int32.h"
#include <micro_ros_utilities/string_utilities.h>

#include "Data.hpp"

class Micro_ROS_t
{
    public:
        Micro_ROS_t(WIFI_Data_t Wifi_Input) : Wifi_Data(Wifi_Input)
        {
            Wifi_Init(this->Wifi_Data,2000);
        
            Ros_Init();

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
                                    {Micro_ROS_t *I = static_cast<Micro_ROS_t*>(param);
                                    I->Micro_Ros_Task();},
                                    "Micro_Ros_Task", 
                                    100*1024, 
                                    this, 
                                    2, 
                                    NULL, 
                                    1);
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
        
        }
        void Ros_Init()
        {
            // this->System_Status_Flag.ROS_Work_Flag = ROS_INIT;
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
            ROSIDL_GET_MSG_TYPE_SUPPORT(car_interfaces, msg, Car),
            "Car_Control");

            // 创建执行器
            rclc_executor_init(&this->executor, &this->support.context, 1, &this->allocator);
            // 为执行器添加一个订阅者
            rclc_executor_add_subscription(&this->executor, &this->subscriber, &this->sub_msg, &Micro_ROS_t::callback_subscription_, ON_NEW_DATA);
            // 初始化LED
            // pinMode(LED_Pin, OUTPUT);
            
            // this->System_Status_Flag.ROS_Work_Flag = ROS_START_WORK;
        }
        /*
        * @brief  ROS回调函数
        * @param  *msgin 输入参数指针
        * @return 无
        */
        static void callback_subscription_(const void *msgin)
        {
            const car_interfaces__msg__Car *msg = (const car_interfaces__msg__Car *)msgin;
        }

        void Micro_Ros_Task()
        {
            digitalWrite(4, HIGH);
            uint32_t Counter1 = 0;
            while(true)
            {

                if (!rmw_uros_epoch_synchronized()) // 判断时间是否同步
                {
                    rmw_uros_sync_session(1); //  同步时间
                    continue;
                }
                rclc_executor_spin_some(&this->executor, RCL_MS_TO_NS(1));
                Serial.printf("Counter1 = %d\r\n",Counter1);
                Counter1++;
                vTaskDelay(1);
            }
        }
        
    private:
        rclc_executor_t executor;
        rclc_support_t support;
        rcl_allocator_t allocator;
        rcl_node_t node;
        // 声明话题订阅者
        rcl_subscription_t subscriber;
        // 声明消息文件
        car_interfaces__msg__Car sub_msg;

        const WIFI_Data_t Wifi_Data;
        uint32_t WiFi_DisCon_Time = 0;
};





#endif