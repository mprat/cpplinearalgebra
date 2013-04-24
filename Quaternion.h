#include "Matrix4x4.h"

#ifndef QUATERNION_CPP_H
#define QUATERNION_CPP_H

#include <cmath>


class Quaternion{
public:
    Quaternion(void): x(0.0), y(0.0), z(0.0), w(1.0) {};
    Quaternion(double newX, double newY, double newZ, double newW): x(newX), y(newY), z(newZ), w(newW){};
    Quaternion(const Matrix4x4 &m);
    
    double x;
    double y;
    double z;
    double w;
};

#endif