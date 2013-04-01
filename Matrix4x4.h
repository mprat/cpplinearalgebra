class Matrix4x4{
public:
    Matrix4x4();
    Matrix4x4(float e00, float e01, float e02, float e03,
              float e10, float e11, float e12, float e13,
              float e20, float e21, float e22, float e23,
              float e30, float e31, float e32, float e33);
    Matrix4x4(float entries[16]);
    ~Matrix4x4(); //empty
    
    void Identity(void);
    void Zero(void);
private:
    float values[16];
};