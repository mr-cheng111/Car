#ifndef UART_IT_SERVICE
#define UART_IT_SERVICE

#include "usart.h"
#include "string.h"
void Usart_IT_Service(void);

typedef struct 
{
	uint8_t Header;
	float Set_Speed;
	float Set_Position;
	uint8_t Tail;
}MOTOR_Set_t;

extern MOTOR_Set_t Motor_Set_Data;


#endif