#ifndef ARM_IK_H
#define ARM_IK_H


#include <iostream>
#include <QByteArray>

// #define Pi 3.14159
#define NUM_SOLUTIONS 8
#define MATRIX3d_SIZE 3
#define MATRIX4d_SIZE 4
#define MAX_SOLUTIONS 6
#define M_PI_2 3.1415926535/2
#define M_PI 3.1415926535


//枚举机械臂末端欧拉角
enum
{
    yaw = 0,
    pitch,
    roll
};

//枚举机械臂关节编号
enum
{
    joint1 = 0,
    joint2,
    joint3,
    joint4,
    joint5,
    joint6
};

typedef struct {
    double data[MAX_SOLUTIONS];
} VectorXd;

typedef struct {
    double data[MATRIX4d_SIZE][MATRIX4d_SIZE];
} Matrix4d;

typedef struct {
    double data[MATRIX3d_SIZE][MATRIX3d_SIZE];
} Matrix3d;

// 关节角结构体
typedef struct {
    double theta1, theta2, theta3, theta4, theta5, theta6;
} JointAngles;


//定义关节数据结构体
typedef struct JointData
{
    float curr_vel[5];
    float curr_pos[5];
    float curr_torque[5];
    float tar_vel[5];
    float tar_pos[5];
    float tar_torque[5];

    float out[5];
}JointDataTypedef;


//定义机械臂数据结构体
typedef struct ArmData
{
    float alpha, beta, gamma;
    float px,py,pz;
    JointDataTypedef joint_data;
}ArmDataTypedef;


class ARM
{
private:
    /* data */
public:
    ArmDataTypedef Arm_data;//机械臂数据

    // 定义存储逆解的数组和当前关节角度
    JointAngles IK[8];
    JointAngles currentAngles = {0, 0, 0, 0, 0, 0};

    int filterSolution1();
    void filterSolution2(double x, double y, double z);
    JointAngles optimalSolution = {0, 0, 0, 0, 0, 0};
    JointAngles filteredSolutions[8];
    int count=0;           //有效解个数

    ARM(/* args */);
    ~ARM();

    void initIdentityMatrix(Matrix4d *mat);
    Matrix4d rotX(double theta);
    Matrix4d rotZ(double theta);
    Matrix4d multiplyMatrix4d(const Matrix4d *a, const Matrix4d *b);
    Matrix3d multiplyMatrix3d(const Matrix3d *a, const Matrix3d *b);
    Matrix4d inverseMatrix(const Matrix4d *mat);
    Matrix4d inv_R03(double alpha01, double theta01, double alpha12, double theta12, double alpha23, double theta23, double alpha34, double theta34);
    double rad2deg(double rad);
    double deg2rad(double radians);
    double angleDifference(double angle1, double angle2);
    double totalAngleChange(const JointAngles* a1, const JointAngles* a2);
    JointAngles selectOptimalSolution();
    JointAngles Calc_Ik();
    QByteArray createDataFrame(const JointAngles &angles);

};

#endif // ARM_IK_H
