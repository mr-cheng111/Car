#include "BSP_MT6701.h"
#include "i2c.h"

#define SlaveAddress    0X0C        //MT6701 地址
#define ReadAddress1    0X03        //数据高位寄存器地址
#define ReadAddress2    0X04        //数据低位寄存器地址


/*
 * IIC 方式读取角度信息
 * 返回数据为 0 ~ 360 之间的浮点数
 * STM32 开启 IIC 高速模式
 */
uint8_t Temp_Angle_Data[2] = {0};
double ReadAngleIIC(void)
{

    uint32_t angle = 0;
    double fangle = 0;
		HAL_I2C_Mem_Read(&hi2c1,SlaveAddress,ReadAddress1,I2C_MEMADD_SIZE_8BIT,Temp_Angle_Data,2,1000);
    angle = Temp_Angle_Data[0]<<8|Temp_Angle_Data[1];
    angle=angle>>2;            //取数据高 14 位
    fangle = (double)(angle * 360.0) / 16384.0;

    return fangle;
}

void MT6701_Get_RAWData(void)
{
	HAL_I2C_Mem_Read_DMA(&hi2c1,SlaveAddress,ReadAddress1,I2C_MEMADD_SIZE_8BIT,Temp_Angle_Data,2);
}

_iq Last_Angle;
void MT6701_Get_Angle(void)
{
	_iq Angle_del = 0;
	uint32_t Tick = __HAL_TIM_GetCounter(&htim4);
	Last_Angle = FOC.Sensor.Angle;
	FOC.Sensor.Angle = _IQ24mpyI32(_IQ(0.00006103515625),(uint32_t)(Temp_Angle_Data[0]<<8|Temp_Angle_Data[1])>>2);
	/********DEBUG*********/
	FOC.Sensor.Rate = _IQdiv(FOC.Sensor.Angle - Last_Angle,_IQ(Tick / 72000000.0));
	
	__HAL_TIM_SetCounter(&htim4,0);
	__HAL_TIM_ENABLE(&htim4);
}


/**
  * @brief This function handles DMA1 channel7 global interrupt.
  */
void DMA1_Channel7_Server(void)
{
	if (((hdma_i2c1_rx.DmaBaseAddress->ISR & (DMA_FLAG_HT1 << hdma_i2c1_rx.ChannelIndex)) != RESET) &&
			((hdma_i2c1_rx.Instance->CCR & DMA_IT_HT) != RESET))
  {
    if((hdma_i2c1_rx.Instance->CCR & DMA_CCR_CIRC) == 0U)
    {
	  CLEAR_BIT(hdma_i2c1_rx.Instance->CCR ,DMA_IT_HT);
    }
	DMA1->IFCR = DMA_FLAG_HT1;
  }

  else if (((hdma_i2c1_rx.DmaBaseAddress->ISR & (DMA_FLAG_TC1 << hdma_i2c1_rx.ChannelIndex)) != RESET) && 
	       ((hdma_i2c1_rx.Instance->CCR & DMA_IT_TC) != RESET))
  {
    if((hdma_i2c1_rx.Instance->CCR & DMA_CCR_CIRC) == 0U)
    {
			CLEAR_BIT(hdma_i2c1_rx.Instance->CCR ,DMA_IT_TE | DMA_IT_TC);
      hdma_i2c1_rx.State = HAL_DMA_STATE_READY;
			MT6701_Get_Angle();
    }
	DMA1->IFCR = DMA_FLAG_TC1;
  }
    __HAL_UNLOCK(&hdma_i2c1_rx);

    if(hdma_i2c1_rx.XferCpltCallback != NULL)
    {
      hdma_i2c1_rx.XferCpltCallback(&hdma_i2c1_rx);
    }
}
