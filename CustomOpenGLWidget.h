#pragma once

#include "Render.h"

#include <QOpenGLWidget>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QKeyEvent>

class CustomOpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit CustomOpenGLWidget(QWidget* parent = nullptr);

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
    bool getPolygonMode();
    bool getGridMode();
    bool getAxisMode();
    bool getTrackMode();
    bool getExplodeMode();
    bool getNormalMode();
    void setView(const std::string& dir);

signals:
    void sig_updateViewZoom(float x);
    void sig_updateFps(float fps);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    Render* m_render;
};

