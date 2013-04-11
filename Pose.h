#include "Matrix4x4.h"
#include "Vector3D.h"

class Pose {
public:
    Pose(void);
    Pose(const Matrix4x4 &mat);
    Pose getInverse() const;
    Vector3D GetObjectLocation() const;
};