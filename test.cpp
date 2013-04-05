#include "Matrix4x4.h";

int main( int argc, const char* argv[] )
{
	float foo[16] = {1.0, 1.0, 1.0, 0.0, 
		0.0, 1.0, 0.0, 0.0, 
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0};
	float bar[16] = {1.0, 0.0, 0.0, 0.0, 
		1.0, 1.0, 0.0, 0.0, 
		1.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0};
	Matrix4x4 foomat = Matrix4x4(foo) * Matrix4x4(bar);
	std::cout<<*((float *)foomat)<<std::endl;
	foomat.print();
}