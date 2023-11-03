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
	
	LPF_Velocity.Tf=_IQ(0.0001);   //Tf设置小一点，配合爬升斜率设置PID_velocity.output_ramp，速度切换更平稳；如果没有爬升模式的斜率限制，Tf太小电机容易抖动。
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
	if(dt > 0.3)   //时间过长，大概是程序刚启动初始化，直接返回
	{
		LPF->y_prev = x;
		return x;
	}
	
	alpha = _IQdiv(LPF->Tf,LPF->Tf + dt);
	y = _IQmpy(alpha,LPF->y_prev) + _IQmpy(_1 - alpha,x);
	LPF->y_prev = y;
	
	return y;
}











