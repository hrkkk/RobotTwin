#include "CustomOpenGLWidget.h"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

CustomOpenGLWidget::CustomOpenGLWidget(QWidget* parent): QOpenGLWidget(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
}

void CustomOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    m_modelShader = Shader("../RobotTwin/modelVertexShader.glsl", "../RobotTwin/modelFragmentShader.glsl");
    m_lightShader = Shader("../RobotTwin/lightVertexShader.glsl", "../RobotTwin/lightFragmentShader.glsl");
    m_coordShader = Shader("../RobotTwin/coordVertexShader.glsl", "../RobotTwin/coordFragmentShader.glsl");

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

    path[0] = "C:\\Users\\hrkkk\\Desktop\\dizuo.obj";
    path[1] = "C:\\Users\\hrkkk\\Desktop\\jizuo.obj";
    path[2] = "C:\\Users\\hrkkk\\Desktop\\dabi.obj";
    path[3] = "C:\\Users\\hrkkk\\Desktop\\pianyi.obj";
    path[4] = "C:\\Users\\hrkkk\\Desktop\\xiaobi.obj";
    path[5] = "C:\\Users\\hrkkk\\Desktop\\xiaoxiaobi.obj";
    path[6] = "C:\\Users\\hrkkk\\Desktop\\zhixingqi.obj";

    for (int i = 0; i < 7; i++) {
        ourModel[i] = new Model(path[i]);
    }

    component[0] = {
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        -180,
        180
    };
    component[1] = {
        glm::vec3(0.0f, 0.042f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        -180,
        180
    };
    component[2] = {
        glm::vec3(0.046f, 0.267f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        -180,
        180
    };
    component[3] = {
        glm::vec3(-0.210f, 0.286f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        -180,
        180
    };
    component[4] = {
        glm::vec3(-0.223f, 0.333f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        -180,
        180
    };
    component[5] = {
        glm::vec3(-0.523f, 0.333f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        -180,
        180
    };
    component[6] = {
        glm::vec3(-0.523f, 0.333f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        -180,
        180
    };

    glClearColor(0.94f, 0.94f, 0.94f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void CustomOpenGLWidget::paintGL()
{
    glClearColor(0.94f, 0.94f, 0.94f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 渲染机械臂模型
    m_modelShader.use();
    m_modelShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
    m_modelShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
    m_modelShader.setVec3("lightPos", 1.0f, 1.0f, 1.0f);
    m_modelShader.setVec3("viewPos", camera.Position);

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)this->width() / (float)this->height(), 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);

    // 基座
    model = glm::translate(model, component[0].origin);     // 平移
    // model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0, 0.0, 0.0));   // 旋转
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));     // 缩放
    m_modelShader.setMat4("projection", projection);
    m_modelShader.setMat4("view", view);
    m_modelShader.setMat4("model", model);
    ourModel[0]->Draw(m_modelShader);
    // 肩部
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[1].origin);
    model = glm::rotate(model, glm::radians(component[1].angle), component[1].axis);
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    m_modelShader.setMat4("model", model);
    ourModel[1]->Draw(m_modelShader);
    // 大臂
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[2].origin);
    model = model * rotateAround(component[1].origin, component[1].axis, glm::radians(component[1].angle));
    model = glm::rotate(model, glm::radians(component[2].angle), component[2].axis);
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    m_modelShader.setMat4("model", model);
    ourModel[2]->Draw(m_modelShader);
    // 小臂1
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[3].origin);
    model = model * rotateAround(component[1].origin, component[1].axis, glm::radians(component[1].angle));
    model = model * rotateAround(component[2].origin, component[2].axis, glm::radians(component[2].angle));
    model = glm::rotate(model, glm::radians(component[3].angle), component[3].axis);
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    m_modelShader.setMat4("model", model);
    ourModel[3]->Draw(m_modelShader);
    // 小臂2
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[4].origin);
    model = model * rotateAround(component[1].origin, component[1].axis, glm::radians(component[1].angle));
    model = model * rotateAround(component[2].origin, component[2].axis, glm::radians(component[2].angle));
    model = model * rotateAround(component[3].origin, component[3].axis, glm::radians(component[3].angle));
    model = glm::rotate(model, glm::radians(component[4].angle), component[4].axis);
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    m_modelShader.setMat4("model", model);
    ourModel[4]->Draw(m_modelShader);
    // 手腕
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[5].origin);
    model = model * rotateAround(component[1].origin, component[1].axis, glm::radians(component[1].angle));
    model = model * rotateAround(component[2].origin, component[2].axis, glm::radians(component[2].angle));
    model = model * rotateAround(component[3].origin, component[3].axis, glm::radians(component[3].angle));
    model = model * rotateAround(component[4].origin, component[4].axis, glm::radians(component[4].angle));
    model = glm::rotate(model, glm::radians(component[5].angle), component[5].axis);
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    m_modelShader.setMat4("model", model);
    ourModel[5]->Draw(m_modelShader);
    // 末端工具
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[6].origin);
    model = model * rotateAround(component[1].origin, component[1].axis, glm::radians(component[1].angle));
    model = model * rotateAround(component[2].origin, component[2].axis, glm::radians(component[2].angle));
    model = model * rotateAround(component[3].origin, component[3].axis, glm::radians(component[3].angle));
    model = model * rotateAround(component[4].origin, component[4].axis, glm::radians(component[4].angle));
    model = model * rotateAround(component[5].origin, component[5].axis, glm::radians(component[5].angle));
    model = glm::rotate(model, glm::radians(component[6].angle), component[6].axis);
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    m_modelShader.setMat4("model", model);
    ourModel[6]->Draw(m_modelShader);

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

    // 渲染坐标轴
    m_coordShader.use();
    model = glm::mat4(1.0f);
    model = glm::translate(model, component[0].origin);
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

void CustomOpenGLWidget::resizeGL(int w, int h)
{

}

void CustomOpenGLWidget::wheelEvent(QWheelEvent* event)
{
    camera.ProcessMouseScroll(static_cast<float>(event->angleDelta().y() / 100.0f));
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
    switch (event->key()) {
    case Qt::Key_W:
        camera.ProcessKeyboard(FORWARD, 0.5);
        break;
    case Qt::Key_S:
        camera.ProcessKeyboard(BACKWARD, 0.5);
        break;
    case Qt::Key_A:
        camera.ProcessKeyboard(LEFT, 0.5);
        break;
    case Qt::Key_D:
        camera.ProcessKeyboard(RIGHT, 0.5);
        break;
    }
    update();
}

glm::mat4 CustomOpenGLWidget::rotateAround(const glm::vec3& center, const glm::vec3& axis, float angle)
{
    // 计算旋转矩阵
    glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, axis);

    // 创建一个平移矩阵，将旋转中心移动到原点
    glm::mat4 translationToCenter = glm::translate(glm::mat4(1.0f), -center);

    // 创建一个平移矩阵，将旋转后的点移回原来的位置
    glm::mat4 translationFromCenter = glm::translate(glm::mat4(1.0f), center);

    // 组合矩阵以实现绕点旋转
    glm::mat4 rotateAroundMatrix = translationFromCenter * rotationMatrix * translationToCenter;

    return rotateAroundMatrix;
}

void CustomOpenGLWidget::updateAngle(int index, float angle)
{
    if (index < 0 || index > 6) {
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
