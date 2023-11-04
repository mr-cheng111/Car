#include "TIM_IT_Server.h"
#include "BSP_ADC.h"
#include "BSP_MT6701.h"
void TIM_Init(void)
{
//  	TIM1->PSC = 71; // 72MHz/(71+1) = 1MHz
//	TIM1->ARR = 999; // 1MHz/(1+999) = 1KHz 
//	
	TIM3->PSC = 71; // 72MHz/(71+1) = 1MHz
	TIM3->ARR = 999; // 1MHz/(1+999) = 100Hz 
	
//	TIM4->PSC = 71; // 72MHz/(71+1) = 1MHz
//	TIM4->ARR = 9999; // 1MHz/(1+9999) = 100Hz
//	
//	//Enable TIM_IT
//	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_Base_Start_IT(&htim3);
//	//HAL_TIM_Base_Start_IT(&htim4);
//	
}

uint32_t Counter1 = 0;
void TIM1_IRQServer(void)
{
  //Check if it's the update interrupt
  if((htim1.Instance->SR &(TIM_FLAG_UPDATE)) == TIM_FLAG_UPDATE)
  {
		if(__HAL_TIM_GET_FLAG(&htim1,TIM_FLAG_UPDATE))
		{
			if(htim1.Instance->CNT <= 130)
			{
				hadc1.Instance->CR2 |=  1<<20;
				hadc2.Instance->CR2 |=  1<<20;
			}
		}
  }
  HAL_TIM_IRQHandler(&htim1);

}

uint32_t Counter3 = 0;
void TIM3_IRQServer(void)
{
    //Check if it's the update interrupt
  if((htim3.Instance->SR &(TIM_FLAG_UPDATE)) == TIM_FLAG_UPDATE)
  {
	  //clear the Flag
	  htim3.Instance->SR &= ~TIM_FLAG_UPDATE;
  }
	
  Counter3 = Counter3%10000;
	LED_Work_State(LedWorkMode,Counter3);
  Counter3--;
	MT6701_Get_RAWData();

}

uint32_t Counter4 = 0;
//void TIM4_IRQHandler(void)
//{
//    //Check if it's the update interrupt
//  if((htim4.Instance->SR &(TIM_FLAG_UPDATE)) == TIM_FLAG_UPDATE)
//  {
//	  //clear the Flag
//	  htim4.Instance->SR &= ~TIM_FLAG_UPDATE;
//  }
//}