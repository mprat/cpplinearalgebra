#include "Pose.h"

Pose::Pose(const Matrix4x4 &mat){
    Matrix4x4 inputMat = mat;
    translation = inputMat.GetTranslatedVector3D(Vector3D(0.0, 0.0, 0.0));
    inputMat.SetTranslationPart(Vector3D(0.0, 0.0, 0.0));
    rotation = Quaternion(inputMat);
}

Pose Pose::getInverse(){
    
}