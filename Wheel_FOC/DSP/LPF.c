#include "LPF.h"
#include "Useful_Math_Lib.h"

LowPassFilter  LPF_Current_Q,LPF_Current_D,LPF_Velocity;
LowPassFilter  LPF_I1,LPF_I2;
/******************************************************************************/
void LPF_Init(void)
{
	LPF_Current_Q.Tf=_IQ(0.1);    
	LPF_Current_Q.y_prev=_IQ(0.0);
	LPF_Current_Q.timestamp_prev=0;  //SysTick->VAL;
	
	LPF_Current_D.Tf=_IQ(0.05);
	LPF_Current_D.y_prev=_IQ(0.0);
	LPF_Current_D.timestamp_prev=0;
	
	LPF_Velocity.Tf=_IQ(0.0001);   //Tf����Сһ�㣬�������б������PID_velocity.output_ramp���ٶ��л���ƽ�ȣ����û������ģʽ��б�����ƣ�Tf̫С������׶�����
	LPF_Velocity.y_prev=_IQ(0.0);
	LPF_Velocity.timestamp_prev=0;
	
	LPF_I1.Tf=_IQ(0.00000000001);    
	LPF_I1.y_prev=_IQ(0.0);
	LPF_I1.timestamp_prev=0;  //SysTick->VAL;
	
	LPF_I2.Tf=_IQ(0.00000000001);    
	LPF_I2.y_prev=_IQ(0.0);
	LPF_I2.timestamp_prev=0;  //SysTick->VAL;
}

_iq LPF(LowPassFilter* LPF,_iq x)
{
	uint32_t now_us;
	_iq dt, alpha, y;
	
	now_us = HAL_GetTick();
	if(now_us < LPF->timestamp_prev)
		dt = _IQ((float)(LPF->timestamp_prev - now_us)/9*1e-6f);
	else
		dt = _IQ((float)(0xFFFFFF - now_us + LPF->timestamp_prev)/9*1e-6f);
	LPF->timestamp_prev = now_us;
	if(dt > 0.3)   //ʱ�����������ǳ����������ʼ����ֱ�ӷ���
	{
		LPF->y_prev = x;
		return x;
	}
	
	alpha = _IQdiv(LPF->Tf,LPF->Tf + dt);
	y = _IQmpy(alpha,LPF->y_prev) + _IQmpy(_1 - alpha,x);
	LPF->y_prev = y;
	
	return y;
}











