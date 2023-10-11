#include <Arduino.h>

#include <lidar.hpp>

WIFI_Data_t Wifi_input;


uint32_t Counter = 0;
void setup() 
{
  Serial.begin(115200);
  
  Wifi_input.Wifi_SSID = "Xiaomi_WIFI";
  Wifi_input.Pass_Word = "12345678910";
  Wifi_input.Host_Ip   = "192.168.31.197";
  Wifi_input.Port      = 8888;
  lidar_t *L = new lidar_t(Wifi_input,1);
}

void loop() 
{
  
  Serial.printf("Counter : %d\r\n",Counter);
  Counter ++;
  delay(1000);

}

