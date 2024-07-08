#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QColorDialog>
#include <QMessageBox>
#include <QSettings>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置OpenGL版本为4.1核心模式
    QSurfaceFormat format;
    format.setVersion(4, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);
    ui->openGLWidget->setFormat(format);

    this->showMaximized();
    ui->groupBox_gridSetting->hide();
    ui->groupBox_trackSetting->hide();

    ui->tabWidget->tabBar()->hide();
    this->setWindowFlags(Qt::FramelessWindowHint);

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

    connect(ui->btn_min, &QPushButton::clicked, this, [=]() {
        this->showMinimized();
    });
    connect(ui->btn_max, &QPushButton::clicked, this, [=]() {
        if (this->isMaximized()) {
            this->showNormal();
        } else {
            this->showMaximized();
        }
    });
    connect(ui->btn_close, &QPushButton::clicked, this, [=]() {
        this->close();
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
    connect(ui->btn_saveColor, &QPushButton::clicked, this, [this]() {
        // QString filePath = "../color1.ini";
        // QSettings settings(filePath, QSettings::IniFormat);
        // QColor modelColors[7]={(255,0,0),(0,255,0),(0,0,255),(255,255,0),(255,0,255),(0,255,255),(0,0,0)};
        // for (int i = 0; i < 7; ++i) {
        //     settings.setValue(QString("ModelColors/Model%1").arg(i + 1), modelColors[i]);
        // }
    });
    connect(ui->btn_setColor, &QPushButton::clicked, this, [this]() {
        QString filePath = QFileDialog::getOpenFileName(this, "Open INI File", "", "INI Files (*.ini)");
        if (!filePath.isEmpty()) {
            QVector<QColor> colors;
            QSettings settings(filePath, QSettings::IniFormat);
            int i = 1;
            while (settings.contains(QString("ModelColors/Model%1").arg(i))) {
                colors.append(settings.value(QString("ModelColors/Model%1").arg(i)).value<QColor>());
                ++i;
            }
            for (int i = 0; i < 7; ++i) {
                qDebug() << "Model" << i + 1 << "Color:" << colors[i];
            }
        }

    });

    connect(ui->checkBox_polygonMode, &QCheckBox::clicked, this, [this](bool isChecked) {
        ui->openGLWidget->setPolygonMode(isChecked);
    });
    connect(ui->checkBox_axisMode, &QCheckBox::clicked, this, [this](bool isChecked) {
        ui->openGLWidget->setAxisMode(isChecked);
    });
    connect(ui->checkBox_gridMode, &QCheckBox::clicked, this, [this](bool isChecked) {
        if (isChecked) {
            ui->groupBox_gridSetting->show();
        } else {
            ui->groupBox_gridSetting->hide();
        }
        ui->openGLWidget->setGridMode(isChecked);
    });
    connect(ui->checkBox_trackMode, &QCheckBox::clicked, this, [this](bool isChecked) {
        if (isChecked) {
            ui->groupBox_trackSetting->show();
        } else {
            ui->groupBox_trackSetting->hide();
        }
        ui->openGLWidget->setTrackMode(isChecked);
    });

    ui->lineEdit_x->setText(QString::number(400));
    ui->lineEdit_y->setText(QString::number(200));
    ui->lineEdit_z->setText(QString::number(100));
    ui->lineEdit_alpha->setText(QString::number(90));
    ui->lineEdit_beta->setText(QString::number(0));
    ui->lineEdit_gamma->setText(QString::number(-90));

    connect(serialPort, &SerialPort::dataReceived, this, [=](const QByteArray& data) {
        analyseData(data);
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
        ui->comboBox_serialList->clear();
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

    connect(ui->btn_front, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget->setView("front");
    });
    connect(ui->btn_back, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget->setView("back");
    });
    connect(ui->btn_left, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget->setView("left");
    });
    connect(ui->btn_right, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget->setView("right");
    });
    connect(ui->btn_up, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget->setView("up");
    });
    connect(ui->btn_down, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget->setView("down");
    });

    connect(ui->btn_gridColor, &QPushButton::clicked, this, [=]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateGridStyle(-1, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF(), selectedColor.alphaF());
            ui->btn_gridColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                              .arg(selectedColor.green())\
                                              .arg(selectedColor.blue()));
        }
    });
    connect(ui->btn_trackColor, &QPushButton::clicked, this, [=]() {
        QColor selectedColor = QColorDialog::getColor(Qt::white, nullptr, "选择颜色", QColorDialog::ShowAlphaChannel);
        // 检查用户是否点击了“确定”按钮
        if (selectedColor.isValid()) {
            ui->openGLWidget->updateTrackStyle(-1, selectedColor.redF(), selectedColor.greenF(), selectedColor.blueF(), selectedColor.alphaF());
            ui->btn_trackColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3);").arg(selectedColor.red())\
                                                 .arg(selectedColor.green())\
                                                 .arg(selectedColor.blue()));
        }
    });
    connect(ui->dSpinBox_gridWidth, &QDoubleSpinBox::valueChanged, this, [=](double value) {
        ui->openGLWidget->updateGridStyle((float)value, -1, -1, -1, -1);
    });
    connect(ui->dSpinBox_trackWidth, &QDoubleSpinBox::valueChanged, this, [=](double value) {
        ui->openGLWidget->updateTrackStyle((float)value, -1, -1, -1, -1);
    });

    connect(ui->btn_lineMode, &QPushButton::clicked, this, [=]() {
        if (ui->openGLWidget->getPolygonMode()) {
            ui->openGLWidget->setPolygonMode(false);
            ui->btn_lineMode->setStyleSheet("background-color:#ffffff");
        } else {
            ui->openGLWidget->setPolygonMode(true);
            ui->btn_lineMode->setStyleSheet("background-color:#2b7beb");
        }
    });
    connect(ui->btn_gridMode, &QPushButton::clicked, this, [=]() {
        if (ui->openGLWidget->getGridMode()) {
            ui->openGLWidget->setGridMode(false);
            ui->btn_gridMode->setStyleSheet("background-color:#ffffff");
        } else {
            ui->openGLWidget->setGridMode(true);
            ui->btn_gridMode->setStyleSheet("background-color:#2b7beb");
        }
    });
    connect(ui->btn_axisMode, &QPushButton::clicked, this, [=]() {
        if (ui->openGLWidget->getAxisMode()) {
            ui->openGLWidget->setAxisMode(false);
            ui->btn_axisMode->setStyleSheet("background-color:#ffffff");
        } else {
            ui->openGLWidget->setAxisMode(true);
            ui->btn_axisMode->setStyleSheet("background-color:#2b7beb");
        }
    });
    connect(ui->btn_trackMode, &QPushButton::clicked, this, [=]() {
        if (ui->openGLWidget->getTrackMode()) {
            ui->openGLWidget->setTrackMode(false);
            ui->btn_trackMode->setStyleSheet("background-color:#ffffff");
        } else {
            ui->openGLWidget->setTrackMode(true);
            ui->btn_trackMode->setStyleSheet("background-color:#2b7beb");
        }
    });

    QStringList tabTitles;
    tabTitles << "运动控制" << "模型设置" << "场景设置" << "串口通信";
    for (int i = 0; i < tabTitles.size(); i++) {
        QPushButton* btn = ui->widget_5->findChild<QPushButton*>(QString("btn_tab%1").arg(i + 1));
        connect(btn, &QPushButton::clicked, this, [=]() {
            ui->tabWidget->setCurrentIndex(i);
            ui->label_tabTitle->setText(tabTitles[i]);
        });
    }
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
    // ui->openGLWidget->motionSlowly(degree);

    for (int i = 1; i <= 6; ++i) {
        QLabel* label = ui->tab->findChild<QLabel*>(QString("label_joint%1").arg(i));
        QSlider* slider = ui->tab->findChild<QSlider*>(QString("slider%1").arg(i));
        slider->setValue(degree[i - 1]);
        label->setText(QString::number(degree[i - 1]));
    }
}

void MainWindow::analyseData(const QByteArray& data)
{
    qDebug() << "received: " << data;
    qDebug() << data.size();
    float angles[6] = { 0.0f };
    if (data.size() == 20 && data[0] == (char)0xFF && data[1] == (char)0xFE) {
        for (int i = 0; i < 6; i++) {
            int signal = 1;
            if (data[2 + i * 3] == (char)0xEE) {
                signal = 1;
            } else if (data[2 + i * 3] == (char)0x01) {
                signal = -1;
            }
            uint8_t highByte = data[3 + i * 3];
            uint8_t lowByte = data[4 + i * 3];
            uint16_t num = (highByte << 8) | lowByte;
            angles[i] = (float)(signal * num);
        }
    }
    qDebug() << "analysed: ";
    for (int i = 0; i < 6; ++i) {
        qDebug() << angles[i] << " ";
    }

}
