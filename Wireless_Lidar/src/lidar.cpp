#include "../include/lidar.hpp"

lidar_t::lidar_t(WIFI_Data_t Wifi_Input,int Serial_Num) : Wifi_Data(Wifi_Input)
{
    this->System_Status_Flag.System_Status = SYSTEM_INIT;

    Ros_Serial_Init(Serial_Num);

    Wifi_Init(this->Wifi_Data,2000);
    
    Ros_Init();

    // 初始化LED
    pinMode(LED_Pin, OUTPUT);

    /**
     * @brief 创建一个任务在Core 0 上
     * microros_task    任务函数
     * "microros_task"  任务名称
     * 10240      任务占用内存大小
     * NULL         任务参数，为空
     * 1               任务优先级
     * NULL     任务Handle可以为空
     * 0                 内核编号
     */
    xTaskCreatePinnedToCore([](void*param)->void
                            {lidar_t *I = static_cast<lidar_t*>(param);
                             I->Micro_Ros_Task();},
                            "Micro_Ros_Task", 
                            100*1024, 
                            this, 
                            0, 
                            NULL, 
                            0);
    /**
     * @brief 创建一个任务在Core 0 上
     * Lidar_Data_Task    任务函数
     * "Lidar_Data_Task"  任务名称
     * 1024      任务占用内存大小
     * this         任务参数，为空
     * 1               任务优先级
     * NULL     任务Handle可以为空
     * 0                 内核编号
     */
    xTaskCreatePinnedToCore([](void*param)->void
                            {lidar_t *I = static_cast<lidar_t*>(param);
                             I->Lidar_Data_Task();},
                            "Lidar_Data_Task", 
                            20*1024, 
                            this, 
                            0, 
                            NULL, 
                            1);
    /**
     * @brief 创建一个任务在Core 1 上
     * System_Monitor_Task    任务函数
     * "System_Monitor_Task"  任务名称
     * 1024      任务占用内存大小
     * this         任务参数，为空
     * 1               任务优先级
     * NULL     任务Handle可以为空
     * 0                 内核编号
     */
    xTaskCreatePinnedToCore([](void*param)->void
                            {lidar_t *I = static_cast<lidar_t*>(param);
                             I->System_Monitor_Task();},
                            "System_Monitor_Task", 
                            10*1024, 
                            this, 
                            1, 
                            NULL, 
                            1);
}

void lidar_t::Ros_Init()
{
    // 初始化内存分配器
    this->allocator = rcl_get_default_allocator();
    // 创建初始化选项
    rclc_support_init(&this->support, 0, NULL, &this->allocator);
    // 创建节点 microros_wifi
    rclc_node_init_default(&this->pubnode, "microros_wifi", "", &this->support);
    //定义一个话题发布者
    rclc_publisher_init_default(
        &this->publisher,
        &this->pubnode,
        ROSIDL_GET_MSG_TYPE_SUPPORT(wireless_lidar, msg, LidarData),
        "/Scan");

    // 创建执行器
    rclc_executor_init(&this->executor, &this->support.context, 1, &this->allocator);

    memset((void*)&this->pub_msg,0,sizeof(this->pub_msg));
    
    this->System_Status_Flag.ROS_Work_Flag = true;
}

void lidar_t::Wifi_Init(const WIFI_Data_t Wifi_Input,const uint16_t Wait_Time)
{
    // 设置通过WIFI进行MicroROS通信
    IPAddress agent_ip;
    agent_ip.fromString(Wifi_Input.Host_Ip.c_str());

    char* Wifi_Data_Temp = new char[Wifi_Input.Wifi_SSID.length() + 1];  // 额外空间用于存储字符串的结束符 '\0'  
    strcpy(Wifi_Data_Temp, Wifi_Input.Wifi_SSID.c_str());
    
    char* Pass_Word_Temp = new char[Wifi_Input.Pass_Word.length() + 1];  // 额外空间用于存储字符串的结束符 '\0'  
    strcpy(Pass_Word_Temp, Wifi_Input.Pass_Word.c_str());

    // 设置wifi名称，密码，电脑IP,端口号
    set_microros_wifi_transports(Wifi_Data_Temp, Pass_Word_Temp, agent_ip, Wifi_Input.Port);

    delay(Wait_Time);

    delete[] Wifi_Data_Temp;
    delete[] Pass_Word_Temp;

    this->System_Status_Flag.Wifi_Work_Flag = true;
}

void lidar_t::Ros_Serial_Init(int Serial_Num,int Baud)
{
    switch(Serial_Num)
    {
        case 0:this->Lidar_Serial = &Serial1;break;
        case 1:this->Lidar_Serial = &Serial1;break;
        case 2:this->Lidar_Serial = &Serial2;break;
        default :this->Lidar_Serial = &Serial1;break;
    }
    this->Lidar_Serial->begin(Baud);
    this->Lidar_Serial->setPins(15,16,-1,-1);
    this->Lidar_Serial->setRxBufferSize(58);
    this->Lidar_Serial->setTxBufferSize(1024);
    

    /*
     *设置系统调试串口
     */
    this->System_Serial = &Serial1;
    this->System_Serial->begin(115200);

    this->System_Status_Flag.Serial_Work_Flag = 1;
}

void lidar_t::Ros_Serial_Init(int Serial_Num)
{
    /*
     *设置雷达串口
     */
    switch(Serial_Num)
    {
        // case 0:this->Lidar_Serial = &Serial;break;
        case 1:this->Lidar_Serial = &Serial;break;
        case 2:this->Lidar_Serial = &Serial2;break;
        // default :this->Lidar_Serial = &Serial;break;
    }
    this->Lidar_Serial->begin(230400);
    this->Lidar_Serial->setPins(15,16,-1,-1);
    this->Lidar_Serial->setRxBufferSize(58);
    this->Lidar_Serial->setTxBufferSize(1024);
    

        //this->Lidar_Serial->onReceive(this->Usart_Callback_,0);

    /*
     *设置系统调试串口
     */
    this->System_Serial = &Serial1;
    this->System_Serial->begin(115200);

    memset((void *)&this->Lidar_Rx_Buffer,0,sizeof(this->Lidar_Rx_Buffer));

    this->System_Status_Flag.Serial_Work_Flag = true;
}

