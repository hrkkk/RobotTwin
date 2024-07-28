//
// Created by E cho on 2024/7/8.
//

#ifndef RENDER_H
#define RENDER_H

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"
#include "model.h"
#include <stack>

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

class Render {
public:
    Render();

    void initRender();
    void resizeRender();
    void paintRender();

    void setWindowSize(int width, int height);
    glm::mat4 rotateAround(glm::mat4& model, const glm::vec3& center, const glm::vec3& axis, float angle);
    void updateSingleJoint(int index, float angle);
    void updateAllJoints(float* angles);
    void updateModelColor(int index, float r, float g, float b);
    void updateGridStyle(float width, float r, float g, float b, float a);
    void updateTrackStyle(float width, float r, float g, float b, float a);

    void setPolygonMode(bool flag);
    void setGridMode(bool flag);
    void setAxisMode(bool flag);
    void setTrackMode(bool flag);
    void setExplodeMode(bool flag);
    void setNormalMode(bool flag);
    bool getPolygonMode() const;
    bool getGridMode() const;
    bool getAxisMode() const;
    bool getTrackMode() const;
    bool getExplodeMode() const;
    bool getNormalMode() const;

    void initGrid();
    void setView(const std::string& dir);

    float wheelEvent(float value);
    void mousePressEvent(float x, float y);
    bool mouseMoveEvent(float x, float y);

private:
    unsigned int m_lightVAO;
    unsigned int m_coordVAO;
    unsigned int m_gridVAO;
    unsigned int m_trackVAO;
    unsigned int m_trackVBO;
    Shader m_lightShader;
    Shader m_modelShader;
    Shader m_coordShader;
    Shader m_gridShader;
    Shader m_trackShader;
    Shader m_modelNormalShader;
    std::string path[7];
    Model* ourModel[7];
    Component component[7];

    float m_gridLineWidth;
    float m_trackLineWidth;
    glm::vec4 m_gridColor;
    glm::vec4 m_trackColor;

    bool m_polygonMode = false;
    bool m_axisMode = false;
    bool m_gridMode = false;
    bool m_trackMode = false;
    bool m_explodeMode = false;
    bool m_normalMode = false;

    int m_windowWidth;
    int m_windowHeight;
};



#endif //RENDER_H
