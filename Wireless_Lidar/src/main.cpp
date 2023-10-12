#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include <lidar.hpp>

WIFI_Data_t Wifi_input;

char Data[58*2] = {'\0'};
uint32_t Counter = 0;
int a = 0;

#define BUF_SIZE				(1024)
#define RD_BUF_SIZE 		(BUF_SIZE)
 
 
uart_event_t  uart0_event;
QueueHandle_t	uart0_queue;


void uart_event_handle(uart_port_t uart_num, QueueHandle_t queue, uart_event_t *event);
 
void Get_Data();
void setup() 
{
  // uart_config_t	uart_config =
	// {
	// 	.baud_rate			= 230400,
	// 	.data_bits			= UART_DATA_8_BITS,
	// 	.parity 			  = UART_PARITY_DISABLE,
	// 	.stop_bits	    = UART_STOP_BITS_1,
	// 	.flow_ctrl			= UART_HW_FLOWCTRL_DISABLE
	// };
    
	// uart_param_config(UART_NUM_0, &uart_config);
 
	// uart_set_pin(UART_NUM_0, UART_PIN_NO_CHANGE,  UART_PIN_NO_CHANGE,  UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
 
	// uart_driver_install(UART_NUM_0, BUF_SIZE * 2, BUF_SIZE * 2, 20, &uart0_queue, 0);

  // uart_enable_intr_mask(UART_NUM_0,UART_BREAK);

	// uart_pattern_queue_reset(UART_NUM_0, 20);



  Serial.begin(230400);
  Serial.onReceive(Get_Data,true);
  pinMode(LED_Pin, OUTPUT);
  // Wifi_input.Wifi_SSID = "Mi10";
  // Wifi_input.Pass_Word = "12345678";
  // Wifi_input.Host_Ip   = "192.168.52.59";
  // Wifi_input.Port      = 9999;
  // lidar_t *L = new lidar_t(Wifi_input,1);
}

bool T = false;

void loop() 
{
    if(T == true)
    {
      digitalWrite(LED_Pin,LOW);
    }
    else
    {
      digitalWrite(LED_Pin,HIGH);
    }
  // Serial.printf("Counter : %d\r\n",Counter);
  // Counter ++;
  // a = Serial.available();
  // if(a > 2*58)
  // {
  //   Serial.readBytes(Data,a);
  //   // Serial.write(Data,1);
  //   Serial.printf("%d\r\n",a);
  //   memset(Data,0,1);
  // }
  delay(1);
  // memset(Data,0,58);
  // Serial.readBytes(Data,58);

}

// void serialEvent() 
// {
//   while (Serial.available()) 
//   {
//     // get the new byte:
//     char inChar = (char)Serial.read();
//     // add it to the inputString:
//     inputString += inChar;
//     // if the incoming character is a newline, set a flag
//     // so the main loop can do something about it:
//     if (inChar == '\n') {
//       stringComplete = true;
//     }
//   }
// }

uint16_t Data_Counter = 0;

void Get_Data()
{
  Data_Counter++;
  if(Data_Counter == 58*2)
  {
    Data_Counter = 0;
    Serial.readBytes(Data,58*2);
    Serial.write(Data,58*2);
    memset(Data,0,58*2);
    // if(Data[0][0]<<8|Data[0][1] == 0)
    // {
    
    // }
    // else if(Data[1][0]<<8|Data[1][1] == 0)
    // {
    //   Serial.readBytes(Data[1],58);
    // }
    // else
    // {
    //   Serial.readBytes(Data[2],58);
    // }

  }

}

