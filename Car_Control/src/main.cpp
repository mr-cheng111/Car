#include <Arduino.h>
//#include "Disp.hpp"
#include "Car_Control.hpp"
#include "ROS.hpp"
#include "Data.hpp"

#include "BMI088.h"
#include <cstdint>


// hw_timer_t * timer = NULL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
  Imu.begin();
  Imu.setRange(Bmi088::ACCEL_RANGE_6G,Bmi088::GYRO_RANGE_500DPS);
  Imu.setOdr(Bmi088::ODR_2000HZ);

  Serial.printf("Setting Microros\r\n");
  //Micro_ROS_t *B = new Micro_ROS_t(Wifi_input);
  Serial.printf("Setting Car\r\n");
  Car_t *C = new Car_t(1,NULL);
}

void loop() 
{
  delay(10000);
}

