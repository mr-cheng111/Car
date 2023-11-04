#include "FOC_Ctrl.h"
#include "math.h"
#include "TIM_IT_Server.h"
#include "BSP_LED.h"
#include "Useful_Math_Lib.h"
#include "LPF.h"
#include "math.h"

float IA,IB,IC,ID;
FOC_Ctrl_Typedef FOC;


_iq Ia[500],Ib[500];
void Current_init(void)
{
	HAL_Delay(1000);
	for(uint32_t i =0 ; i < 500;i++)
	{	
		Ia[i] = V[0];
		Ib[i] = V[1];
		HAL_Delay(1);
	}
	_iq I1_REF = _IQ(0.0),I2_REF = _IQ(0.0);
	for(uint32_t i =0 ; i < 500;i++)
	{
		I1_REF += _IQmpy(Ia[i],_002);
		I2_REF += _IQmpy(Ib[i],_002);
	}
	FOC.ADC.Calibrate_Level[0] = I1_REF;
	FOC.ADC.Calibrate_Level[1] = I2_REF;
}





void FOC_Init(void)
{
	FOC.TIM = &htim1;
	HAL_TIM_Base_Start_IT(FOC.TIM);
	HAL_TIM_PWM_Init(FOC.TIM);
	
	HAL_TIM_PWM_Start(FOC.TIM,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(FOC.TIM,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(FOC.TIM,TIM_CHANNEL_3);
	
	Driver_Enable();
	
	PID_init();
	
	FOC.Aim_Current[0] = _IQ(2.0); // Iq
	FOC.Aim_Current[1] = _IQ(0.0); // Id
	
	FOC.Motor.Voltage_Limit = _IQ(14.0);
	FOC.Motor.Voltage_Power_Support = _IQ(15.0);
	FOC.Motor.Pole_Pairs = 11;
	FOC.Sensor.Sensor_Direction = -1;
	FOC.Sensor.Zero_Electric_Angle = _IQ(0.4123);
	
	Sensor_Dectect_Init();

	Current_init();
}

/*
 *更新IQ和ID的PID参数
*/

void PID_init(void)
{
	FOC.Iq_Pid.term.c1  = _IQ(1);
	FOC.Iq_Pid.term.c2  = _IQ(0);
	FOC.Iq_Pid.param.Kp   = _IQ(IQ_KP);
	FOC.Iq_Pid.param.Ki   = _IQ(IQ_KI);
	FOC.Iq_Pid.param.Kd   = _IQ(IQ_KD);
	FOC.Iq_Pid.param.Umax = _IQ(IQ_MAX_OUT);
	FOC.Iq_Pid.param.Umin = _IQ(IQ_MIN_OUT);
	FOC.Iq_Pid.param.Imax = _IQ(IQ_MAX_IOUT);
	FOC.Iq_Pid.param.Imin = _IQ(IQ_MIN_IOUT);
	
	FOC.Id_Pid.term.c1  = _IQ(1);
	FOC.Id_Pid.term.c2  = _IQ(0);
	FOC.Id_Pid.param.Kp = _IQ(ID_KP);
	FOC.Id_Pid.param.Ki = _IQ(ID_KI);
	FOC.Id_Pid.param.Kd = _IQ(ID_KD);
	FOC.Id_Pid.param.Umax = _IQ(ID_MAX_OUT);
	FOC.Id_Pid.param.Umin = _IQ(ID_MIN_OUT);
	FOC.Id_Pid.param.Imax = _IQ(ID_MAX_IOUT);
	FOC.Id_Pid.param.Imin = _IQ(ID_MIN_IOUT);
	

}


/*
 *使能DRV8313
*/
void Driver_Enable(void)
{
	DRV_EN_GPIO_Port->BSRR = DRV_EN_Pin;
}

uint32_t U0,V0,W0;
void FOC_Ctrl(void)
{
	Get_Current(V);
	Clark_Transformation(FOC.ADC.Current_After_ADC[0],FOC.ADC.Current_After_ADC[1],FOC.Current_After_Clark);
	Get_Current_Angle(FOC.Sensor.Angle,FOC.Motor.Pole_Pairs);
	Park_Transformation(FOC.Current_After_Clark[0],FOC.Current_After_Clark[1],FOC.Current_After_Park);
	FOC_PID(FOC.Current_After_Park[0],FOC.Current_After_Park[1],FOC.Aim_Current[0],FOC.Aim_Current[1]);
	SVPWM(FOC.Iq_Pid.term.Out,0,FOC.Current_Angle);

}


float Iq_out0,Id_out0 = 0;
float Iq_Fbk0,Id_Fbk0 = 0;
float Iq_Set0,Id_Set0 = 0;
void FOC_PID(_iq Iq_fbk,_iq Id_fbk,_iq Iq_Set,_iq Id_Set)
{
	FOC.Iq_Pid.term.Ref = Iq_Set;
	FOC.Id_Pid.term.Ref = Id_Set;
	//Iq_Set0 = _IQtoF(Iq_Set);
	
	FOC.Iq_Pid.term.Fbk = Iq_fbk;
	FOC.Id_Pid.term.Fbk = Id_fbk;
	Iq_Fbk0 = _IQtoF(FOC.Iq_Pid.term.Fbk);
	Id_Fbk0 = _IQtoF(Id_fbk);
	PID_MACRO(FOC.Iq_Pid);
	PID_MACRO(FOC.Id_Pid);
	
//	FOC.Aim_U[0] = LPF(&LPF_Current_Q,FOC.Iq_Pid.term.Out);
//	FOC.Aim_U[1] = LPF(&LPF_Current_D,FOC.Id_Pid.term.Out);
//	Iq_Set0 = 0.7;
//	Id_Set0 = _IQtoF(FOC.Aim_U[1]);
}


/*
 *通过AD采样将电流数据转化出来
 */
_iq Level_Gain1 = _IQ(2.25);//50V/V增益*0.01ohm电阻 = 0.5，采样电压除于0.5得到电流,因此增益是2
_iq Level_Gain2 = _IQ(1.74);//50V/V增益*0.01ohm电阻 = 0.5，采样电压除于0.5得到电流,因此增益是2
float I_U , I_V , I_W;
void Get_Current(_iq *V)
{
	FOC.ADC.Current_After_ADC[0] = *V - FOC.ADC.Calibrate_Level[0];			//V是正向
	FOC.ADC.Current_After_ADC[1] = FOC.ADC.Calibrate_Level[1] - *(V+1);	//W是负向

//	I_V = _IQtoF(FOC.ADC.Current_After_ADC[0]);
//	I_W = _IQtoF(FOC.ADC.Current_After_ADC[1]); 
//	I_U = -I_W - I_V;

}


void Get_Current_Angle(_iq Current_Motor_Angle,uint8_t Num_Of_Pole_Pairs)
{
	FOC.Current_Angle = _IQ24mpyI32(Current_Motor_Angle,Num_Of_Pole_Pairs) - FOC.Sensor.Zero_Electric_Angle;
	FOC.Current_Angle = Angle_Normalize(FOC.Current_Angle);
}

/*
 *克拉克变换，将三相电压转换为两相电压I_Alpha，I_Beta
 *变换矩阵CK=[ 1,			-1/2,			 -1/2;
							 0,sqrt(3)/2,-sqrt(3)/2]
 */
//I1 -- V
//I2 -- W
float I_Alpha , I_Beta;
void Clark_Transformation(_iq I1,_iq I2,_iq *I)
{
	*I 		 = - I1 - I2; 			 				 //Get I_Alpha
	*(I+1) = _IQmpy(_1_Sqrt3,I1 - I2); //Get I_Beta
	
//	I_Alpha = _IQtoF(*I);
//	I_Beta  = _IQtoF(*(I+1));
}

/*
 *park变换，将静态两相电压I_Alpha，I_Beta转换为动态两相电流 Iq,Id
 *变换矩阵PK=[ cos(cita),sin(cita)
							-sin(cita),cos(cita)]
 *其中，Cita表示电角度，表示方法是标幺值，范围为0~1 就是0~2pi
 */
float I_Q , I_D;
void Park_Transformation(_iq I_Alpha,_iq I_Beta,_iq *I)
{
	_iq Cos_Cita = _IQ(0.0),Sin_Cita = _IQ(0.0);
	
	Cos_Cita = _IQcosPU(FOC.Current_Angle);
	Sin_Cita = _IQsinPU(FOC.Current_Angle);

	*I     = _IQmpy(Cos_Cita,I_Beta) - _IQmpy(Sin_Cita,I_Alpha);// Get Iq
	*(I+1) = _IQmpy(Sin_Cita,I_Beta) + _IQmpy(Cos_Cita,I_Alpha);// Get Id

	I_Q = _IQtoF(*I);
	I_D  = _IQtoF(*(I+1));
}

/*
 *SVPWM，将静态电流U_q，U_b转换为对应的SVPWM
 *使用中心对称计数法，默认状态是低电平，当大于计数值时，输出高电平，计数周期是4000
 */

void SVPWM(_iq Uq,_iq Ud,_iq Angle)
{
	_iq Uout = _IQ(0.0);
	_iq Temp_T1 = _IQ(0.0),Temp_T2 = _IQ(0.0),Temp_T0 = _IQ(0.0);

	Uq = _IQsat(Uq,FOC.Motor.Voltage_Limit,-FOC.Motor.Voltage_Limit);
	Ud = _IQsat(Ud,FOC.Motor.Voltage_Limit,-FOC.Motor.Voltage_Limit);
	
	if(Ud)
	{
		Uout = _IQsqrt(_IQmag(Uq,Ud));
		Angle = Angle_Normalize(Angle + _IQatan2PU(Uq, Ud));
	}
	else 
	{
		Uout = _IQdiv(Uq,FOC.Motor.Voltage_Limit);
		Angle = Angle_Normalize(Angle + _PI_2_PU);
	}

	Uout = _IQsat(Uout,_IQ(0.8),_IQ(-0.8));
	FOC.Sector = _IQint(_IQdiv(Angle,_PI_3_PU)) + 1;				
	Temp_T1 = _IQmpy(Sqrt3,_IQmpy(Uout,_IQsinPU(_IQmpyI32(_PI_3_PU,FOC.Sector) - Angle)));
	Temp_T2 = _IQmpy(Sqrt3,_IQmpy(Uout,_IQsinPU(Angle - _IQmpyI32(_PI_3_PU,FOC.Sector - 1))));
	Temp_T0 = _1 - Temp_T1 - Temp_T2;
  
	switch(FOC.Sector)
	{
		case 1:
		{
			FOC.PWM_Period[0] = Temp_T1 + Temp_T2 + _IQdiv2(Temp_T0);
			FOC.PWM_Period[1] = Temp_T2 + _IQdiv2(Temp_T0);
			FOC.PWM_Period[2] = _IQdiv2(Temp_T0);
		}break;
		case 2:
		{
			FOC.PWM_Period[0] = Temp_T1 + _IQdiv2(Temp_T0);
			FOC.PWM_Period[1] = Temp_T1 + Temp_T2 + _IQdiv2(Temp_T0);
			FOC.PWM_Period[2] = _IQdiv2(Temp_T0);
		}break;
		case 3:
		{
			FOC.PWM_Period[0] = _IQdiv2(Temp_T0);
			FOC.PWM_Period[1] = Temp_T1 + Temp_T2 + _IQdiv2(Temp_T0);
			FOC.PWM_Period[2] = Temp_T2 + _IQdiv2(Temp_T0);
		}break;
		case 4:		
		{
			FOC.PWM_Period[0] = _IQdiv2(Temp_T0);
			FOC.PWM_Period[1] = Temp_T1 + _IQdiv2(Temp_T0);
			FOC.PWM_Period[2] = Temp_T1 + Temp_T2 + _IQdiv2(Temp_T0);
		}break;
		case 5:
		{
			FOC.PWM_Period[0] = Temp_T2 + _IQdiv2(Temp_T0);
			FOC.PWM_Period[1] = _IQdiv2(Temp_T0);
			FOC.PWM_Period[2] = Temp_T1 + Temp_T2 + _IQdiv2(Temp_T0);
		}break;
		case 6:
		{
			FOC.PWM_Period[0] = Temp_T1 + Temp_T2 + _IQdiv2(Temp_T0);
			FOC.PWM_Period[1] = _IQdiv2(Temp_T0);
			FOC.PWM_Period[2] = Temp_T1 + _IQdiv2(Temp_T0);
		}break;
		default:
		{
			FOC.PWM_Period[0] = 0;
		  FOC.PWM_Period[1] = 0;
		  FOC.PWM_Period[2] = 0;
		}
	}
	
	FOC.TIM->Instance->CCR1 = _IQmpyI32int(FOC.PWM_Period[0],TIM_Period);
	FOC.TIM->Instance->CCR2 = _IQmpyI32int(FOC.PWM_Period[1],TIM_Period);
	FOC.TIM->Instance->CCR3 = _IQmpyI32int(FOC.PWM_Period[2],TIM_Period);
	
	U0 = FOC.TIM->Instance->CCR1;
	V0 = FOC.TIM->Instance->CCR2;
	W0 = FOC.TIM->Instance->CCR3;
}

_iq Temp_Data = _IQ(0.0001);
float Temp_S = 0.01;
float Temp_V = 2 ;
void Sensor_Dectect_Init(void)
{
	_iq angle = 0;
	float mid_angle,end_angle;
	float moved;
	Driver_Enable();
	
	
//		for(uint32_t i = 0; i < 100000; i++)
//		{
//			angle = _3PI_2_PU + _IQmpyI32(_IQ(0.008),i);
//			SVPWM(_IQ(6.0), 0,  angle);
////			HAL_Delay(1);
//		}
//		mid_angle = _IQtoF(FOC.Sensor.Angle);
//		
//		for(uint32_t i = 100000; i > 0; i--) 
//		{
//			angle = _3PI_2_PU - _IQmpyI32(_IQ(0.008),i);
//			SVPWM(_IQ(6.0), 0,  angle);
//			HAL_Delay(1);
//		}
//		end_angle = _IQtoF(FOC.Sensor.Angle);
//		SVPWM(_IQ(0.0),_IQ(0.0),_IQ(0.0));
//		HAL_Delay(2000);
//		
//		moved = fabs(mid_angle - end_angle);
//		
//		if(moved < 0.01)
//		{
//			HAL_GPIO_WritePin(DRV_EN_GPIO_Port,DRV_EN_Pin,GPIO_PIN_RESET);
//			LedWorkMode = 2;
//			return ;
//		}
//		else if(mid_angle < end_angle)
//		{
//			FOC.Sensor.Sensor_Direction = -1;
//		}
//		else if(mid_angle > end_angle)
//		{
//			FOC.Sensor.Sensor_Direction = 1;
//		}
		
		SVPWM(_IQ(2.0), 0, _3PI_2_PU);  //计算零点偏移角度
		HAL_Delay(10);
		
		FOC.Sensor.Zero_Electric_Angle = Angle_Normalize(_IQ24mpyI32(_IQ24mpyI32(FOC.Sensor.Angle,FOC.Motor.Pole_Pairs),FOC.Sensor.Sensor_Direction));
		SVPWM(_IQ(0.0), _IQ(0.0), _IQ(0.0));
		LedWorkMode = 1;
	}