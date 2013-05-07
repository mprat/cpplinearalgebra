#include "Vector3D.h"

void Vector3D::print(){
    std::cout<<"("<<x<<", "<<y<<", "<<z<<")"<<std::endl;
}

float Vector3D::length(){
    return (float)sqrt((x*x) + (y*y) + (z*z));
}

float Vector3D::xy_length(){
    return (float)sqrt((x*x) + (y*y));
}