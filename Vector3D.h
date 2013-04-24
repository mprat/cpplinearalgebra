#ifndef VECTOR3D_CPP_H
#define VECTOR3D_CPP_H

class Vector3D{
public:
    Vector3D(void) : x(0.0f), y(0.0f), z(0.0f){}
    Vector3D(float newX, float newY, float newZ) :x(newX), y(newY), z(newZ){}
    Vector3D(const float * rhs) : x(*rhs), y(*(rhs+1)), z(*(rhs+2)){}
    Vector3D(const Vector3D & rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}
    
    float x;
    float y;
    float z;

};

#endif