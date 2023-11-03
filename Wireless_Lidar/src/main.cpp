#include <Arduino.h>
#include <lidar.hpp>

WIFI_Data_t Wifi_Input;

void setup() 
{
  Wifi_Input.Wifi_SSID = "Xiaomi_WIFI";

  Wifi_Input.Pass_Word = "12345678910";

  Wifi_Input.Host_Ip   = "192.168.31.197";

  Wifi_Input.Port      = 9999;

  lidar_t *L = new lidar_t(Wifi_Input,1);

}

void loop() 
{
  
  delay(10000);

}
