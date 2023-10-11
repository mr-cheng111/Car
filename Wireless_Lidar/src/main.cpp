#include <Arduino.h>

// #include <lidar.hpp>

// WIFI_Data_t Wifi_input;


uint32_t Counter = 0;
void setup() 
{
  Serial.begin(115200);
  
  // Wifi_input.Wifi_SSID = "Mi10";
  // Wifi_input.Pass_Word ="12345678";
  // Wifi_input.Host_Ip   = "192.168.235.59";
  // Wifi_input.Port      = 8888;
  // lidar_t *L = new lidar_t(Wifi_input,0);
}

void loop() 
{
  
  Serial.printf("AAA");
  Counter ++;
  delay(1000);
}

