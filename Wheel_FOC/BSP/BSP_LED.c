#include "BSP_LED.h"
uint8_t LedWorkMode = 0;

enum
{
	INIT = 0,
	WORKING,
	STOP_WORKING,
	DEBUGING
	
}LED_STATE;

void LED_Init(void)
{
	HAL_GPIO_WritePin(LED_GPIO_Port, LED2_Pin|LED3_Pin, GPIO_PIN_RESET);
}

void Init_Lighting(uint8_t LED2,uint8_t LED3)
{
	if(LED2 == 0)
	LED_GPIO_Port->BSRR = ((LED_GPIO_Port->ODR & LED2_Pin) << 16u) | (~LED_GPIO_Port->ODR & LED2_Pin);
	if(LED3 == 0)
	LED_GPIO_Port->BSRR = ((LED_GPIO_Port->ODR & LED3_Pin) << 16u) | (~LED_GPIO_Port->ODR & LED3_Pin);
}

void Nomal_Lighting(uint8_t LED)
{
	if(LED == 0)
	LED_GPIO_Port->BSRR = (LED2_Pin|LED3_Pin) << 16u;
	else 
	LED_GPIO_Port->BSRR = LED2_Pin|LED3_Pin;
		
}


void LED_Work_State(uint8_t State,uint8_t Counter)
{
	switch(State)
	{
		case INIT : 			Init_Lighting(Counter%5000,Counter%10000);break;
		case WORKING : 		Init_Lighting(Counter%10000,Counter%10000);break;
		case STOP_WORKING:Nomal_Lighting(0);break;
		case DEBUGING : 	Nomal_Lighting(Counter%1000);break;
		default : 				Init_Lighting(Counter%2500,Counter%2500);break;
	}
}



