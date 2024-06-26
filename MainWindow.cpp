#include "MainWindow.h"
#include "./ui_MainWindow.h"

int angle[6] = {0};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->slider1, &QSlider::valueChanged, this, [this](int value) {
        angle[0] = value;
        ui->label_angle1->setText(QString::number(value));
        ui->openGLWidget->update();
    });
    connect(ui->slider2, &QSlider::valueChanged, this, [this](int value) {
        angle[1] = value;
        ui->label_angle2->setText(QString::number(value));
        ui->openGLWidget->update();
    });
    connect(ui->slider3, &QSlider::valueChanged, this, [this](int value) {
        angle[2] = value;
        ui->label_angle3->setText(QString::number(value));
        ui->openGLWidget->update();
    });
    connect(ui->slider4, &QSlider::valueChanged, this, [this](int value) {
        angle[3] = value;
        ui->label_angle4->setText(QString::number(value));
        ui->openGLWidget->update();
    });
    connect(ui->slider5, &QSlider::valueChanged, this, [this](int value) {
        angle[4] = value;
        ui->label_angle5->setText(QString::number(value));
        ui->openGLWidget->update();
    });
    connect(ui->slider6, &QSlider::valueChanged, this, [this](int value) {
        angle[5] = value;
        ui->label_angle6->setText(QString::number(value));
        ui->openGLWidget->update();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
