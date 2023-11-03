#ifndef BSP_LED
#define BSP_LED


#include "main.h"
#include "gpio.h"
#include "TIM_IT_Server.h"


void LED_Init(void);
void LED_Work_State(uint8_t State,uint8_t Counter);
extern uint8_t LedWorkMode;
#endif