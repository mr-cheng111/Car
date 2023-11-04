#ifndef AS5600
#define AS5600

#include "main.h"
#include "i2c.h"
#include "IQmathLib.h"
#include "FOC_Ctrl.h"
#include "i2c.h"

#define  RAW_Angle_Hi    0x0C
#define  RAW_Angle_Lo    0x0D
#define  AS5600_Address  0x36


double ReadAngleIIC(void);
extern uint8_t Temp_Angle_Data[2];
void MT6701_Get_RAWData(void);
void MT6701_Get_Angle(void);
void DMA1_Channel7_Server(void);

#endif