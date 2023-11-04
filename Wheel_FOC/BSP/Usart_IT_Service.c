#include "Usart_IT_Service.h"

#define user_usart huart1

#define Buffer_Length 32

uint8_t UART_Data[Buffer_Length];
MOTOR_Set_t Motor_Set_Data;

void Usart_Init(void)
{
	HAL_UART_Receive_DMA(&user_usart, UART_Data, Buffer_Length);
}






void Usart_IT_Service(void)
{
		if(__HAL_UART_GET_FLAG(&user_usart, UART_FLAG_IDLE) != RESET)
	{
		__HAL_UART_CLEAR_IDLEFLAG(&user_usart);	
			
		HAL_UART_AbortReceive(&user_usart);//¹Ø±Õdma
		
		for(uint8_t i = 0; i < Buffer_Length ; i ++)
		{
			if(UART_Data[i] == 0xAF)
			{
				uint8_t Temp_Data = 0;
				for(uint8_t j = 0 ; j < 10 ; j++)
				{
					 Temp_Data = UART_Data[i + j];
				}
				if(Temp_Data == UART_Data[i + 10])
				{
					memcpy((void*)&Motor_Set_Data , (void *)UART_Data[i] , 10);
					memset(UART_Data[i],0,Buffer_Length);
				}
			}
		}
	}
    //ÖØÆôDMA
	HAL_UART_Receive_DMA(&user_usart, UART_Data, Buffer_Length);
}




