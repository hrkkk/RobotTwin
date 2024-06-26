#include "CustomOpenGLWidget.h"

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

CustomOpenGLWidget::CustomOpenGLWidget(QWidget* parent): QOpenGLWidget(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
}

void CustomOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    m_modelShader = Shader("../../modelVertexShader.glsl", "../../modelFragmentShader.glsl");
    m_lightShader = Shader("../../lightVertexShader.glsl", "../../lightFragmentShader.glsl");

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

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void CustomOpenGLWidget::paintGL()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
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

    // render the loaded model
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));     // 平移
    model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0, 0.0, 0.0));   // 旋转
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));     // 缩放
    m_modelShader.setMat4("projection", projection);
    m_modelShader.setMat4("view", view);
    m_modelShader.setMat4("model", model);
    ourModel[0]->Draw(m_modelShader);

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f,  0.042f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    m_modelShader.setMat4("model", model);
    ourModel[1]->Draw(m_modelShader);

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.046f, 0.267f,  0.0f)); // translate it down so it's at the center of the scene
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    m_modelShader.setMat4("model", model);
    ourModel[2]->Draw(m_modelShader);

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-0.210f, 0.286f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(1.0, 0.0, 0.0));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    m_modelShader.setMat4("model", model);
    ourModel[3]->Draw(m_modelShader);

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-0.223f, 0.333f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    m_modelShader.setMat4("model", model);
    ourModel[4]->Draw(m_modelShader);

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(-0.523f, 0.333f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0.0, 0.0, 1.0));
    model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0, 0.0, 0.0));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    m_modelShader.setMat4("model", model);
    ourModel[5]->Draw(m_modelShader);

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
}

void CustomOpenGLWidget::resizeGL(int w, int h)
{

}

void CustomOpenGLWidget::wheelEvent(QWheelEvent* event)
{
    camera.ProcessMouseScroll(static_cast<float>(event->angleDelta().y() / 100.0f));
    update();
}

void CustomOpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{
    float xpos = static_cast<float>(event->pos().x());
    float ypos = static_cast<float>(event->pos().y());

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
    update();
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

