#ifndef CAR_CONTROL
#define CAR_CONTROL

#include <Arduino.h>
#include "WiFi.h"
#include <MPU6050_light.h>
#include <U8g2lib.h>
#include <Wire.h>

using namespace std;

struct 
{


};





class Car_Control_t
{
public :
    Car_Control_t(TwoWire * _wire,uint8_t Left_Motor,uint8_t Right_Motor);
    void Car_Control_Task(void);
    void OnRecive_L_Motor(uint8_t L_Motor);
    void OnRecive_R_Motor(uint8_t R_Motor);
    
private:
    TwoWire *Mpu_Wire;
    TwoWire *Disp_Wire;


};

























#endif