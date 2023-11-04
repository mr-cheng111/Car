#ifndef FOCCtrl

#define FOCCtrl

#include "main.h"
#include "BSP_MT6701.h"
#include "BSP_ADC.h"
#include "IQmathLib.h"
#include "pid_grando.h"
#include "tim.h"

/*��������ʹ��7λ��ʾ����������24λ��ʾ
 *�������ַ�Χ�ǣ�127 ~ -128
 *
 *
*/
#define IQ_KP 2
#define IQ_KI 0.0
#define IQ_KD 0.0
#define IQ_MAX_OUT 35.0 //A 
#define IQ_MIN_OUT -35.0//A 
#define IQ_MAX_IOUT 27.1 //A 
#define IQ_MIN_IOUT -27.1 //A 

#define ID_KP 0.0
#define ID_KI 0.0
#define ID_KD 0.0
#define ID_MAX_OUT 2.0 //A 
#define ID_MIN_OUT -2.0 //A 
#define ID_MAX_IOUT 1.00 //A 
#define ID_MIN_IOUT -1.00 //A 


#define TIM_Period 1440 - 1


typedef struct 
{	
	_iq Current_After_ADC[2];
	_iq Calibrate_Level[2];
	
}ADC_Fbk_Typedef;


typedef struct
{
	uint8_t Sensor_Direction;
	_iq Zero_Electric_Angle;
	_iq Angle;
	_iq Rate;
}Sensor_Typedef;

typedef struct
{
	_iq Voltage_Power_Support;
	_iq Voltage_Limit;
	uint8_t Pole_Pairs;
	
}Motor_Typedef;

typedef struct
{
	_iq Current_After_Clark[2];//����clark�任�õ��ĵ���
	_iq Current_After_Park[2]; //����Park�任�õ��ĵ���
	_iq Aim_Current[2];//Ŀ��ĵ���Iq��Ŀ��ĵ���Id
	_iq Aim_U[2];
	_iq PWM_Period[3];
	TIM_HandleTypeDef *TIM;
	//Id��Iq��PID
	PID_CONTROLLER Id_Pid,Iq_Pid;
	_iq Current_Angle;
	Sensor_Typedef Sensor;
	Motor_Typedef Motor;
	uint8_t Sector;
	ADC_Fbk_Typedef ADC;
}FOC_Ctrl_Typedef;


void Current_init(void);
void FOC_Init(void);
void PID_init(void);
void Get_Current(_iq *I);
void FOC_Ctrl(void);
void Clark_Transformation(_iq I1,_iq I2,_iq *I);
void Park_Transformation(_iq I_Alpha,_iq I_Beta,_iq *I);
void FOC_PID(_iq Iq_fbk,_iq Id_fbk,_iq Iq_Set,_iq Id_Set);
_iq Angle_Normalize(_iq Cita);
void Rev_Park_Transformation(_iq Cita,_iq Uq,_iq Ud,_iq *U);
void SVPWM(_iq Uq,_iq Ud,_iq Angle);
void Driver_Enable(void);
void Sensor_Dectect_Init(void);
void SVPWM_s(uint32_t i);
void Get_Current_Angle(_iq Current_Motor_Angle,uint8_t Num_Of_Pole_Pairs);
void Get_Current(_iq *V);
extern FOC_Ctrl_Typedef FOC;
extern float IA,IB,IC,ID;
#endif