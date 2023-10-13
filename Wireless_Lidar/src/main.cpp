#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include <lidar.hpp>
#include <iostream>
#include <queue>

WIFI_Data_t Wifi_input;
uint8_t Temp_Data[256];
std::queue<uint8_t> fifoQueue; // 定义一个整型的FIFO队列
 
void Get_Data();
void setup() 
{
  Serial.begin(230400);
  Serial.setPins(44,43);
  Serial.onReceive(Get_Data);
  pinMode(LED_Pin, OUTPUT);
  Wifi_input.Wifi_SSID = "Mi10";
  Wifi_input.Pass_Word = "12345678";
  Wifi_input.Host_Ip   = "192.168.52.59";
  Wifi_input.Port      = 9999;
  lidar_t *L = new lidar_t(Wifi_input,1);
}

bool T = false;
uint8_t Data_Length = 0;
uint32_t Counter = 0;
void loop() 
{
}
void Get_Data()
{
    Serial.printf("Got %d bytes on Serial to read\n", Serial.available());
    uint8_t i = 0;
    while(Serial.available())
    {
      *(Temp_Data + i) = Serial.read();
      i++;
    }
    Serial.write(Temp_Data,i);
    i=0;
}

