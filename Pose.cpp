#include "Pose.h"

Pose::Pose(const Matrix4x4 &mat){
    Matrix4x4 inputMat = mat;
    translation = inputMat.GetTranslatedVector3D(Vector3D(0.0, 0.0, 0.0));
    inputMat.SetTranslationPart(Vector3D(0.0, 0.0, 0.0));
    rotation = Quaternion(inputMat);
}

Pose::Pose(const float * newentries){
    Matrix4x4 inputMat = Matrix4x4(newentries);
    translation = inputMat.GetTranslatedVector3D(Vector3D(0.0, 0.0, 0.0));
    inputMat.SetTranslationPart(Vector3D(0.0, 0.0, 0.0));
    rotation = Quaternion(inputMat);
}

Pose Pose::getInverse() const{
    Quaternion rInv = rotation.getInverse();
    return Pose(rInv, rInv*(-translation));
}

Vector3D Pose::getObjectLocation() const{
	return getInverse()*Vector3D(0.0, 0.0, 0.0);
}

Vector3D Pose::translationToDesiredPose(const Pose &desiredPose){
    return (getObjectLocation() - desiredPose.getObjectLocation());
}

void Pose::print(){
    std::cout<<"Rotation: ";
    rotation.print();
    std::cout<<"Translation: ";
    translation.print();
}