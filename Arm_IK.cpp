#include "Arm_IK.h"
#include "float.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <QString>
#include <QDebug>


ARM::ARM()
{
    Arm_data.px = 400;
    Arm_data.py = 200;
    Arm_data.pz = 100;
    Arm_data.alpha = deg2rad(90);
    Arm_data.beta = 0.0;
    Arm_data.gamma = 0.0;
}

ARM::~ARM()
{
}

// 初始化单位矩阵
void ARM::initIdentityMatrix(Matrix4d *mat) {
    for (int i = 0; i < MATRIX4d_SIZE; ++i) {
        for (int j = 0; j < MATRIX4d_SIZE; ++j) {
            mat->data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

// 绕X轴旋转的矩阵
Matrix4d ARM::rotX(double theta) {
    Matrix4d rot_X_matrix;
    initIdentityMatrix(&rot_X_matrix);
    rot_X_matrix.data[1][1] = cos(theta);
    rot_X_matrix.data[1][2] = -sin(theta);
    rot_X_matrix.data[2][1] = sin(theta);
    rot_X_matrix.data[2][2] = cos(theta);
    return rot_X_matrix;
}

// 绕Z轴旋转的矩阵
Matrix4d ARM::rotZ(double theta) {
    Matrix4d rot_Z_matrix;
    initIdentityMatrix(&rot_Z_matrix);
    rot_Z_matrix.data[0][0] = cos(theta);
    rot_Z_matrix.data[0][1] = -sin(theta);
    rot_Z_matrix.data[1][0] = sin(theta);
    rot_Z_matrix.data[1][1] = cos(theta);
    return rot_Z_matrix;
}

// 矩阵乘法
Matrix4d ARM::multiplyMatrix4d(const Matrix4d *a, const Matrix4d *b) {
    Matrix4d result;
    for (int i = 0; i < MATRIX4d_SIZE; ++i) {
        for (int j = 0; j < MATRIX4d_SIZE; ++j) {
            result.data[i][j] = 0.0;
            for (int k = 0; k < MATRIX4d_SIZE; ++k) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

// 矩阵乘法
Matrix3d ARM::multiplyMatrix3d(const Matrix3d *a, const Matrix3d *b) {
    Matrix3d result;
    for (int i = 0; i < MATRIX3d_SIZE; ++i) {
        for (int j = 0; j < MATRIX3d_SIZE; ++j) {
            result.data[i][j] = 0.0;
            for (int k = 0; k < MATRIX3d_SIZE; ++k) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

// 计算4x4矩阵的逆
Matrix4d ARM::inverseMatrix(const Matrix4d *mat) {
    Matrix4d result;
    double det;

    // 计算矩阵行列式
    det = mat->data[0][0] * (mat->data[1][1] * mat->data[2][2] - mat->data[1][2] * mat->data[2][1]) -
          mat->data[0][1] * (mat->data[1][0] * mat->data[2][2] - mat->data[1][2] * mat->data[2][0]) +
          mat->data[0][2] * (mat->data[1][0] * mat->data[2][1] - mat->data[1][1] * mat->data[2][0]);

    if (det == 0.0) {
        printf("Matrix is singular. Cannot find inverse.\n");
        initIdentityMatrix(&result); // 返回单位矩阵
        return result;
    }

    // 计算伴随矩阵
    result.data[0][0] = (mat->data[1][1] * mat->data[2][2] - mat->data[1][2] * mat->data[2][1]) / det;
    result.data[0][1] = -(mat->data[0][1] * mat->data[2][2] - mat->data[0][2] * mat->data[2][1]) / det;
    result.data[0][2] = (mat->data[0][1] * mat->data[1][2] - mat->data[0][2] * mat->data[1][1]) / det;
    result.data[0][3] = 0.0;

    result.data[1][0] = -(mat->data[1][0] * mat->data[2][2] - mat->data[1][2] * mat->data[2][0]) / det;
    result.data[1][1] = (mat->data[0][0] * mat->data[2][2] - mat->data[0][2] * mat->data[2][0]) / det;
    result.data[1][2] = -(mat->data[0][0] * mat->data[1][2] - mat->data[0][2] * mat->data[1][0]) / det;
    result.data[1][3] = 0.0;

    result.data[2][0] = (mat->data[1][0] * mat->data[2][1] - mat->data[1][1] * mat->data[2][0]) / det;
    result.data[2][1] = -(mat->data[0][0] * mat->data[2][1] - mat->data[0][1] * mat->data[2][0]) / det;
    result.data[2][2] = (mat->data[0][0] * mat->data[1][1] - mat->data[0][1] * mat->data[1][0]) / det;
    result.data[2][3] = 0.0;

    result.data[3][0] = -(mat->data[3][0] * result.data[0][0] + mat->data[3][1] * result.data[1][0] +
                         mat->data[3][2] * result.data[2][0]);
    result.data[3][1] = -(mat->data[3][0] * result.data[0][1] + mat->data[3][1] * result.data[1][1] +
                         mat->data[3][2] * result.data[2][1]);
    result.data[3][2] = -(mat->data[3][0] * result.data[0][2] + mat->data[3][1] * result.data[1][2] +
                         mat->data[3][2] * result.data[2][2]);
    result.data[3][3] = 1.0;

    return result;
}


// 计算R03矩阵的逆矩阵
Matrix4d ARM::inv_R03(double alpha01, double theta01, double alpha12, double theta12, double alpha23, double theta23, double alpha34, double theta34) {

    Matrix4d T1 = rotX(alpha01);Matrix4d T2 = rotZ(theta01);
    Matrix4d T3 = rotX(alpha12);Matrix4d T4 = rotZ(theta12);
    Matrix4d T5 = rotX(alpha23);Matrix4d T6 = rotZ(theta23);
    Matrix4d T7 = rotX(alpha34);Matrix4d T8 = rotZ(theta34);

    Matrix4d T01 = multiplyMatrix4d(&T1, &T2);
    Matrix4d T12 = multiplyMatrix4d(&T3, &T4);
    Matrix4d T23 = multiplyMatrix4d(&T5, &T6);
    Matrix4d T34 = multiplyMatrix4d(&T7, &T8);
    Matrix4d T = multiplyMatrix4d(&T01, &T12);
    T = multiplyMatrix4d(&T, &T23);
    T = multiplyMatrix4d(&T, &T34);
    for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                std::cout << "T01[" << i << "][" << j << "] = " << T01.data[i][j];
            }
            std::cout <<std::endl;
        }
    return inverseMatrix(&T);
}

//将弧度制转为角度制
double ARM::rad2deg(double rad)
{
    return rad * 180 / M_PI;
}

//角度转为弧度
double ARM::deg2rad(double radians) {
    return radians * ( M_PI/180.0);
}


// 计算两个角度之间的差异
double ARM::angleDifference(double angle1, double angle2) {
    double diff = angle1 - angle2;
    if (diff > M_PI)
        diff -= 2 * M_PI;
    else if (diff < -M_PI)
        diff += 2 * M_PI;
    return diff;
}

// 计算解之间的总角度变化量
double ARM::totalAngleChange(const JointAngles* a1, const JointAngles* a2) {
    return fabs(angleDifference(a1->theta1, a2->theta1)) +
           fabs(angleDifference(a1->theta2, a2->theta2)) +
           fabs(angleDifference(a1->theta3, a2->theta3)) +
           fabs(angleDifference(a1->theta4, a2->theta4)) +
           fabs(angleDifference(a1->theta5, a2->theta5)) +
           fabs(angleDifference(a1->theta6, a2->theta6));
}

// 选择最优解
JointAngles ARM::selectOptimalSolution() {
    double minChange = DBL_MAX;
    int optimalIndex = 0;

    for (int i = 0; i < count; ++i) {
        double change = totalAngleChange(&currentAngles, &filteredSolutions[i]);
        if (change < minChange) {
            minChange = change;
            optimalIndex = i;
            std::cout<< "i:" << i <<std::endl;
        }
    }

    return filteredSolutions[optimalIndex];
}


int ARM::filterSolution1()
{
    int k=0;
    for (int i = 0; i < 8; ++i) {
        JointAngles sol = IK[i];
        if ((sol.theta2 > deg2rad(-45.0) && sol.theta2 < deg2rad(225.0)))
        {
            if(sol.theta3 > deg2rad(-135.0) && sol.theta3 < deg2rad(0.0))
            {
//                if(sol.theta5 > deg2rad(-90.0) && sol.theta5 < deg2rad(90.0))
//                {
                    filteredSolutions[k]=sol;
                    k=k+1;
//                }
            }

        }
    }
    if(k == 0)
        {
            filteredSolutions[0] = currentAngles;
            k =1;
        }
    return k;
}

void ARM::filterSolution2(double x, double y, double z)
{
    if (z <= 0)
    {
        std::cout<<"error1"<<std::endl;
    }
    else
    {
        if(z <= 360)
        {
            if((x*x+y*y>=130*130)&&(x*x+y*y+(273-z)*(273-z)<=474*474))
            {
                count = filterSolution1();
                std::cout<<"count1  "<<count<<std::endl;
            }
            else
            {
                std::cout<<"error2"<<std::endl;
            }
        }
        else
        {
            if(x*x+y*y+z*z<=760*760)
            {
                count = filterSolution1();
                std::cout<<"count2   "<<count<<std::endl;
            }
            else
            {
                std::cout<<"error3"<<std::endl;
            }
        }
    }
}



JointAngles ARM::Calc_Ik()
{
    // MOD-DH参数
    // 定义连杆的D-H参数
    // 连杆偏移
    double d1 = 273;
    double d2 = 0;
    double d3 = 0;
    double d4 = -197.5;

    // 连杆长度
    double a1 = 0;
    double a2 = 0;
    double a3 = 266;
    double a4 = 66;

    // 连杆扭角
    double alpha1 = 0;
    double alpha2 = M_PI / 2;
    double alpha3 = 0;
    double alpha4 = -M_PI / 2;

    double nx1 = cos(deg2rad(Arm_data.beta)) * cos(deg2rad(Arm_data.gamma));
    double ox1 = -cos(deg2rad(Arm_data.alpha)) * sin(deg2rad(Arm_data.gamma)) + sin(deg2rad(Arm_data.alpha)) * sin(deg2rad(Arm_data.beta)) * cos(deg2rad(Arm_data.gamma));
    double ax1 = sin(deg2rad(Arm_data.alpha)) * sin(deg2rad(Arm_data.gamma)) + cos(deg2rad(Arm_data.alpha)) * sin(deg2rad(Arm_data.beta)) * cos(deg2rad(Arm_data.gamma));
    double ny1 = cos(deg2rad(Arm_data.beta)) * sin(deg2rad(Arm_data.gamma));
    double oy1 = cos(deg2rad(Arm_data.alpha)) * cos(deg2rad(Arm_data.gamma)) + sin(deg2rad(Arm_data.alpha)) * sin(deg2rad(Arm_data.beta)) * sin(deg2rad(Arm_data.gamma));
    double ay1 = -sin(deg2rad(Arm_data.alpha)) * cos(deg2rad(Arm_data.gamma)) + cos(deg2rad(Arm_data.alpha)) * sin(deg2rad(Arm_data.beta)) * sin(deg2rad(Arm_data.gamma));
    double nz1 = -sin(deg2rad(Arm_data.beta));
    double oz1 = sin(deg2rad(Arm_data.alpha)) * cos(deg2rad(Arm_data.beta));
    double az1 = cos(deg2rad(Arm_data.alpha)) * cos(deg2rad(Arm_data.beta));

    Arm_data.px = Arm_data.px - (-49.5 * ax1);
    Arm_data.py = Arm_data.py - (-49.5 * ay1);
    Arm_data.pz = Arm_data.pz - (-49.5 * az1);

    Matrix3d R06 = {{{nx1, ox1, ax1},
                      {ny1, oy1, ay1},
                      {nz1, oz1, az1}}};

    std::cout<<nx1<<" "<<ox1<<" "<<ax1<<" "
             <<ny1<<" "<<oy1<<" "<<ay1<<" "
             <<nz1<<" "<<oz1<<" "<<az1<<" "
             <<std::endl;

    double z = Arm_data.pz - 273;
    double L1 = 266;
    double L2 = sqrt(66 * 66 + 197.5 * 197.5);
    double L3 = sqrt(Arm_data.px * Arm_data.px + Arm_data.py * Arm_data.py + z * z);

    // 求解关节角1
    double theta1 = atan2(Arm_data.py, Arm_data.px);
    double theta1_1 = theta1;
    double theta1_2;
    if (theta1 <= 0)
        theta1_2 = theta1 + M_PI;
    else
        theta1_2 = theta1 - M_PI;

    std::cout<<"theta1_1 "<<theta1_1<<std::endl;
    std::cout<<"theta1_2 "<<theta1_2<<std::endl;

    // 求解关节角3
    double theta_A = atan2(197.5, 66);
    double theta_B = acos((L1 * L1 + L2 * L2 - L3 * L3) / (2 * L1 * L2));

    double theta3_1_1 = theta_A + theta_B - M_PI_2*3;
    double theta3_1_2 = M_PI/2 + theta_A - theta_B;

    double theta3_2_1 = M_PI/2 + theta_A - theta_B;
    double theta3_2_2 = theta_A + theta_B - M_PI_2*3;

    // 求解关节角2
    double theta_C = atan2(z, sqrt(Arm_data.px * Arm_data.px + Arm_data.py * Arm_data.py));
    double theta_D = acos((L1 * L1 + L3 * L3 - L2 * L2) / (2 * L1 * L3));
    double theta2_1_1 = theta_C + theta_D;
    double theta2_1_2 = theta_C - theta_D;

    double theta2_2_1 = -(theta_C + theta_D - M_PI);
    double theta2_2_2 = -(theta_C - theta_D - M_PI);

//    std::cout<<"theta2_1_1"<<theta2_1_1<<std::endl;
//    std::cout<<"theta2_1_2"<<theta2_1_2<<std::endl;
//    std::cout<<"theta2_2_1"<<theta2_2_1<<std::endl;
//    std::cout<<"theta2_2_2"<<theta2_2_2<<std::endl;
//    std::cout<<"theta3_1_1"<<theta3_1_1<<std::endl;
//    std::cout<<"theta3_1_2"<<theta3_1_2<<std::endl;
//    std::cout<<"theta3_2_1"<<theta3_2_1<<std::endl;
//    std::cout<<"theta3_2_2"<<theta3_2_2<<std::endl;

    // 参数矩阵取名为MDH
    double MDH[16][4] = {
        {theta1_1,                     d1,     a1,     alpha1},
        {theta2_1_1,                   d2,     a2,     alpha2},
        {(theta3_1_1 + M_PI_2),        d3,     a3,     alpha3},
        {0,                            d4,     a4,     alpha4},
        {theta1_1,                     d1,     a1,     alpha1},
        {theta2_1_2,                   d2,     a2,     alpha2},
        {(theta3_1_2 + M_PI_2),        d3,     a3,     alpha3},
        {0,                            d4,     a4,     alpha4},
        {theta1_2,                     d1,     a1,     alpha1},
        {theta2_2_1,                   d2,     a2,     alpha2},
        {(theta3_2_1 + M_PI_2),        d3,     a3,     alpha3},
        {0,                            d4,     a4,     alpha4},
        {theta1_2,                     d1,     a1,     alpha1},
        {theta2_2_2,                   d2,     a2,     alpha2},
        {(theta3_2_2 + M_PI_2),        d3,     a3,     alpha3},
        {0,                            d4,     a4,     alpha4}};

    double theta_46[8][3] = {0};

    for (int i = 0; i <= 12; i += 4) {
        Matrix4d inv_0 = inv_R03(MDH[i][3], MDH[i][0], MDH[i + 1][3], MDH[i + 1][0], MDH[i + 2][3], MDH[i + 2][0], MDH[i + 3][3], MDH[i + 3][0]);
        Matrix3d inv_1 = {{
            {inv_0.data[0][0], inv_0.data[0][1], inv_0.data[0][2]},
            {inv_0.data[1][0], inv_0.data[1][1], inv_0.data[1][2]},
            {inv_0.data[2][0], inv_0.data[2][1], inv_0.data[2][2]},
            }
        };
        Matrix3d R46 = multiplyMatrix3d(&inv_1, &R06);

        // for (int i = 0; i < 3; ++i)
        // {
        //     for (int j = 0; j < 3; ++j)
        //     {
        //         std::cout << "inv_0[" << i << "][" << j << "] = " << inv_0.data[i][j] << std::endl;
        //     }
        // }

        // 求解关节角4
        theta_46[i / 4][0] = atan2(R46.data[1][2], R46.data[0][2]);
        theta_46[i / 4 + 4][0] = theta_46[i / 4][0] + M_PI;

        // 求解关节角5
        theta_46[i / 4][1] = -atan2(sqrt(pow(R46.data[2][0], 2) + pow(R46.data[2][1], 2)), R46.data[2][2]);
        theta_46[i / 4 + 4][1] = -theta_46[i / 4][1];
        // 求解关节角6
        theta_46[i / 4][2] = atan2(R46.data[2][1], -R46.data[2][0]) + M_PI/2;
        theta_46[i / 4 + 4][2] = theta_46[i / 4][2] + M_PI;
    }


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            if (theta_46[i][j] > M_PI)
                theta_46[i][j] -= M_PI*2;
            else if (theta_46[i][j] <= -M_PI)
                theta_46[i][j] += M_PI*2;
        }
    }

//    // 打印 theta_46 数组
//    for (int i = 0; i < 8; ++i) { // 假设 theta_46 有 8 行
//        for (int j = 0; j < 3; ++j) { // 假设 theta_46 每行有 3 列
//            std::cout << "theta_46[" << i << "][" << j << "] = " << theta_46[i][j] << std::endl;
//        }
//    }

    IK[0] =  {theta1_1, theta2_1_1, theta3_1_1, theta_46[0][0], theta_46[0][1], theta_46[0][2]};
    IK[1] =  {theta1_1, theta2_1_2, theta3_1_2, theta_46[1][0], theta_46[1][1], theta_46[1][2]};
    IK[2] =  {theta1_2, theta2_2_1, theta3_2_1, theta_46[2][0], theta_46[2][1], theta_46[2][2]};
    IK[3] =  {theta1_2, theta2_2_2, theta3_2_2, theta_46[3][0], theta_46[3][1], theta_46[3][2]};
    IK[4] =  {theta1_1, theta2_1_1, theta3_1_1, theta_46[4][0], theta_46[4][1], theta_46[4][2]};
    IK[5] =  {theta1_1, theta2_1_2, theta3_1_2, theta_46[5][0], theta_46[5][1], theta_46[5][2]};
    IK[6] =  {theta1_2, theta2_2_1, theta3_2_1, theta_46[6][0], theta_46[6][1], theta_46[6][2]};
    IK[7] =  {theta1_2, theta2_2_2, theta3_2_2, theta_46[7][0], theta_46[7][1], theta_46[7][2]};

    // 打印八组解
    printf("ik1: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", IK[0].theta1, IK[0].theta2, IK[0].theta3, IK[0].theta4, IK[0].theta5, IK[0].theta6);
    printf("ik2: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", IK[1].theta1, IK[1].theta2, IK[1].theta3, IK[1].theta4, IK[1].theta5, IK[1].theta6);
    printf("ik3: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", IK[2].theta1, IK[2].theta2, IK[2].theta3, IK[2].theta4, IK[2].theta5, IK[2].theta6);
    printf("ik4: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", IK[3].theta1, IK[3].theta2, IK[3].theta3, IK[3].theta4, IK[3].theta5, IK[3].theta6);
    printf("ik5: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", IK[4].theta1, IK[4].theta2, IK[4].theta3, IK[4].theta4, IK[4].theta5, IK[4].theta6);
    printf("ik6: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", IK[5].theta1, IK[5].theta2, IK[5].theta3, IK[5].theta4, IK[5].theta5, IK[5].theta6);
    printf("ik7: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", IK[6].theta1, IK[6].theta2, IK[6].theta3, IK[6].theta4, IK[6].theta5, IK[6].theta6);
    printf("ik8: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", IK[7].theta1, IK[7].theta2, IK[7].theta3, IK[7].theta4, IK[7].theta5, IK[7].theta6);



    filterSolution2(Arm_data.px, Arm_data.py, Arm_data.pz);

    optimalSolution = selectOptimalSolution();

    currentAngles = optimalSolution;

    printf("Optimal solution: %.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",
           optimalSolution.theta1, optimalSolution.theta2, optimalSolution.theta3,
           optimalSolution.theta4, optimalSolution.theta5, optimalSolution.theta6);
    return optimalSolution;
}

QByteArray ARM::createDataFrame(const JointAngles &angles)
{
    QByteArray dataFrame;
    dataFrame.append(0xFF);  // 起始标志
    dataFrame.append(0xFE);  // 结束标志

    // 创建一个包含所有角度的数组
    double angleArray[6] = {angles.theta1, angles.theta2, angles.theta3, angles.theta4, angles.theta5, angles.theta6};

    for (double angle : angleArray)
    {
        // 将角度从 -3.14 到 3.14 转换为整数值
        int value = static_cast<int>(angle * 1000);

        bool isNegative = (value < 0);
        if (isNegative)
        {
            value = -value; // 取绝对值
            dataFrame.append(0x01);
        }
        else
        {
            dataFrame.append(0xee);
        }

        // 提取高8位
        uint8_t highByte = (value >> 8) & 0xFF;

        // 提取低8位
        uint8_t lowByte = value & 0xFF;

        // 将两个字节添加到数据帧
        dataFrame.append(highByte);
        dataFrame.append(lowByte);
    }

    QString output;
    for (char byte : dataFrame) {
        output += QString("%1 ").arg(static_cast<unsigned char>(byte), 2, 16, QChar('0')).toUpper();
    }
    qDebug() << output.trimmed();
    return dataFrame;
}

