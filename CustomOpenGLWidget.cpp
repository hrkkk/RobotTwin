#include "CustomOpenGLWidget.h"

#include <stack>
#include <QTimer>

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
glm::vec4 backgroundColor(glm::vec4(0.94f, 0.94f, 0.94f, 1.0f));
std::vector<glm::vec3> gridVertices;
std::vector<glm::vec4> trackVertices;
const size_t maxTrackPoint = 1000;
glm::vec3 toolPosition = glm::vec3(0.0f);

QTimer motionTimer;

CustomOpenGLWidget::CustomOpenGLWidget(QWidget* parent): QOpenGLWidget(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);

    initGrid();
}

void CustomOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    m_modelShader = Shader("../../modelVertexShader.glsl", "../../modelFragmentShader.glsl");
    m_lightShader = Shader("../../lightVertexShader.glsl", "../../lightFragmentShader.glsl");
    m_coordShader = Shader("../../coordVertexShader.glsl", "../../coordFragmentShader.glsl");
    m_gridShader = Shader("../../coordVertexShader.glsl", "../../trackFragmentShader.glsl");
    m_trackShader = Shader("../../trackVertexShader.glsl", "../../trackFragmentShader.glsl");

    // 创建光源VAO
    m_lightVAO.create();
    m_lightVAO.bind();
    // 创建光源VBO
    unsigned int lightVBO;
    glGenBuffers(1, &lightVBO);
    glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lightVertices), lightVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    m_lightVAO.release();

    // 创建坐标系VAO
    m_coordVAO.create();
    m_coordVAO.bind();
    // 创建坐标系VBO
    unsigned int coordVBO;
    glGenBuffers(1, &coordVBO);
    glBindBuffer(GL_ARRAY_BUFFER, coordVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(coordVertices), coordVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    m_coordVAO.release();

    // 创建网格VAO
    m_gridVAO.create();
    m_gridVAO.bind();
    // 创建网格VBO
    unsigned int gridVBO;
    glGenBuffers(1, &gridVBO);
    glBindBuffer(GL_ARRAY_BUFFER, gridVBO);
    glBufferData(GL_ARRAY_BUFFER, gridVertices.size() * sizeof(glm::vec3), gridVertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    m_gridVAO.release();

    // 创建轨迹VAO
    m_trackVAO.create();
    m_trackVAO.bind();
    // 创建轨迹VAO
    glGenBuffers(1, &m_trackVBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_trackVBO);
    glBufferData(GL_ARRAY_BUFFER, maxTrackPoint * sizeof(glm::vec4), nullptr, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    m_gridVAO.release();

    path[0] = "../../model/base.obj";
    path[1] = "../../model/shoulder.obj";
    path[2] = "../../model/arm.obj";
    path[3] = "../../model/elbow.obj";
    path[4] = "../../model/forearm.obj";
    path[5] = "../../model/wrist.obj";
    path[6] = "../../model/tool.obj";

    for (int i = 0; i < 7; i++) {
        ourModel[i] = new Model(path[i]);
    }

    component[0] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        -180,
        180,
        0,
        glm::vec3(1.0f, 0.0f, 0.0f)
    };
    component[1] = {
        glm::vec3(0.0f, 0.059f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        -180,
        180,
        0,
        glm::vec3(0.0f, 1.0f, 0.0f)
    };
    component[2] = {
        glm::vec3(0.0f, 0.215f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        -180,
        180,
        0,
        glm::vec3(0.0f, 0.0f, 1.0f)
    };
    component[3] = {
        glm::vec3(-0.266f, 0.001f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        -180,
        180,
        0,
        glm::vec3(1.0f, 1.0f, 0.0f)
    };
    component[4] = {
        glm::vec3(0.013f, 0.0f, 0.065f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        -180,
        180,
        0,
        glm::vec3(0.0f, 1.0f, 1.0f)
    };
    component[5] = {
        glm::vec3(-0.23f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        -180,
        180,
        0,
        glm::vec3(1.0f, 0.0f, 1.0f)
    };
    component[6] = {
        glm::vec3(-0.035f, 0.0f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        -180,
        180,
        0,
        glm::vec3(1.0f, 0.5f, 0.0f)
    };

    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    glEnable(GL_DEPTH_TEST);
}

std::stack<glm::mat4> mvStack;
void CustomOpenGLWidget::paintGL()
{
    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (m_polygonMode) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glLineWidth(1.0f);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    // 渲染机械臂模型
    m_modelShader.use();
    m_modelShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    m_modelShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
    m_modelShader.setVec3("lightPos", 1.0f, 1.0f, 1.0f);
    m_modelShader.setVec3("viewPos", camera.Position);

    // MVP: 投影矩阵 —— 视图矩阵 —— 模型矩阵
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)this->width() / (float)this->height(), 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);

    m_modelShader.setMat4("projection", projection);

    // 将视图矩阵压入栈
    mvStack.push(view);

    // 基座
    model = glm::translate(model, component[0].origin);     // 平移

    mvStack.push(mvStack.top());
    mvStack.top() *= model;    // 基座位置

    m_modelShader.setMat4("model", model);
    m_modelShader.setMat4("mv", mvStack.top());
    m_modelShader.setVec3("objectColor", component[0].color);
    ourModel[0]->Draw(m_modelShader);

    // 肩部
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[1].origin);
    model = glm::rotate(model, glm::radians(component[1].angle), component[1].axis);

    mvStack.push(mvStack.top());
    mvStack.top() *= model;

    m_modelShader.setMat4("model", model);
    m_modelShader.setMat4("mv", mvStack.top());
    m_modelShader.setVec3("objectColor", component[1].color);
    ourModel[1]->Draw(m_modelShader);

    // 大臂
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[2].origin);
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(component[2].angle), component[2].axis);

    mvStack.push(mvStack.top());
    mvStack.top() *= model;
    m_modelShader.setMat4("model", model);
    m_modelShader.setMat4("mv", mvStack.top());
    m_modelShader.setVec3("objectColor", component[2].color);
    ourModel[2]->Draw(m_modelShader);

    // 小臂1
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[3].origin);
    model = glm::rotate(model, glm::radians(component[3].angle), component[3].axis);

    mvStack.push(mvStack.top());
    mvStack.top() *= model;

    m_modelShader.setMat4("model", model);
    m_modelShader.setMat4("mv", mvStack.top());
    m_modelShader.setVec3("objectColor", component[3].color);
    ourModel[3]->Draw(m_modelShader);

    // 小臂2
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[4].origin);
    model = glm::rotate(model, glm::radians(component[4].angle), component[4].axis);

    mvStack.push(mvStack.top());
    mvStack.top() *= model;

    m_modelShader.setMat4("model", model);
    m_modelShader.setMat4("mv", mvStack.top());
    m_modelShader.setVec3("objectColor", component[4].color);
    ourModel[4]->Draw(m_modelShader);

    // 手腕
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[5].origin);
    model = glm::rotate(model, glm::radians(component[5].angle), component[5].axis);

    mvStack.push(mvStack.top());
    mvStack.top() *= model;

    m_modelShader.setMat4("model", model);
    m_modelShader.setMat4("mv", mvStack.top());
    m_modelShader.setVec3("objectColor", component[5].color);
    ourModel[5]->Draw(m_modelShader);

    // 末端工具
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[6].origin);
    model = glm::rotate(model, glm::radians(component[6].angle), component[6].axis);

    mvStack.push(mvStack.top());
    mvStack.top() *= model;

    m_modelShader.setMat4("model", model);
    m_modelShader.setMat4("mv", mvStack.top());
    m_modelShader.setVec3("objectColor", component[6].color);
    ourModel[6]->Draw(m_modelShader);

    glm::vec4 pos = projection * mvStack.top() * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

    // 渲染光源
    // m_lightShader.use();
    // model = glm::mat4(1.0f);
    // model = glm::translate(model, glm::vec3(1.0f, 1.0f, 1.0f));
    // model = glm::scale(model, glm::vec3(1.0f));
    // m_lightShader.setMat4("model", model);
    // m_lightShader.setMat4("projection", projection);
    // m_lightShader.setMat4("view", view);

    // m_lightVAO.bind();
    // glDrawArrays(GL_TRIANGLES, 0, 36);
    // m_lightVAO.release();

    if (m_axisMode) {
        // 渲染坐标轴
        m_coordShader.use();
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.1f));
        m_coordShader.setMat4("model", model);
        m_coordShader.setMat4("projection", projection);
        m_coordShader.setMat4("view", view);

        // glDrawArrays(GL_POINTS, 0, 1);  // 绘制第一个顶点作为点

        m_coordVAO.bind();
        glLineWidth(5.0f);
        glDrawArrays(GL_LINES, 0, 6);   // 从第二个顶点开始绘制三个顶点作为线段
        m_coordVAO.release();
    }

    if (m_gridMode) {
        // 渲染网格图
        m_gridShader.use();
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(0.1f));
        m_gridShader.setMat4("model", model);
        m_gridShader.setMat4("projection", projection);
        m_gridShader.setMat4("view", view);

        m_gridShader.setVec4("color", m_gridColor);

        m_gridVAO.bind();
        glLineWidth(m_gridLineWidth);
        glDrawArrays(GL_LINES, 0, gridVertices.size());
        m_gridVAO.release();
    }

    if (m_trackMode) {
        // 渲染轨迹
        trackVertices.push_back(pos);
        // 添加轨迹点
        glBindBuffer(GL_ARRAY_BUFFER, m_trackVBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, trackVertices.size() * sizeof(glm::vec4), trackVertices.data());
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // 绘制轨迹线
        m_trackShader.use();
        m_trackShader.setVec4("color", m_trackColor);
        m_trackVAO.bind();
        glLineWidth(m_trackLineWidth);
        glDrawArrays(GL_LINE_STRIP, 0, trackVertices.size());
        m_trackVAO.release();
    }
}

void CustomOpenGLWidget::resizeGL(int w, int h)
{

}

void CustomOpenGLWidget::wheelEvent(QWheelEvent* event)
{
    camera.ProcessMouseScroll(static_cast<float>(event->angleDelta().y() / 100.0f));
    emit sig_updateViewZoom(camera.Zoom);
    update();
}

static float lastX = 0.0f;
static float lastY = 0.0f;

void CustomOpenGLWidget::mousePressEvent(QMouseEvent* event)
{
    lastX = event->position().x();
    lastY = event->position().y();
}

void CustomOpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{   
    float deltaX = event->position().x() - lastX;
    float deltaY = event->position().y() - lastY;

    // 更新鼠标位置
    lastX = event->position().x();
    lastY = event->position().y();

    if (deltaX != 0 && deltaY != 0) {
        camera.ProcessMouseMovement(deltaX, deltaY);
        update();
    }
}

void CustomOpenGLWidget::keyReleaseEvent(QKeyEvent* event)
{
    // switch (event->key()) {
    // case Qt::Key_W:
    //     camera.ProcessKeyboard(FORWARD, 0.5);
    //     break;
    // case Qt::Key_S:
    //     camera.ProcessKeyboard(BACKWARD, 0.5);
    //     break;
    // case Qt::Key_A:
    //     camera.ProcessKeyboard(LEFT, 0.5);
    //     break;
    // case Qt::Key_D:
    //     camera.ProcessKeyboard(RIGHT, 0.5);
    //     break;
    // }
    // update();
}

glm::mat4 CustomOpenGLWidget::rotateAround(glm::mat4& model, const glm::vec3& pivot, const glm::vec3& axis, float angle)
{
    // 首先，将模型平移到旋转中心
    glm::mat4 translateToCenter = glm::translate(glm::mat4(1.0f), pivot);

    // 然后，创建旋转矩阵
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), angle, glm::normalize(axis));

    // 接着，将模型从旋转中心平移回原位置
    glm::mat4 translateBack = glm::translate(glm::mat4(1.0f), -pivot);

    // 组合变换矩阵
    glm::mat4 transform = translateBack * rotation * translateToCenter;

    return transform;
}

void CustomOpenGLWidget::updateSingleJoint(int index, float angle)
{
    if (index < 0 || index >= 7) {
        return;
    }

    if (angle < component[index].minAngle) {
        this->component[index].angle = component[index].minAngle;
    } else if (angle > component[index].maxAngle) {
        this->component[index].angle = component[index].maxAngle;
    } else {
        this->component[index].angle = angle;
    }

    update();
}

void CustomOpenGLWidget::updateAllJoints(float* angles)
{
    for (int i = 0; i < 6; ++i) {
        if (angles[i] < component[i].minAngle) {
            this->component[i].angle = component[i].minAngle;
        } else if (angles[i] > component[i].maxAngle) {
            this->component[i].angle = component[i].maxAngle;
        } else {
            this->component[i].angle = angles[i];
        }
    }

    update();
}

void CustomOpenGLWidget::updateModelColor(int index, float r, float g, float b)
{
    if (index < 0 || index >= 7) {
        return;
    }

    this->component[index].color = glm::vec3(r, g, b);
    update();
}

void CustomOpenGLWidget::setPolygonMode(bool flag)
{
    m_polygonMode = flag;
    update();
}

void CustomOpenGLWidget::setAxisMode(bool flag)
{
    m_axisMode = flag;
    update();
}

void CustomOpenGLWidget::setGridMode(bool flag)
{
    m_gridMode = flag;
    update();
}

bool CustomOpenGLWidget::getPolygonMode()
{
    return m_polygonMode;
}

bool CustomOpenGLWidget::getGridMode()
{
    return m_gridMode;
}

bool CustomOpenGLWidget::getAxisMode()
{
    return m_axisMode;
}

bool CustomOpenGLWidget::getTrackMode()
{
    return m_trackMode;
}

void CustomOpenGLWidget::initGrid()
{
    // 绘制横向的GRID_SIZE个线段
    for (int i = 0; i <= GRID_SIZE; ++i) {
        // 线段起点
        gridVertices.push_back(glm::vec3(-10.0f, 0.0f, -10.0f + i * 2.0f));
        // 线段终点
        gridVertices.push_back(glm::vec3(10.0f, 0.0f, -10.0f + i * 2.0f));
    }
    // 绘制纵向的GRID_SIZE个线段
    for (int i = 0; i <= GRID_SIZE; ++i) {
        // 线段起点
        gridVertices.push_back(glm::vec3(-10.0f + i * 2.0f, 0.0f, -10.0f));
        // 线段终点
        gridVertices.push_back(glm::vec3(-10.0f + i * 2.0f, 0.0f, 10.0f));
    }
}

void CustomOpenGLWidget::setTrackMode(bool flag)
{
    m_trackMode = flag;
    if (m_trackMode) {
        trackVertices.clear();
    }
    update();
}

void CustomOpenGLWidget::renderTrajectory()
{
    // trackVertices.push_back(toolPosition);
    // // 计算要添加的点的数量
    // size_t pointsToAdd = 1;
    // // 添加轨迹点
    // glBindBuffer(GL_ARRAY_BUFFER, m_trackVBO);
    // glBufferSubData(GL_ARRAY_BUFFER, 0, pointsToAdd * sizeof(glm::vec3), trackVertices.data());
    // glBindBuffer(GL_ARRAY_BUFFER, 0);

    // // 绘制轨迹线
    // m_trackShader.use();
    // model = glm::mat4(1.0f);
    // model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    // model = glm::scale(model, glm::vec3(0.1f));
    // m_trackShader.setMat4("model", model);
    // m_trackShader.setMat4("projection", projection);
    // m_trackShader.setMat4("view", view);

    // m_trackVAO.bind();
    // glDrawArrays(GL_LINE_STRIP, 0, trackVertices.size());
    // m_trackVAO.release();
}

void CustomOpenGLWidget::setView(const std::string& view)
{
    camera.setViewDirection(view);
    update();
}

// void CustomOpenGLWidget::motionSlowly(float* targetAngle)
// {
//     int motionDir[6];

//     for (int i = 0; i < 6; ++i) {
//         if (targetAngle[i] >= this->component[i + 1].angle) {
//             motionDir[i] = 1;
//         } else {
//             motionDir[i] = -1;
//         }
//     }

//     connect(&motionTimer, &QTimer::timeout, this, [=]() {
//         static bool inPlace[6] = { false };
//         for (int i = 0; i < 6; i++) {
//             this->component[i + 1].angle += (motionDir[i] * 1.0f);
//             if (component[i + 1].angle >= component[i + 1].maxAngle) {
//                 component[i + 1].angle = component[i + 1].maxAngle;
//                 inPlace[i] = true;
//             } else if (component[i + 1].angle <= component[i + 1].minAngle) {
//                 component[i + 1].angle = component[i + 1].minAngle;
//                 inPlace[i] = true;
//             }
//         }
//         update();
//         bool flag = true;
//         for (int i = 0; i < 6; i++) {
//             if (!inPlace[i]) {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag) {
//             motionTimer.stop();
//         }
//     });
//     motionTimer.start(40);
// }

void CustomOpenGLWidget::updateGridStyle(float width, float r, float g, float b, float a)
{
    if (width > 0.0f) {
        m_gridLineWidth = width;
    }
    if (r >= 0.0f && g >= 0.0f && b >= 0.0f && a >= 0.0f) {
        m_gridColor = glm::vec4(r, g, b, a);
    }
    update();
}

void CustomOpenGLWidget::updateTrackStyle(float width, float r, float g, float b, float a)
{
    if (width > 0.0f) {
        m_trackLineWidth = width;
    }
    if (r >= 0.0f && g >= 0.0f && b >= 0.0f && a >= 0.0f) {
        m_trackColor = glm::vec4(r, g, b, a);
    }
    update();
}
