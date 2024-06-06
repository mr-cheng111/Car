#ifndef ODOM_DATA_PROCESS
#define ODOM_DATA_PROCESS
#include <Arduino.h>

#define pi 3.14159265358979323846f

typedef struct 
{
    uint8_t Cmd_Flag;
    uint8_t Motor_Temp;
    int16_t Motor_Iq_Current;
    int16_t Motor_Speed;
    uint8_t Motor_Angle;
    int64_t Last_Update_Time;
    int64_t Current_Time;
}Motor_Data_t;

typedef struct
{
    float w;
    float x;
    float y;
    float z;
} quaternion_t;
/**
 * @brief 里程计相关信息，根据轮子速度信息和运动模型推算而来
 *
 */
typedef struct
{
    float x;                 // 坐标x
    float y;                 // 坐标y
    float yaw;               // yaw
    quaternion_t quaternion; // 姿态四元数
    float linear_speed;      // 线速度
    float angular_speed;     // 角速度
} odom_t;

class Odom_Data_Process_t
{
private:
    
    volatile int16_t *Wheel_L_Speed;              // 左轮数据
    volatile int16_t *Wheel_R_Speed;              // 右轮数据
    odom_t odom_;                       // 里程计数据
    float wheel_distance_ = 101.5;      // 轮子间距，单位：mm
    float wheel_diameter_ = 64;         // 轮子外直径，单位：mm
    float wheel_radius_ = 32;         // 轮子外直径，单位：mm
    uint64_t current_update_time_ = 0;   // 上次计算时间，单位：us
    uint64_t last_update_time_ = 0;      // 本次计算时间，单位：us
    uint32_t dt = 0;                     // 两次函数调用之间的时间间隔，单位：us

    float robot_linear_velocity = 0;     // 机器人线速度；
    float robot_angular_velocity = 0;    // 机器人角速度
    
public:
    Odom_Data_Process_t(volatile int16_t *Wheel_L_p = NULL,  volatile int16_t *Wheel_R_p = NULL);
    ~Odom_Data_Process_t();
    void Update_Odom();
    void Robot_Inverse(float linear_speed, float angular_speed, int32_t &out_wheel_L_speed, int32_t &out_wheel_R_speed);
    odom_t &odom();
    void Get_Robot_forward_speed(float Wheel_Linear_L, float Wheel_Linear_R, float &linear_speed, float &angular_speed);
    void Euler2Quaternion(float roll, float pitch, float yaw, quaternion_t &q);
    void TransAngleInPI(float angle, float &out_angle);
};




#endif