#include "MainWindow.h"
#include "./ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->slider1, &QSlider::valueChanged, this, [this](int value) {
        ui->label_angle1->setText(QString::number(value));
        ui->openGLWidget->updateAngle(1, (float)value);
    });
    connect(ui->slider2, &QSlider::valueChanged, this, [this](int value) {
        ui->label_angle2->setText(QString::number(value));
        ui->openGLWidget->updateAngle(2, (float)value);
    });
    connect(ui->slider3, &QSlider::valueChanged, this, [this](int value) {
        ui->label_angle3->setText(QString::number(value));
        ui->openGLWidget->updateAngle(3, (float)value);
    });
    connect(ui->slider4, &QSlider::valueChanged, this, [this](int value) {
        ui->label_angle4->setText(QString::number(value));
        ui->openGLWidget->updateAngle(4, (float)value);
    });
    connect(ui->slider5, &QSlider::valueChanged, this, [this](int value) {
        ui->label_angle5->setText(QString::number(value));
        ui->openGLWidget->updateAngle(5, (float)value);
    });
    connect(ui->slider6, &QSlider::valueChanged, this, [this](int value) {
        ui->label_angle6->setText(QString::number(value));
        ui->openGLWidget->updateAngle(6, (float)value);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
