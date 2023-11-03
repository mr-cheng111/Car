#include "Useful_Math_Lib.h"

_iq Sqrt3_2 = _IQ(0.8660254037844386);
_iq Sqrt3 = _IQ(1.73205080756887);
_iq _1_Sqrt3 = _IQ(0.5773502691896257);
_iq _3_2 = _IQ(1.5);
_iq _1_2 = _IQ(0.5);
_iq _1   = _IQ(1.0);
_iq _2   = _IQ(2.0);
_iq _PI_3_PU = _IQ(0.16666666666), _2PI_3_PU = _IQ(0.33333333333);
_iq _PI_PU 	 = _IQ(0.5),					 _4PI_3_PU = _IQ(0.666666666666);
_iq _5PI_3_PU= _IQ(0.83333333333), _2PI_PU   = _IQ(1.0);
_iq _PI_2_PU = _IQ(0.25),_3PI_2_PU = _IQ(0.75);
_iq _002 = _IQ(0.002);
_iq Va,Vb,Vc,t1,t2,temp_sv1,temp_sv2;
uint8_t Sector = 0;  // Sector is treated as Q0 - independently with global Q




_iq Angle_Normalize(_iq Cita)
{
	while(1)
	{
		if(Cita > _IQ(1.0))
		{
			Cita -= _IQ(1.0);
		}
		else if(Cita < _IQ(0.0))
		{
			Cita += _IQ(1.0);
		}
		else break;
	}
	return Cita;
}





