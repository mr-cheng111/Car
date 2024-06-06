#include <Arduino.h>
#include "Odom_Data_Process.hpp"

Odom_Data_Process_t::Odom_Data_Process_t(volatile int16_t *Wheel_L_p, volatile int16_t *Wheel_R_p)
{
    this->Wheel_L_Speed = Wheel_L_p;
    this->Wheel_R_Speed = Wheel_R_p;
    if(this->Wheel_L_Speed == NULL || this->Wheel_R_Speed == NULL)
    {
        while(1)
        {
            delay(1000);
            Serial.printf("Init error: Invalid MOTOR Data Pointer!\r\n");
        }
    }
}
//更新里程计数据
void Odom_Data_Process_t::Update_Odom()
{
    float L_Wheel_Angular_Speed = *this->Wheel_L_Speed * pi / 180.0f;//输入dps，转换为rad/s
    float R_Wheel_Angular_Speed =-*this->Wheel_R_Speed * pi / 180.0f;//输入dps，转换为rad/s

    float Wheel_L_Linear_Speed = L_Wheel_Angular_Speed * wheel_radius_;//左轮的线速度，单位是：mm/s
    float Wheel_R_Linear_Speed = R_Wheel_Angular_Speed * wheel_radius_;//右轮的线速度，单位是：mm/s

    current_update_time_ = micros();//获取当前时间，单位：us
    dt = current_update_time_ - last_update_time_;
    last_update_time_ = current_update_time_;

    static float linear_speed, angular_speed;
    float dt_s = (float)(dt / 1000) / 1000;
    
    // 计算机器人的线速度和角速度。
    this->Get_Robot_forward_speed(Wheel_L_Linear_Speed, Wheel_R_Linear_Speed, linear_speed, angular_speed);
    
    // 将计算出的角速度和线速度存储到 odom_ 结构体中。根据角速度和时间间隔，更新机器人的姿态信息 odom_.yaw
    odom_.angular_speed = angular_speed;        // 旋转角速度为rad/s
    odom_.linear_speed = linear_speed / 1000;   // 将线速度从mm/s 转为 m/s
    
    odom_.yaw += odom_.angular_speed * dt_s;

    // 将角度值 odom_.yaw 转换到 -π 到 π 的范围内
    TransAngleInPI(odom_.yaw, odom_.yaw);

    //Serial.printf("Linear Speed = %f, Angular Speed = %f\r\n",linear_speed,angular_speed);
    
    /*更新x和y轴上移动的距离*/
    // 计算机器人在 x 和 y 轴上移动的距离 delta_distance，单位为米
    float delta_distance = odom_.linear_speed * dt_s; // 单位m
    // 根据机器人的角度值 odom_.yaw 和移动距离 delta_distance，更新机器人的位置信息 odom_.x 和 odom_.y
    odom_.x += delta_distance * std::cos(odom_.yaw);
    odom_.y += delta_distance * std::sin(odom_.yaw);
}
//机器人逆运动学解算，输入分别为线速度(mm/s)、角速度(rad/s)，输出为左右轮子的旋转速度(0.01dps)
void Odom_Data_Process_t::Robot_Inverse(float linear_speed, float angular_speed, int32_t &out_wheel_L_speed, int32_t &out_wheel_R_speed)
{
    //此时速度单位为0.01dps
    out_wheel_L_speed = (linear_speed / wheel_radius_ - angular_speed * wheel_distance_ / wheel_diameter_) * 18000 / pi ;
    out_wheel_R_speed = -(linear_speed / wheel_radius_ + angular_speed * wheel_distance_ / wheel_diameter_) * 18000 / pi;
}
// 用于获取机器人的位置和姿态信息
odom_t &Odom_Data_Process_t::odom()
{
    // 调用 Euler2Quaternion 函数，将机器人的欧拉角 yaw 转换为四元数 quaternion。
    Euler2Quaternion(0, 0, odom_.yaw, odom_.quaternion);
    // 返回机器人的位置和姿态信息 odom_
    return odom_;
}
//将机器人的左右轮速(rad/s)作为输入,输出为机器人线速度(mm/s)与机器人角速度(rad/s)
void Odom_Data_Process_t::Get_Robot_forward_speed(float Wheel_Linear_L, float Wheel_Linear_R, float &linear_speed, float &angular_speed)
{
    //返回的linear_speed单位是mm/s
    //返回的angular_speed单位是rad/s
    linear_speed = (Wheel_Linear_R + Wheel_Linear_L) / 2.0f;
    angular_speed = (Wheel_Linear_R - Wheel_Linear_L) / wheel_distance_;
}
//将pitch、roll、yaw数据转换为四元数
void Odom_Data_Process_t::Euler2Quaternion(float roll, float pitch, float yaw, quaternion_t &q)
{
    // 传入机器人的欧拉角 roll、pitch 和 yaw。
    // 计算欧拉角的 sin 和 cos 值，分别保存在 cr、sr、cy、sy、cp、sp 六个变量中    

    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    // 计算出四元数的四个分量 q.w、q.x、q.y、q.z
    q.w = cy * cp * cr + sy * sp * sr;
    q.x = cy * cp * sr - sy * sp * cr;
    q.y = sy * cp * sr + cy * sp * cr;
    q.z = sy * cp * cr - cy * sp * sr;
}
//将机器人的Yaw角度归一化到-PI ~ PI
void Odom_Data_Process_t::TransAngleInPI(float angle, float &out_angle)
{
    // 如果 angle 大于 π，则将 out_angle 减去 2π
    if (angle > PI)
    {
        out_angle -= 2 * PI;
    }
    // 如果 angle 小于 -π，则将 out_angle 加上 2π
    else if (angle < -PI)
    {
        out_angle += 2 * PI;
    }
}

Odom_Data_Process_t::~Odom_Data_Process_t(void)
{
    return ;
}