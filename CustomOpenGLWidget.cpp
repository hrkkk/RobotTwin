#include "CustomOpenGLWidget.h"

CustomOpenGLWidget::CustomOpenGLWidget(QWidget* parent): QOpenGLWidget(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);

    m_render = new Render();
}

void CustomOpenGLWidget::initializeGL()
{
    m_render->setWindowSize(width(), height());
    m_render->initRender();
}


void CustomOpenGLWidget::paintGL()
{
    m_render->paintRender();
}

void CustomOpenGLWidget::resizeGL(int w, int h)
{
    m_render->resizeRender();
}

void CustomOpenGLWidget::wheelEvent(QWheelEvent* event)
{
    float ret = m_render->wheelEvent(event->angleDelta().y());
    emit sig_updateViewZoom(ret);
    update();
}


void CustomOpenGLWidget::mousePressEvent(QMouseEvent* event)
{
    m_render->mousePressEvent(event->position().x(), event->position().y());
}

void CustomOpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (m_render->mouseMoveEvent(event->position().x(), event->position().y())) {
        update();
    }
}

void CustomOpenGLWidget::updateSingleJoint(int index, float angle) {
    m_render->updateSingleJoint(index, angle);
    update();
}

void CustomOpenGLWidget::updateAllJoints(float *angles) {
    m_render->updateAllJoints(angles);
    update();
}

void CustomOpenGLWidget::updateModelColor(int index, float r, float g, float b) {
    m_render->updateModelColor(index, r, g, b);
    update();
}

void CustomOpenGLWidget::updateGridStyle(float width, float r, float g, float b, float a) {
    m_render->updateGridStyle(width, r, g, b, a);
    update();
}

void CustomOpenGLWidget::updateTrackStyle(float width, float r, float g, float b, float a) {
    m_render->updateTrackStyle(width, r, g, b, a);
    update();
}

void CustomOpenGLWidget::setPolygonMode(bool flag) {
    m_render->setPolygonMode(flag);
    update();
}

void CustomOpenGLWidget::setGridMode(bool flag) {
    m_render->setGridMode(flag);
    update();
}

void CustomOpenGLWidget::setAxisMode(bool flag) {
    m_render->setAxisMode(flag);
    update();
}

void CustomOpenGLWidget::setTrackMode(bool flag) {
    m_render->setTrackMode(flag);
    update();
}

bool CustomOpenGLWidget::getPolygonMode() {
    return m_render->getPolygonMode();
}

bool CustomOpenGLWidget::getGridMode() {
    return m_render->getGridMode();
}

bool CustomOpenGLWidget::getAxisMode() {
    return m_render->getAxisMode();
}

bool CustomOpenGLWidget::getTrackMode() {
    return m_render->getTrackMode();
}

void CustomOpenGLWidget::setView(const std::string &dir) {
    m_render->setView(dir);
    update();
}