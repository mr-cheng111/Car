#include <Arduino.h>
#include "WiFi.h"
#include <MPU6050_light.h>
#include <U8g2lib.h>
#include <Wire.h>


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 6, /* data=*/ 7);   // ESP32 Thing, HW I2C with pin remapping

void drawLogo(void)
{
    u8g2.setFontMode(1);	// Transparent
    u8g2.setFontDirection(0);
    u8g2.setFont(u8g2_font_inb24_mf);
    u8g2.drawStr(0, 30, "U");
    
    u8g2.setFontDirection(1);
    u8g2.setFont(u8g2_font_inb30_mn);
    u8g2.drawStr(21,8,"8");
        
    u8g2.setFontDirection(0);
    u8g2.setFont(u8g2_font_inb24_mf);
    u8g2.drawStr(51,30,"g");
    u8g2.drawStr(67,30,"\xb2");
    
    u8g2.drawHLine(2, 35, 47);
    u8g2.drawHLine(3, 36, 47);
    u8g2.drawVLine(45, 32, 12);
    u8g2.drawVLine(46, 33, 12);
}

void drawURL(void)
{
#ifndef MINI_LOGO
  u8g2.setFont(u8g2_font_4x6_tr);
  if ( u8g2.getDisplayHeight() < 59 )
  {
    u8g2.drawStr(89,20,"github.com");
    u8g2.drawStr(73,29,"/olikraus/u8g2");
  }
  else
  {
    u8g2.drawStr(1,54,"github.com/olikraus/u8g2");
  }
#endif
}

MPU6050 mpu(Wire1);

void setup() 
{
  Serial.begin(115200);
  
  Wire1.setPins(42,41);
  Wire1.setClock(400000);
  Wire1.begin();
  
  byte status = mpu.begin();

  Serial.print(F("MPU6050 status: "));

  Serial.println(status);

  while(status!=0)
  { 
    Serial.printf("cpnnect error\r\n");
  } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));

  delay(1000);

  mpu.calcOffsets(true,true); // gyro and accelero

  Serial.println("Done!\n");

  u8g2.begin();



  
  
  
}
void loop() 
{
  /*put your main code here, to run repeatedly:*/
  u8g2.clearBuffer();
  drawLogo();
  drawURL();
  u8g2.sendBuffer();
  mpu.update();
  // u8g2.drawStr(90,20,"Temp:");
  Serial.printf("%f,%f,%f\n",mpu.getAngleX(),mpu.getAngleY(),mpu.getAngleZ());
  // delay(1000);
}
