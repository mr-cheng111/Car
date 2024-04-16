#ifndef MICRO_ROS_TASK
#define MICRO_ROS_TASK

#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <string>
#include <geometry_msgs/msg/twist.h>
#include <sensor_msgs/msg/imu.h>
#include <nav_msgs/msg/odometry.h>

#include <micro_ros_utilities/string_utilities.h>

#include "Data.hpp"

class Micro_ROS_t
{
    public:
        Micro_ROS_t(WIFI_Data_t Wifi_Input) : Wifi_Data(Wifi_Input)
        {
            Wifi_Init(this->Wifi_Data,10);
        
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
                                    20, 
                                    NULL, 
                                    0);
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


            //定义一个订阅者
            rclc_subscription_init_default(
            &this->subscriber,
            &this->node,
            ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
            "cmd_vel");
     
            // 添加Imu数据发布者
            rclc_publisher_init_best_effort(
            &this->publisher_Imu,
            &this->node,
            ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Imu),
            "imu");

            // 添加轮式编码器节点
            rclc_publisher_init_best_effort(
            &this->publisher_Odom,
            &this->node,
            ROSIDL_GET_MSG_TYPE_SUPPORT(nav_msgs, msg, Odometry),
            "odom");

            // 创建执行器
            rclc_executor_init(&this->executor, &this->support.context, 1, &this->allocator);
            rclc_executor_add_subscription(&this->executor, &this->subscriber, &this->sub_msg, &Micro_ROS_t::callback_subscription_, ON_NEW_DATA);

            // 初始化Imu数据
            Imu_msg.header.frame_id = micro_ros_string_utilities_set(Imu_msg.header.frame_id, "base_link"); // 初始化消息内容
            Imu_msg.angular_velocity_covariance[0] = 1029.40872336;
            Imu_msg.angular_velocity_covariance[4] = 764.94836929;
            Imu_msg.angular_velocity_covariance[8] = 1146.0459208899997;

            Odom_msg.header.frame_id = micro_ros_string_utilities_set(Odom_msg.header.frame_id, "base_link"); // 初始化消息内容
        }
        /*
        * @brief  ROS回调函数
        * @param  *msgin 输入参数指针
        * @return 无
        */
        static void callback_subscription_(const void *msgin)
        {
            const geometry_msgs__msg__Twist *msg = (const geometry_msgs__msg__Twist *)msgin;
            Car_control.Forward_Speed = msg->linear.x;
            Car_control.Spinning_Speed = msg->angular.z;
        }

        void Micro_Ros_Task()
        {
            LED.LED_Work(LED_COLOR::RED,0.4);
            uint64_t Counter1 = 0;
            while(true)
            {
                vTaskDelay(1);
                Counter1++;
                if (!rmw_uros_epoch_synchronized()) // 判断时间是否同步
                {
                    rmw_uros_sync_session(1); //  同步时间
                    continue;
                }
                rcl_ret = rcl_publish(&this->publisher_Imu, &Imu_msg, NULL);
                rcl_ret = rcl_publish(&this->publisher_Odom, &Odom_msg, NULL);
                rclc_executor_spin_some(&this->executor, 1);
                Serial.printf("Micro_Ros_Task Counter = %lld\r\n",Counter1);
            }
        }
    
    private:
        rclc_executor_t executor;
        rclc_support_t support;
        rcl_allocator_t allocator;
        rcl_node_t node;
        // 声明话题订阅者
        rcl_subscription_t subscriber;
        rcl_publisher_t publisher_Imu; // 定义Imu话题发布者
        rcl_publisher_t publisher_Odom;// 声明话题发布者
        rcl_ret_t rcl_ret;
        // 声明消息文件
        car_interfaces__msg__Car sub_msg;

        const WIFI_Data_t Wifi_Data;
        uint32_t WiFi_DisCon_Time = 0;
};





#endif