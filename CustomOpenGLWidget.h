#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "model.h"

// settings
const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

const float coordVertices[] = {
    0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,     // 红色线段起点
    1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,     // 红色线段终点

    0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,     // 绿色线段起点
    0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,     // 绿色线段终点

    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,     // 蓝色线段起点
    0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f      // 蓝色线段终点
};

const float lightVertices[] = {
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
    0.5f, -0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

    0.5f,  0.5f,  0.5f,
    0.5f,  0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, -0.5f,  0.5f,
    0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    0.5f,  0.5f,  0.5f,
    0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
};

const int GRID_SIZE = 10;

struct Component {
    glm::vec3 origin;   // 原点坐标
    glm::vec3 axis;     // 旋转轴
    float minAngle;     // 最小旋转角度
    float maxAngle;     // 最大旋转角度
    float angle;        // 旋转角度
    glm::vec3 color;    // 物体颜色
};

class CustomOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    CustomOpenGLWidget(QWidget* parent = nullptr);

    glm::mat4 rotateAround(glm::mat4& model, const glm::vec3& center, const glm::vec3& axis, float angle);
    void updateSingleJoint(int index, float angle);
    void updateAllJoints(float* angles);
    void updateModelColor(int index, float r, float g, float b);
    void setPolygonMode(bool flag);
    void setGridMode(bool flag);
    void setAxisMode(bool flag);
    void setTrackMode(bool flag);
    void initGrid();
    void renderTrajectory();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private:
    QOpenGLVertexArrayObject m_lightVAO;
    QOpenGLVertexArrayObject m_coordVAO;
    QOpenGLVertexArrayObject m_gridVAO;
    QOpenGLVertexArrayObject m_trackVAO;
    unsigned int m_trackVBO;
    QOpenGLShaderProgram* m_lightProgram;
    Shader m_lightShader;
    Shader m_modelShader;
    Shader m_coordShader;
    Shader m_gridShader;
    Shader m_trackShader;
    std::string path[7];
    Model* ourModel[7];
    Component component[7];

    bool m_polygonMode = false;
    bool m_axisMode = false;
    bool m_gridMode = false;
    bool m_trackMode = false;
};
