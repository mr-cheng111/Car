//=====================================================================================================
// MahonyAHRS.h
//=====================================================================================================
//
// Madgwick's implementation of Mayhony's AHRS algorithm.
// See: http://www.x-io.co.uk/node/8#open_source_ahrs_and_imu_algorithms
//
// Date			Author			Notes
// 29/09/2011	SOH Madgwick    Initial release
// 02/10/2011	SOH Madgwick	Optimised for reduced CPU load
//
//=====================================================================================================
#ifndef MahonyAHRS_h
#define MahonyAHRS_h

//----------------------------------------------------------------------------------------------------
// Variable declaration

extern float twoKp;			// 2 * proportional gain (Kp)
extern float twoKi;			// 2 * integral gain (Ki)
extern float q[4];
extern float Angle[3];

//---------------------------------------------------------------------------------------------------
// Function declarations

void IRAM_ATTR MahonyAHRSupdate(float q[4], float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
void IRAM_ATTR MahonyAHRSupdateIMU(float q[4], float gx, float gy, float gz, float ax, float ay, float az);
void IRAM_ATTR get_angle(float q[4], float *yaw, float *pitch, float *roll);
#endif
//=====================================================================================================
// End of file
//=====================================================================================================
