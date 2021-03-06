#include "Vector3D.h"

#ifndef MATRIX4X4_CPP_H
#define MATRIX4X4_CPP_H

#include <memory>
#include <iostream>
#include <cstring>

class Matrix4x4{
public:
    Matrix4x4();
    Matrix4x4(float e00, float e01, float e02, float e03,
              float e10, float e11, float e12, float e13,
              float e20, float e21, float e22, float e23,
              float e30, float e31, float e32, float e33);
    // Matrix4x4(float entries[16]);
    Matrix4x4(const float * newentries);
    //~Matrix4x4(); //empty
    
    void Identity(void);
    void Zero(void);
    
    //operators
    Matrix4x4 operator+(const Matrix4x4 & m) const;
    Matrix4x4 operator-(const Matrix4x4 & m) const;
    Matrix4x4 operator*(const Matrix4x4 & m) const;
    
    Vector3D GetTranslatedVector3D(const Vector3D & rhs) const;
    void SetTranslationPart(const Vector3D & translation);
    
    //cast to pointer to a (float *) for glGetFloatv etc
	operator float* () const {return (float*) this;}
	operator const float* () const {return (const float*) this;}
    
    //other methods
    void print();

    float values[16];
};

#endif