#ifndef _LPF
#define _LPF

#include "IQmathLib.h"
#include "main.h"


typedef struct 
{
	_iq Tf; //!< Low pass filter time constant
	_iq y_prev; //!< filtered value in previous execution step 
	uint32_t timestamp_prev;  //!< Last execution timestamp
} LowPassFilter;

extern LowPassFilter  LPF_Current_Q,LPF_Current_D,LPF_Velocity;
extern LowPassFilter  LPF_I1,LPF_I2;

extern void LPF_Init(void);

extern _iq LPF(LowPassFilter* LPF,_iq x);

#endif