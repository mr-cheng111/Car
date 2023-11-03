#ifndef KALMAN_T
#define KALMAN_T

#include "Arduino.h"

#include <ArduinoEigenDense.h>

using namespace Eigen;

class KalmanFilter 
{
public:
    KalmanFilter(float dt, 
                 float processNoiseX, float processNoiseY, float processNoiseZ,
                 float measurementNoiseX, float measurementNoiseY, float measurementNoiseZ) :
        dt(dt),
        processNoise(Eigen::Vector3f(processNoiseX, processNoiseY, processNoiseZ)),
        measurementNoise(Eigen::Vector3f(measurementNoiseX, measurementNoiseY, measurementNoiseZ)),
        A(Eigen::Matrix<float, 6, 6>::Identity()),
        B(Eigen::Matrix<float, 6, 3>::Zero()),
        C(Eigen::Matrix<float, 3, 6>::Zero()),
        Q(Eigen::Matrix<float, 6, 6>::Identity()),
        R(Eigen::Matrix<float, 3, 3>::Identity()),
        P(Eigen::Matrix<float, 6, 6>::Identity()),
        x(Eigen::Vector<float, 6>::Zero()) {}

    KalmanFilter(float dt, float processNoise, float measurementNoise) :
        KalmanFilter(dt, processNoise, processNoise, processNoise,
                     measurementNoise, measurementNoise, measurementNoise) {}

    void predict(const Eigen::Vector3f& u) {
        A.block<3, 3>(0, 3) = Eigen::Matrix3f::Identity() * dt;
        B.block<3, 3>(3, 0) = Eigen::Matrix3f::Identity() * dt;

        x = A * x + B * u;
        P = A * P * A.transpose() + Q;
    }

    void update(const Eigen::Vector3f& z) {
        C.block<3, 3>(0, 0) = Eigen::Matrix3f::Identity();

        Eigen::Vector3f y = z - C * x;
        Eigen::Matrix3f S = C * P * C.transpose() + R;
        Eigen::Matrix<float, 6, 3> K = P * C.transpose() * S.inverse();

        x += K * y;
        P = (Eigen::Matrix<float, 6, 6>::Identity() - K * C) * P;
    }

    Eigen::Vector3f getStateAngles() const {
        return x.segment<3>(0);
    }

    Eigen::Vector3f getStateBiases() const {
        return x.segment<3>(3);
    }

private:
    float dt;
    Eigen::Vector3f processNoise;
    Eigen::Vector3f measurementNoise;

    Eigen::Matrix<float, 6, 6> A;
    Eigen::Matrix<float, 6, 3> B;
    Eigen::Matrix<float, 3, 6> C;
    Eigen::Matrix<float, 6, 6> Q;
    Eigen::Matrix<float, 3, 3> R;
    Eigen::Matrix<float, 6, 6> P;
    Eigen::Vector<float, 6> x;
};

#endif
