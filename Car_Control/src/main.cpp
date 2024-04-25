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

  Serial.printf("Setting Microros\r\n");
  Micro_ROS_t *B = new Micro_ROS_t(Wifi_input_);
  Serial.printf("Setting Car\r\n");
  Car_t *C = new Car_t(1,NULL,B,&Odom_Data_Processer_,&Wheel_L_Data_,&Wheel_R_Data_);
}

void loop() 
{
  delay(10000);
}
