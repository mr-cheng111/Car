#include <Arduino.h>
//#include "Disp.hpp"
#include "Car_Control.hpp"
#include "Kalman_IMU.hpp"
#include "ROS.hpp"
#include "Data.hpp"
// put function declarations here:
WIFI_Data_t Wifi_input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
  xMutexImu = xSemaphoreCreateMutex();
  //Disp_t A;
  Wifi_input.Wifi_SSID = "Mi10";
  Wifi_input.Pass_Word = "12345678";
  Wifi_input.Host_Ip   = "192.168.124.59";
  Wifi_input.Port      = 8888;

  //Micro_ROS_t *B = new Micro_ROS_t(Wifi_input);

  Car_t *L = new Car_t(1<<8|2);
  
  // put function definitions here:

    // 初始化IMU参数和噪声水平
    // float dt = 0.01;  // 时间步长
    // float processNoise = 0.001;  // 过程噪声水平
    // float measurementNoise = 0.01;  // 测量噪声水平

    // // 创建Kalman Filter对象
    // KalmanFilter kf(dt, processNoise, measurementNoise);

    // // 模拟IMU数据
    // Eigen::Vector3f gyro(0.1, 0.2, 0.3);  // 角速度值
    // Eigen::Vector3f angle(0.0, 0.0, 0.0);  // 角度值

    // // 运行Kalman Filter来估计姿态角
    // for (int i = 0; i < 100; ++i) {
    //     // 预测步骤
    //     kf.predict(gyro);

    //     // 更新步骤
    //     kf.update(angle);

    //     // 获取估计的姿态角
    //     Eigen::Vector3f estimatedAngles = kf.getStateAngles();

    //     // 更新IMU数据（此处的示例为固定值，实际应根据实际传感器数据更新）
    //     gyro += Eigen::Vector3f(0.01, 0.02, 0.03);
    //     angle += Eigen::Vector3f(0.1, 0.2, 0.3);
    // }
}

void loop() {
  // put your main code here, to run repeatedly:
   vTaskDelay(10000);
  
}

