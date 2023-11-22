/*Created by Ajay Kumar (ajaybnl@gmail.com) Youtube: Ajay Sudhera
   
   Check My Yourtube Video for How to View UDP Graph :
  https://www.youtube.com/watch?v=ssz-ebdW3ss

   This example shows how to connect and send data to you PC (To TelemetryViewer)
*/
#include <Arduino.h>
#include "esp_wifi.h"
#include <WiFi.h>
#include <WiFiUdp.h>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

const char* ssid = "Xiaomi_WIFI";
const char* password = "12345678910";

//SET YOUR PC IP ADDRESS (YOU GOT FROM MODEM)
IPAddress ip(192, 168, 31, 197);

//SET PORTS TO CONNECT
int printport = 8080;

int chartport = 8081;
char Data[58];
char trash[256];
struct sockaddr_in recipient;

WiFiUDP Udp;

WiFiClient Tcp;

uint32_t D = 0;

#define LED_Pin 4

OnReceiveCb Serial_Get_Data(void)
{
    while(true)
    {
      // Serial.printf("%d\n",Serial1.available());
      if(Serial1.available() == 58)
      {
        Serial1.read(Data,58);
        digitalWrite(LED_Pin,HIGH);
        Tcp.write(Data,58);
      }
      if(Serial1.available() > 58)
      {
        
        Serial1.printf("Error Too Much Data\n");
        Serial1.read(trash,Serial1.available());
      }
      digitalWrite(LED_Pin,LOW);
    }

}

void Send_Data(void *param);

void setup()
{
  Serial.begin(230400);

  pinMode(LED_Pin,OUTPUT);

  esp_wifi_set_protocol(WIFI_IF_AP, WIFI_PROTOCOL_11G|WIFI_PROTOCOL_11N);
  WiFi.setTxPower(WIFI_POWER_19_5dBm);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("WiFi Connected\n");
  while(!Tcp.connect(ip,8080))
  {
    delay(500);
    Serial.print(".");   
  }

  Serial1.begin(230400);
  Serial1.setPins(13,12);
  Serial1.onReceive(Serial_Get_Data(),true);
  Serial1.setRxTimeout(10);
}

uint8_t C = 0;
uint8_t data = 0;
void loop()
{
  delay(1);
}

