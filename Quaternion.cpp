#include "Quaternion.h"

inline float SIGN(float x) {return (x >= 0.0f) ? +1.0f : -1.0f;}
inline float NORM(float a, float b, float c, float d) {return sqrt(a * a + b * b + c * c + d * d);}

Quaternion::Quaternion(const Matrix4x4 &m){
    const float* mat = m.values;
    const float EPS = 0.0;
	
	double q0 = ( mat[0] + mat[5] + mat[10] + mat[15])*0.25;
	double q1 = ( mat[0] - mat[5] - mat[10] + mat[15])*0.25;
	double q2 = (-mat[0] + mat[5] - mat[10] + mat[15])*0.25;
	double q3 = (-mat[0] - mat[5] + mat[10] + mat[15])*0.25;
	if(q0 < 0.0f) q0 = 0.0f;
	if(q1 < 0.0f) q1 = 0.0f;
	if(q2 < 0.0f) q2 = 0.0f;
	if(q3 < 0.0f) q3 = 0.0f;
	q0 = sqrt(q0);
	q1 = sqrt(q1);
	q2 = sqrt(q2);
	q3 = sqrt(q3);
	if(q0 < EPS && q1 < EPS) {
		q0 = 0.0f;
		q1 = 0.0f;
		q2 *= +1.0f;
		q3 *= SIGN(mat[6] + mat[9]);
	} else if(q0 < EPS) {
		q0 = 0.0f;
		q1 *= +1.0f;
		q2 *= SIGN(mat[1] + mat[4]);
		q3 *= SIGN(mat[8] + mat[2]);
	} else {
		q0 *= +1.0f;
		q1 *= SIGN(mat[6] - mat[9]);
		q2 *= SIGN(mat[8] - mat[2]);
		q3 *= SIGN(mat[1] - mat[4]);
	}
	double r = NORM(q0, q1, q2, q3);
	double ri = 1.0/r;
	w = q0*ri;
	x = q1*ri;
	y = q2*ri;
	z = q3*ri;
}

Quaternion Quaternion::operator*(const Quaternion & rhs) const
{
	return Quaternion((w*rhs.x+x*rhs.w+y*rhs.z-z*rhs.y), (w*rhs.y-x*rhs.z+y*rhs.w+z*rhs.x), (w*rhs.z+x*rhs.y-y*rhs.x+z*rhs.w), (w*rhs.w-x*rhs.x-y*rhs.y-z*rhs.z));
}

void Quaternion::print(){
    std::cout<<"("<<x<<", "<<y<<", "<<z<<", "<<w<<")"<<std::endl;
}