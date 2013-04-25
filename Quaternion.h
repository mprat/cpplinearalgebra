#include "Matrix4x4.h"

#ifndef QUATERNION_CPP_H
#define QUATERNION_CPP_H

#include <cmath>


class Quaternion{
public:
    Quaternion(void): x(0.0), y(0.0), z(0.0), w(1.0) {}
    Quaternion(double newX, double newY, double newZ, double newW): x(newX), y(newY), z(newZ), w(newW){}
    Quaternion(const Matrix4x4 &m);
    
    //operators
    Quaternion operator+(const Quaternion & rhs) const
	{	return Quaternion(x+rhs.x, y+rhs.y, z+rhs.z, w+rhs.w);	}
	Quaternion operator-(const Quaternion & rhs) const
	{	return Quaternion(x-rhs.x, y-rhs.y, z-rhs.z, w-rhs.w);	}
	Quaternion operator*(const float rhs) const
	{	return Quaternion(x*rhs, y*rhs, z*rhs, w*rhs);	}
	Quaternion operator/(const float rhs) const
	{	return rhs==0.0f	?	Quaternion(0.0f, 0.0f, 0.0f, 0.0f)
        :	Quaternion(x/rhs, y/rhs, z/rhs, w/rhs);	}
    void operator/=(const float rhs)
    {	if(rhs==0.0f)
        return;
    else
    {	x/=rhs; y/=rhs; z/=rhs; w/=rhs;	}
    }
    void operator*=(const float rhs)
    {	x*=rhs; y*=rhs; z*=rhs; w*=rhs;	}
    Quaternion operator*(const Quaternion & rhs) const;
    Vector3D operator*(const Vector3D rhs) const
    {
        Quaternion v(rhs.x, rhs.y, rhs.z, 0.0);
        Quaternion vt = (*this)*v*((*this).getInverse());
        return Vector3D(vt.x, vt.y, vt.z);
    }
        
    double getNormSquared() const {return (x*x + y*y + z*z + w*w);}
    Quaternion getConjugate() const {return Quaternion(-x, -y, -z, w);}
//    Quaternion getInverse() const {return ((1.0/getNormSquared())*getConjugate());}
    Quaternion getInverse() const {return (getConjugate() / getNormSquared());}
    
    double x;
    double y;
    double z;
    double w;
};

#endif