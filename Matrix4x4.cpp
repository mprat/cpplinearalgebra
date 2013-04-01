#include "Matrix4x4.h"
#include <memory.h>

Matrix4x4::Matrix4x4(){
    Identity();
}

Matrix4x4::Matrix4x4(float e00, float e01, float e02, float e03,
          float e10, float e11, float e12, float e13,
          float e20, float e21, float e22, float e23,
                     float e30, float e31, float e32, float e33){
    values[0] = e00;
    values[1] = e01;
    values[2] = e02;
    values[3] = e03;
    values[4] = e10;
    values[5] = e11;
    values[6] = e12;
    values[7] = e13;
    values[8] = e20;
    values[9] = e21;
    values[10] = e22;
    values[11] = e23;
    values[12] = e30;
    values[13] = e31;
    values[14] = e32;
    values[15] = e33;
}

Matrix4x4::Matrix4x4(float entries[16]){
    *values = *entries;
}

void Matrix4x4::Identity(void){
    memset(values, 0, 16*sizeof(float));
	values[0]=1.0f;
	values[5]=1.0f;
	values[10]=1.0f;
	values[15]=1.0f;
}

void Matrix4x4::Zero(void){
    memset(values, 0, 16*sizeof(float));
}
