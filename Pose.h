#include "Quaternion.h"
#include "Vector3D.h"

#ifndef POSE_CPP_H
#define POSE_CPP_H

class Pose {
public:
    Pose(void){
        rotation = Quaternion(0.0, 0.0, 0.0, 1.0);
        translation = Vector3D(0.0, 0.0, 0.0);
    };
    Pose(const Matrix4x4 &mat);
    Pose getInverse() const;
    Vector3D GetObjectLocation() const;
    
    Quaternion rotation;
    Vector3D translation;
};

#endif