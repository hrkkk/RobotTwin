#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QColorDialog>

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
    connect(ui->btn_color1, &QPushButton::clicked, this, [this]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateModelColor(0, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF());
            ui->btn_color1->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                          .arg(selectedColor.green())\
                                              .arg(selectedColor.blue()));
        }
    });
    connect(ui->btn_color2, &QPushButton::clicked, this, [this]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateModelColor(1, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF());
            ui->btn_color2->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                              .arg(selectedColor.green())\
                                              .arg(selectedColor.blue()));
        }
    });
    connect(ui->btn_color3, &QPushButton::clicked, this, [this]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateModelColor(2, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF());
            ui->btn_color3->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                              .arg(selectedColor.green())\
                                              .arg(selectedColor.blue()));
        }
    });
    connect(ui->btn_color4, &QPushButton::clicked, this, [this]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateModelColor(3, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF());
            ui->btn_color4->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                              .arg(selectedColor.green())\
                                              .arg(selectedColor.blue()));
        }
    });
    connect(ui->btn_color5, &QPushButton::clicked, this, [this]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateModelColor(4, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF());
            ui->btn_color5->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                              .arg(selectedColor.green())\
                                              .arg(selectedColor.blue()));
        }
    });
    connect(ui->btn_color6, &QPushButton::clicked, this, [this]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateModelColor(5, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF());
            ui->btn_color6->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                              .arg(selectedColor.green())\
                                              .arg(selectedColor.blue()));
        }
    });
    connect(ui->btn_color7, &QPushButton::clicked, this, [this]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateModelColor(6, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF());
            ui->btn_color7->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                              .arg(selectedColor.green())\
                                              .arg(selectedColor.blue()));
        }
    });
    connect(ui->checkBox_polygonMode, &QCheckBox::clicked, this, [this](bool isChecked) {
        ui->openGLWidget->setPolygonMode(isChecked);
    });
    connect(ui->checkBox_axisMode, &QCheckBox::clicked, this, [this](bool isChecked) {
        ui->openGLWidget->setAxisMode(isChecked);
    });
    connect(ui->checkBox_gridMode, &QCheckBox::clicked, this, [this](bool isChecked) {
        ui->openGLWidget->setGridMode(isChecked);
    });
    connect(ui->checkBox_trackMode, &QCheckBox::clicked, this, [this](bool isChecked) {
        ui->openGLWidget->setTrackMode(isChecked);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
