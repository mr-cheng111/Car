#ifndef BSP_ADC
#define BSP_ADC

#include "main.h"
#include "adc.h"
#include "IQmathLib.h"
#include "string.h"

void ADC_Init(void);
void ADC_DMA_Server(void);
void Get_ADC_Value(void);
extern DMA_HandleTypeDef hdma_adc1;
extern ADC_HandleTypeDef hadc1;
extern uint8_t ADC_Start;
extern uint32_t V_temp[2];
extern _iq V[2];
#endif