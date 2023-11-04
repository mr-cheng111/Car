/* =================================================================================
File name:       PID_GRANDO.H 
===================================================================================*/


#ifndef __PID_H__
#define __PID_H__

#include "IQmathLib.h"



typedef struct {
					_iq  Ref;   		// Input: reference set-point
				  _iq  Fbk;   		// Input: feedback
				  _iq  Out;   		// Output: controller output 
				  _iq  c1;   			// Internal: derivative filter coefficient 1
				  _iq  c2;   			// Internal: derivative filter coefficient 2
				} PID_TERMINALS;
				// note: c1 & c2 placed here to keep structure size under 8 words

typedef struct {  
				  _iq  Kp;				// Parameter: proportional loop gain				�����ջ�����
				  _iq  Ki;			  // Parameter: integral gain									��������
				  _iq  Kd; 		    // Parameter: derivative gain								��������
	
				  _iq  Imin; 		    // Parameter: derivative weighting  				������Ȩ
					_iq  Imax;				// Parameter: reference set-point weighting �ο��趨���Ȩ
				  _iq  Umax;			// Parameter: upper saturation limit				��������
				  _iq  Umin;			// Parameter: lower saturation limit				��������
				} PID_PARAMETERS;

typedef struct {  
					_iq  up;				// Data: proportional term ����
				  _iq  ui;				// Data: integral term		 ����
				  _iq  ud;				// Data: derivative term	 ΢��
				  _iq  v1;				// Data: pre-saturated controller output Ԥ���ͱ������
				  _iq  i1;				// Data: integrator storage: ui(k-1)		 ��һ�̱�����
				  _iq  d1;				// Data: differentiator storage: ud(k-1) ��һ��΢����
				  _iq  d2;				// Data: differentiator storage: d2(k-1) 
				  _iq  w1;				// Data: saturation record: [u(k-1) - v(k-1)]���ͼ�¼ 
				} PID_DATA;


typedef struct {  
					PID_TERMINALS	term;
				  PID_PARAMETERS param;
				  PID_DATA		data;
				} PID_CONTROLLER;

/*------------------------------------------------------------------------------
 	PID Macro Definition
------------------------------------------------------------------------------*/

#define PID_MACRO(v)																				\
																									\
	/* proportional term ��ʽ��P = Kp*(Ref(����ֵ)-Fbk(����ֵ))*/ 																		\
	v.data.up =  v.term.Ref - v.term.Fbk;										\
																									\
	/* integral term 		 ��ʽ��I = Ki*W1(����Ȩ��)*(Ref(�������) - Fbk(����)) + I*/ 																			\
	v.data.ui = _IQmpy(v.param.Ki, _IQmpy(v.data.w1, (v.term.Ref - v.term.Fbk))) + v.data.i1;		\
	v.data.ui	=	_IQsat(v.data.ui,v.param.Imax,v.param.Imin);				\
	v.data.i1 = v.data.ui;																			\
																									\
	/* derivative term   ��ʽ��D = Kd*(Ref(����)-Fdk(����)) - ��һʱ�̱����ֵ) + C2*D*/ 																			\
	v.data.d2 = _IQmpy(v.param.Kd,(v.term.Ref - v.term.Fbk)) - v.data.d2;	\
	/*���´˿̵�ud*/\
	v.data.ud = v.data.d2 + v.data.d1;																\
	/*����d1*/										\
	v.data.d1 = _IQmpy(v.data.ud, v.term.c2);														\
																									\
	/* control output */ 																			\
	v.data.v1 = _IQmpy(v.param.Kp, (v.data.up + v.data.ui + v.data.ud));							\
	v.term.Out= _IQsat(v.data.v1, v.param.Umax, v.param.Umin);										\
	v.data.w1 = (v.term.Out == v.data.v1) ? _IQ(1.0) : _IQ(0.0);									\
	
#endif // __PID_H__

