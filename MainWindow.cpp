#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QColorDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arm = ARM();
    serialPort = new SerialPort(this);

    for (int i = 1; i <= 6; ++i) {
        QSlider* slider = ui->tab->findChild<QSlider*>(QString("slider%1").arg(i));
        QLabel* label = ui->tab->findChild<QLabel*>(QString("label_joint%1").arg(i));

        connect(slider, &QSlider::valueChanged, this, [label, i, this](int value) {
            label->setText(QString::number(value));
            ui->openGLWidget->updateSingleJoint(i, (float)value);
        });

        connect(slider, &QSlider::sliderReleased, this, [this]() {
            if (serialPort->isOpen()) {
                arm.optimalSolution.theta1 = arm.deg2rad(ui->slider1->value());
                arm.optimalSolution.theta2 = arm.deg2rad(ui->slider2->value());
                arm.optimalSolution.theta3 = arm.deg2rad(ui->slider3->value());
                arm.optimalSolution.theta4 = arm.deg2rad(ui->slider4->value());
                arm.optimalSolution.theta5 = arm.deg2rad(ui->slider5->value());
                arm.optimalSolution.theta6 = arm.deg2rad(ui->slider6->value());
                const QByteArray DATA = arm.createDataFrame(arm.optimalSolution);
                serialPort->sendData(DATA);
            }
        });
    }

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

    ui->lineEdit_x->setText(QString::number(400));
    ui->lineEdit_y->setText(QString::number(200));
    ui->lineEdit_z->setText(QString::number(100));
    ui->lineEdit_alpha->setText(QString::number(90));
    ui->lineEdit_beta->setText(QString::number(0));
    ui->lineEdit_gamma->setText(QString::number(-90));

    connect(serialPort, &SerialPort::dataReceived, this, [=](const QString& data) {
        ui->textEdit_input->append(data);
    });
    connect(serialPort, &SerialPort::errorOccurred, this, [=](const QString &errorString) {
        QMessageBox::critical(this, "Error", errorString);
    });
    connect(ui->btn_cacl, &QPushButton::clicked, this, [=]() {
        startCacl();
    });
    connect(ui->btn_connectSerial, &QPushButton::clicked, this, [=]() {
        if (ui->btn_connectSerial->text() == "连接串口") {
            if (serialPort->openPort(ui->comboBox_serialList->currentText())) {
                // QMessageBox::information(this, "Info", "Connected to serial port");
                ui->label_serialState->setText("已连接");
                ui->btn_connectSerial->setText("断开连接");
            }
        } else if (ui->btn_connectSerial->text() == "断开连接") {
            serialPort->closePort();
            ui->label_serialState->setText("未连接");
            ui->btn_connectSerial->setText("连接串口");
        }
    });
    connect(ui->btn_send, &QPushButton::clicked, this, [=]() {
        const QByteArray DATA = arm.createDataFrame(arm.optimalSolution);
        serialPort->sendData(DATA);
    });
    connect(ui->btn_searchSerial, &QPushButton::clicked, this, [=]() {
        QList<QSerialPortInfo> serialList = QSerialPortInfo::availablePorts();
        foreach (const QSerialPortInfo &info, serialList) {
            ui->comboBox_serialList->addItem(info.portName());
        }
    });
    connect(ui->btn_reset, &QPushButton::clicked, this, [=]() {
        for (int i = 1; i <= 6; ++i) {
            QLabel* label = ui->tab->findChild<QLabel*>(QString("label_joint%1").arg(i));
            QSlider* slider = ui->tab->findChild<QSlider*>(QString("slider%1").arg(i));
            slider->setValue(0);
            label->setText(QString::number(0));
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startCacl()
{
    bool ok;

    arm.Arm_data.px = ui->lineEdit_x->text().toDouble(&ok);
    arm.Arm_data.py = ui->lineEdit_y->text().toDouble(&ok);
    arm.Arm_data.pz = ui->lineEdit_z->text().toDouble(&ok);
    arm.Arm_data.alpha = ui->lineEdit_alpha->text().toDouble(&ok);
    arm.Arm_data.beta = ui->lineEdit_beta->text().toDouble(&ok);
    arm.Arm_data.gamma = ui->lineEdit_gamma->text().toDouble(&ok);

    arm.Calc_Ik();

    float degree[6];
    degree[0] = (float)arm.rad2deg(arm.optimalSolution.theta1);
    degree[1] = (float)arm.rad2deg(arm.optimalSolution.theta2);
    degree[2] = (float)arm.rad2deg(arm.optimalSolution.theta3);
    degree[3] = (float)arm.rad2deg(arm.optimalSolution.theta4);
    degree[4] = (float)arm.rad2deg(arm.optimalSolution.theta5);
    degree[5] = (float)arm.rad2deg(arm.optimalSolution.theta6);

    for (int i = 1; i <= 6; ++i) {
        QLineEdit* lineEdit = ui->groupBox_3->findChild<QLineEdit*>(QString("lineEdit_calc_best_%1").arg(i));
        lineEdit->setText(QString::number(degree[i - 1]));
    }

    ui->openGLWidget->updateAllJoints(degree);

    for (int i = 1; i <= 6; ++i) {
        QLabel* label = ui->tab->findChild<QLabel*>(QString("label_joint%1").arg(i));
        QSlider* slider = ui->tab->findChild<QSlider*>(QString("slider%1").arg(i));
        slider->setValue(degree[i - 1]);
        label->setText(QString::number(degree[i - 1]));
    }
}
