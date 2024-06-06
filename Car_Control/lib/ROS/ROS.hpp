#ifndef MICRO_ROS_TASK
#define MICRO_ROS_TASK

#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <string>
#include <std_msgs/msg/int32.h>
#include <geometry_msgs/msg/twist.h>
#include <sensor_msgs/msg/imu.h>
#include <nav_msgs/msg/odometry.h>
#include "MahonyAHRS.h"
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
                                    10*1024, 
                                    this, 
                                    20, 
                                    NULL, 
                                    0);
        }
        void Wifi_Init(const WIFI_Data_t Wifi_Input,const uint16_t Wait_Time)
        {
            // 设置通过WIFI进行MicroROS通信
            Serial.printf(" Wifi Init Start!\r\n");

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

            Serial.printf(" Wifi Init Finish!\r\n");

            delay(Wait_Time);

            delete[] Wifi_Data_Temp;

            delete[] Pass_Word_Temp;
        
        }
        void Ros_Init()
        {
            // this->System_Status_Flag.ROS_Work_Flag = ROS_INIT;
            // 初始化内存分配器
            Serial.printf(" ROS Init Start!\r\n");
            Allocator_ = rcl_get_default_allocator();

            this->ROS_Allocator = &Allocator_;
            this->ROS_Support   = &Support_;
            this->ROS_Executor  = &Executor_;
            this->ROS_Node      = &Node_;
            this->Cmd_Vel_Sub   = &Subscriber_;
            this->Pub_Imu       = &Publisher_Imu_;
            this->Pub_Odom      = &Publisher_Odom_;
            this->RCL_Ret       = &Rcl_Ret_;
            this->ROS_Timer     = &Timer_;

            // 创建初始化选项
            rclc_support_init(this->ROS_Support, 0, NULL, this->ROS_Allocator);
            // 创建节点 microros_wifi
            rclc_node_init_default(this->ROS_Node, "microros_wifi_car", "", this->ROS_Support);

            //定义一个订阅者
            rclc_subscription_init_best_effort(
            this->Cmd_Vel_Sub,
            this->ROS_Node,
            ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
            "cmd_vel");
     
            // 添加Imu数据发布者
            rclc_publisher_init_best_effort(
            this->Pub_Imu,
            this->ROS_Node,
            ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, Imu),
            "imu");

            // 添加轮式编码器节点
            rclc_publisher_init_best_effort(
            this->Pub_Odom,
            this->ROS_Node,
            ROSIDL_GET_MSG_TYPE_SUPPORT(nav_msgs, msg, Odometry),
            "odom_raw");

            // 创建执行器
            rclc_timer_init_default(this->ROS_Timer, this->ROS_Support, RCL_MS_TO_NS(25), &Micro_ROS_t::timer_callback_subscription_);

            rclc_executor_init(this->ROS_Executor, &this->ROS_Support->context, 2, this->ROS_Allocator);

            rclc_executor_add_subscription(this->ROS_Executor, this->Cmd_Vel_Sub, &this->sub_msg, &Micro_ROS_t::msg_callback_subscription_, ON_NEW_DATA);

            rclc_executor_add_timer(this->ROS_Executor, this->ROS_Timer);

            // 初始化Imu数据
            Imu_msg_.header.frame_id = micro_ros_string_utilities_set(Imu_msg_.header.frame_id, "imu"); // 初始化消息内容
            Imu_msg_.angular_velocity_covariance[0] = 1029.40872336;
            Imu_msg_.angular_velocity_covariance[4] = 764.94836929;
            Imu_msg_.angular_velocity_covariance[8] = 1146.0459208899997;

            Odom_msg_.header.frame_id = micro_ros_string_utilities_set(Odom_msg_.header.frame_id, "odom"); // 初始化消息内容
        }
        /*
        * @brief  ROS回调函数
        * @param  *msgin 输入参数指针
        * @return 无
        */
        static void msg_callback_subscription_(const void *msgin)
        {
            const geometry_msgs__msg__Twist *msg = (const geometry_msgs__msg__Twist *)msgin;
            Car_Control_.Forward_Speed = msg->linear.x;
            Car_Control_.Spinning_Speed = msg->angular.z;
            System_Status_Flag.Get_ROS_Control_Flag = 12;
            // Serial.printf("Speed = %f\r\n",Car_Control_.Forward_Speed);
        }

        /*
        * @brief  ROS回调函数
        * @param  *msgin 输入参数指针
        * @return 无
        */
        static void timer_callback_subscription_(rcl_timer_t *timer, int64_t last_call_time)
        {
            if (timer != NULL)
            {
                // 用于获取当前的时间戳，并将其存储在消息的头部中
                int64_t stamp = rmw_uros_epoch_millis();
                // 获取机器人的位置和速度信息，并将其存储在一个ROS消息（Odom_msg）中
                odom_t odom = Odom_Data_Processer_.odom();
                Odom_msg_.header.stamp.sec = static_cast<int32_t>(stamp / 1000); // 秒部分
                Odom_msg_.header.stamp.nanosec = static_cast<uint32_t>((stamp % 1000) * 1e6); // 纳秒部分
                Odom_msg_.pose.pose.position.x = odom.x;
                Odom_msg_.pose.pose.position.y = odom.y;

                Odom_msg_.pose.pose.orientation.w = odom.quaternion.w;
                Odom_msg_.pose.pose.orientation.x = odom.quaternion.x;
                Odom_msg_.pose.pose.orientation.y = odom.quaternion.y;
                Odom_msg_.pose.pose.orientation.z = odom.quaternion.z;

                Odom_msg_.twist.twist.linear.x = odom.linear_speed;
                Odom_msg_.twist.twist.angular.z = odom.angular_speed;
                Rcl_Ret_ = rcl_publish(&Publisher_Odom_, &Odom_msg_, NULL);


                Imu_.readSensor(&Imu_Data_);
                MahonyAHRSupdateIMU(q,Imu_Data_.gyroX,Imu_Data_.gyroY,Imu_Data_.gyroZ + 0.00520,Imu_Data_.accX,Imu_Data_.accY,Imu_Data_.accZ);

                Imu_msg_.header.stamp.sec = static_cast<int32_t>(stamp / 1000); // 秒部分
                Imu_msg_.header.stamp.nanosec = static_cast<uint32_t>((stamp % 1000) * 1e6); // 纳秒部分

                Imu_msg_.angular_velocity.x = Imu_Data_.gyroX;
                Imu_msg_.angular_velocity.y = Imu_Data_.gyroY;
                Imu_msg_.angular_velocity.z = Imu_Data_.gyroZ;

                Imu_msg_.linear_acceleration.x = Imu_Data_.accX;
                Imu_msg_.linear_acceleration.y = Imu_Data_.accY;
                Imu_msg_.linear_acceleration.z = Imu_Data_.accZ;
                
                Imu_msg_.orientation.w = q[0];
                Imu_msg_.orientation.x = q[1];
                Imu_msg_.orientation.y = q[2];
                Imu_msg_.orientation.z = q[3];
                

                Rcl_Ret_ = rcl_publish(&Publisher_Imu_, &Imu_msg_, NULL);

            }
        }

        void Micro_Ros_Task()
        {
            LED_.LED_Work(LED_COLOR::CYAN,0.4);
            uint64_t Counter1 = 0;
            while(true)
            {
                vTaskDelay(10);
                Counter1++;
                if (!rmw_uros_epoch_synchronized()) // 判断时间是否同步
                {
                    rmw_uros_sync_session(1); //  同步时间
                    continue;
                }
                rclc_executor_spin_some(this->ROS_Executor, RCL_MS_TO_NS(100));
            }
        }
    
    public:
        rclc_executor_t *ROS_Executor;
        rclc_support_t *ROS_Support;
        rcl_allocator_t *ROS_Allocator;
        rcl_node_t *ROS_Node;
        // 声明话题订阅者
        rcl_subscription_t *Cmd_Vel_Sub;
        rcl_publisher_t *Pub_Imu; // 定义Imu话题发布者
        rcl_publisher_t *Pub_Odom;// 声明话题发布者
        rcl_ret_t *RCL_Ret;
        rcl_timer_t *ROS_Timer;         // 用于在指定的时间间隔内执行回调函数
        // 声明消息文件
        geometry_msgs__msg__Twist sub_msg;
        //std_msgs__msg__Int32 sub_msg;
        const WIFI_Data_t Wifi_Data;
        uint32_t WiFi_DisCon_Time = 0;
};





#endif