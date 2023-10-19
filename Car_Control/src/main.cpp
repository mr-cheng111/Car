#include <Arduino.h>
#include "Disp.hpp"
#include "Car_Control.hpp"
// #include "Data.hpp"
// put function declarations here:
WIFI_Data_t Wifi_input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  xMutexMPU6050 = xSemaphoreCreateMutex();
  Disp_t A;
  Wifi_input.Wifi_SSID = "Mi10";
  Wifi_input.Pass_Word = "12345678";
  Wifi_input.Host_Ip   = "192.168.124.59";
  Wifi_input.Port      = 8888;
  Car_t *L = new Car_t(Wifi_input,1<<8|2);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  vTaskDelay(100);
}

// put function definitions here:
