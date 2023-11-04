#include "BSP_ADC.h"
#include "stm32f1xx_hal_dma.h"
#include "string.h"
#include "IQmathLib.h"
#include "FOC_Ctrl.h"
#define ADC_DATA_LENGTH 15
#define ADC_Channel_Num 2
volatile uint16_t ADC_DATA[ADC_DATA_LENGTH][ADC_Channel_Num];
uint8_t ADC_Start = 0;
void ADC_Init(void)
{
  HAL_ADC_Init(&hadc1);
	HAL_ADC_Init(&hadc2);
  HAL_ADCEx_Calibration_Start(&hadc1);
  HAL_ADCEx_Calibration_Start(&hadc2);
	HAL_ADCEx_MultiModeStart_DMA(&hadc1,(uint32_t *)ADC_DATA,ADC_DATA_LENGTH);
}

float A , B;
_iq V[2];
_iq _vcc = _IQ(3.320);
void Get_ADC_Value(void)
{
	uint32_t V_temp[2] = {0};
	
	for(uint16_t Cnt = 0;Cnt < ADC_DATA_LENGTH;Cnt ++)
	{
		V_temp[0] +=  ADC_DATA[Cnt][0];
		V_temp[1] +=  ADC_DATA[Cnt][1];
	}
	
	memset((void*)ADC_DATA,0,ADC_DATA_LENGTH*ADC_Channel_Num*2);
	V[0] = _IQmpy(_vcc,_IQ((float)V_temp[0]/4096/ADC_DATA_LENGTH));
	V[1] = _IQmpy(_vcc,_IQ((float)V_temp[1]/4096/ADC_DATA_LENGTH));
	
	A = _IQtoF(V[0]);
	B = _IQtoF(V[1]);
}

void ADC_DMA_Server(void)
{
  if (((hdma_adc1.DmaBaseAddress->ISR & (DMA_FLAG_HT1 << hdma_adc1.ChannelIndex)) != RESET) &&
			((hdma_adc1.Instance->CCR & DMA_IT_HT) != RESET))
  {
		DMA1->IFCR = DMA_FLAG_HT1;
  }

  else if (((hdma_adc1.DmaBaseAddress->ISR & (DMA_FLAG_TC1 << hdma_adc1.ChannelIndex)) != RESET) && 
	       ((hdma_adc1.Instance->CCR & DMA_IT_TC) != RESET))
  {
			Get_ADC_Value();
			DMA1->IFCR = DMA_FLAG_TC1;
  }
  __HAL_UNLOCK(&hdma_adc1);

  if(hdma_adc1.XferCpltCallback != NULL)
  {
    hdma_adc1.XferCpltCallback(&hdma_adc1);
  }
}

