#ifndef IT_Server
#define IT_Server


#include "main.h"
#include "tim.h"
#include "stm32f1xx_hal_tim.h"

#include "TIM_IT_Server.h"
#include "BSP_LED.h"

void TIM_Init(void);
void TIM1_IRQServer(void);
void TIM2_IRQServer(void);
void TIM3_IRQServer(void);
void TIM4_IRQServer(void);

extern uint32_t Counter1,Counter3,Counter4;
#endif