// #include <Arduino.h>
// #include <micro_ros_platformio.h>
// #include <WiFi.h>
// #include <rcl/rcl.h>
// #include <rclc/rclc.h>
// #include <rclc/executor.h>
// #include <std_msgs/msg/int32.h>
// #include <string>
// #include <Ticker.h>

// #include <sensor_msgs/msg/laser_scan.h>
// #include <micro_ros_utilities/string_utilities.h>

// enum SYSTEM_FLAG
// {
//     SYSTEM_INIT = 0,
//     SYSTEM_NORMAL,
//     SYSTEM_STOP
// };

// typedef struct
// {   
//     uint32_t System_Status;
//     bool Wifi_Work_Flag;
//     bool ROS_Work_Flag;
//     bool Sensor_Work_Flag;
//     bool Serial_Work_Flag;
//     bool System_Time_Sync;

// }System_Status_t;

// typedef struct 
// {
//     String Wifi_SSID;
//     String Pass_Word;
//     String Host_Ip;
//     uint16_t Port;
// }WIFI_Data_t;

// using namespace std;

// #define LED_Pin 4

// class lidar_t
// {
// public:
//     HardwareSerial *Lidar_Serial;
//     HardwareSerial *System_Serial;
//     System_Status_t System_Status_Flag;
// private:
//     rclc_executor_t executor;
//     rclc_support_t support;
//     rcl_allocator_t allocator;
//     rcl_node_t pubnode;

//     //声明话题发布者
//     rcl_publisher_t publisher;           // 声明话题发布者
//     sensor_msgs__msg__LaserScan pub_msg; // 声明消息文件

//     uint8_t Lidar_Rx_Buffer[58*4];

//     const WIFI_Data_t Wifi_Data;

// public:
//     lidar_t(WIFI_Data_t Wifi_Input,int Serial_Num);

//     void Micro_Ros_Task()
//     {
        
//         digitalWrite(LED_Pin, HIGH);
//         this->pub_msg.header.frame_id = micro_ros_string_utilities_set(pub_msg.header.frame_id, "laser"); // 初始化消息内容
        
//         //初始化雷达帧信息的递增角度、最远距离和最近距离。
//         this->pub_msg.angle_increment = 0.8 / 180 * PI;
//         this->pub_msg.range_min = 0.03;
//         this->pub_msg.range_max = 12.0;
//         while(true)
//         {
//             if (!rmw_uros_epoch_synchronized()) // 判断时间是否同步
//             {
//             rmw_uros_sync_session(1000); //  同步时间
//             continue;
//             }
//             this->System_Status_Flag.System_Time_Sync = true;
//             rclc_executor_spin_some(&this->executor, RCL_MS_TO_NS(1));
//         }
//     }

//     void Lidar_Data_Task()
//     {
//         while(true)
//         {
//             if(this->System_Status_Flag.Wifi_Work_Flag)
//             {
//                 if(!(this->Lidar_Serial->available() % 58))
//                 {
//                     this->System_Status_Flag.Sensor_Work_Flag = 1;
//                     this->Lidar_Serial->read(this->Lidar_Rx_Buffer,58);
//                 }
//                 rcl_publish(&publisher, &pub_msg, NULL);
//             }
//             delay(1);
//         }
//     }
//     void System_Monitor_Task()
//     {
//         while(true)
//         {
//             if(WiFi.status() != WL_CONNECTED)
//             {
//                 this->System_Status_Flag.Wifi_Work_Flag = false;
//             }
//             // if();
//             delay(1);
//         }
//     }

//     void Ros_Init();

//     void Wifi_Init(const WIFI_Data_t Wifi_Input,const uint16_t Wait_Time);
                    
//     void Ros_Serial_Init(const int Serial_Num);

//     void Ros_Serial_Init(int Serial_Num,int Baud);

// };
