/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CustomOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_9;
    CustomOpenGLWidget *openGLWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_joint1;
    QSlider *slider1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_joint2;
    QSlider *slider2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *label_joint3;
    QSlider *slider3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *label_joint4;
    QSlider *slider4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *label_joint5;
    QSlider *slider5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *label_joint6;
    QSlider *slider6;
    QPushButton *btn_reset;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QPushButton *btn_color1;
    QLabel *label_8;
    QPushButton *btn_color2;
    QLabel *label_9;
    QPushButton *btn_color3;
    QLabel *label_10;
    QPushButton *btn_color4;
    QLabel *label_11;
    QPushButton *btn_color5;
    QLabel *label_12;
    QPushButton *btn_color6;
    QLabel *label_13;
    QPushButton *btn_color7;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_14;
    QGridLayout *gridLayout;
    QPushButton *btn_left;
    QPushButton *btn_right;
    QPushButton *btn_down;
    QPushButton *btn_front;
    QPushButton *btn_back;
    QPushButton *btn_up;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_gridMode;
    QCheckBox *checkBox_axisMode;
    QCheckBox *checkBox_polygonMode;
    QCheckBox *checkBox_trackMode;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_16;
    QComboBox *comboBox_serialList;
    QPushButton *btn_searchSerial;
    QPushButton *btn_connectSerial;
    QLabel *label_17;
    QTextEdit *textEdit_input;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_18;
    QLineEdit *lineEdit_x;
    QLabel *label_19;
    QLineEdit *lineEdit_y;
    QLabel *label_20;
    QLineEdit *lineEdit_z;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *lineEdit_alpha;
    QLineEdit *lineEdit_beta;
    QLineEdit *lineEdit_gamma;
    QPushButton *btn_cacl;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_calc_best_3;
    QLineEdit *lineEdit_calc_best_5;
    QLineEdit *lineEdit_calc_best_2;
    QLineEdit *lineEdit_calc_best_4;
    QLineEdit *lineEdit_calc_best_1;
    QLineEdit *lineEdit_calc_best_6;
    QPushButton *btn_send;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_25;
    QLabel *label_serialState;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1134, 778);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, -1, -1, -1);
        openGLWidget = new CustomOpenGLWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");

        horizontalLayout_9->addWidget(openGLWidget);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(tab);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        label_joint1 = new QLabel(tab);
        label_joint1->setObjectName("label_joint1");

        horizontalLayout_2->addWidget(label_joint1, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_2);

        slider1 = new QSlider(tab);
        slider1->setObjectName("slider1");
        slider1->setMinimum(-180);
        slider1->setMaximum(180);
        slider1->setValue(0);
        slider1->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        label_joint2 = new QLabel(tab);
        label_joint2->setObjectName("label_joint2");

        horizontalLayout_3->addWidget(label_joint2, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_3);

        slider2 = new QSlider(tab);
        slider2->setObjectName("slider2");
        slider2->setMinimum(-180);
        slider2->setMaximum(180);
        slider2->setValue(0);
        slider2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        label_joint3 = new QLabel(tab);
        label_joint3->setObjectName("label_joint3");

        horizontalLayout_4->addWidget(label_joint3, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_4);

        slider3 = new QSlider(tab);
        slider3->setObjectName("slider3");
        slider3->setMinimum(-180);
        slider3->setMaximum(180);
        slider3->setValue(0);
        slider3->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        label_joint4 = new QLabel(tab);
        label_joint4->setObjectName("label_joint4");

        horizontalLayout_5->addWidget(label_joint4, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_5);

        slider4 = new QSlider(tab);
        slider4->setObjectName("slider4");
        slider4->setMinimum(-180);
        slider4->setMaximum(180);
        slider4->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        label_joint5 = new QLabel(tab);
        label_joint5->setObjectName("label_joint5");

        horizontalLayout_6->addWidget(label_joint5, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_6);

        slider5 = new QSlider(tab);
        slider5->setObjectName("slider5");
        slider5->setMinimum(-180);
        slider5->setMaximum(180);
        slider5->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        label_joint6 = new QLabel(tab);
        label_joint6->setObjectName("label_joint6");

        horizontalLayout_7->addWidget(label_joint6, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_7);

        slider6 = new QSlider(tab);
        slider6->setObjectName("slider6");
        slider6->setMinimum(-180);
        slider6->setMaximum(180);
        slider6->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider6);

        btn_reset = new QPushButton(tab);
        btn_reset->setObjectName("btn_reset");

        verticalLayout->addWidget(btn_reset);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");

        verticalLayout_2->addWidget(label_7);

        btn_color1 = new QPushButton(tab_2);
        btn_color1->setObjectName("btn_color1");
        btn_color1->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(btn_color1);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");

        verticalLayout_2->addWidget(label_8);

        btn_color2 = new QPushButton(tab_2);
        btn_color2->setObjectName("btn_color2");

        verticalLayout_2->addWidget(btn_color2);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName("label_9");

        verticalLayout_2->addWidget(label_9);

        btn_color3 = new QPushButton(tab_2);
        btn_color3->setObjectName("btn_color3");

        verticalLayout_2->addWidget(btn_color3);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName("label_10");

        verticalLayout_2->addWidget(label_10);

        btn_color4 = new QPushButton(tab_2);
        btn_color4->setObjectName("btn_color4");

        verticalLayout_2->addWidget(btn_color4);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName("label_11");

        verticalLayout_2->addWidget(label_11);

        btn_color5 = new QPushButton(tab_2);
        btn_color5->setObjectName("btn_color5");

        verticalLayout_2->addWidget(btn_color5);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName("label_12");

        verticalLayout_2->addWidget(label_12);

        btn_color6 = new QPushButton(tab_2);
        btn_color6->setObjectName("btn_color6");

        verticalLayout_2->addWidget(btn_color6);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");

        verticalLayout_2->addWidget(label_13);

        btn_color7 = new QPushButton(tab_2);
        btn_color7->setObjectName("btn_color7");

        verticalLayout_2->addWidget(btn_color7);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_14 = new QLabel(tab_3);
        label_14->setObjectName("label_14");

        verticalLayout_3->addWidget(label_14);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btn_left = new QPushButton(tab_3);
        btn_left->setObjectName("btn_left");
        btn_left->setMinimumSize(QSize(30, 30));
        btn_left->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/leftView.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_left->setIcon(icon);

        gridLayout->addWidget(btn_left, 1, 0, 1, 1);

        btn_right = new QPushButton(tab_3);
        btn_right->setObjectName("btn_right");
        btn_right->setMinimumSize(QSize(30, 30));
        btn_right->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/rightView.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_right->setIcon(icon1);

        gridLayout->addWidget(btn_right, 1, 2, 1, 1);

        btn_down = new QPushButton(tab_3);
        btn_down->setObjectName("btn_down");
        btn_down->setMinimumSize(QSize(30, 30));
        btn_down->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/bottomView.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_down->setIcon(icon2);

        gridLayout->addWidget(btn_down, 2, 1, 1, 1);

        btn_front = new QPushButton(tab_3);
        btn_front->setObjectName("btn_front");
        btn_front->setMinimumSize(QSize(30, 30));
        btn_front->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/frontView.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_front->setIcon(icon3);

        gridLayout->addWidget(btn_front, 1, 1, 1, 1);

        btn_back = new QPushButton(tab_3);
        btn_back->setObjectName("btn_back");
        btn_back->setMinimumSize(QSize(30, 30));
        btn_back->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/backView.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_back->setIcon(icon4);

        gridLayout->addWidget(btn_back, 1, 3, 1, 1);

        btn_up = new QPushButton(tab_3);
        btn_up->setObjectName("btn_up");
        btn_up->setMinimumSize(QSize(30, 30));
        btn_up->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/topView.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_up->setIcon(icon5);

        gridLayout->addWidget(btn_up, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        label_15 = new QLabel(tab_3);
        label_15->setObjectName("label_15");

        verticalLayout_3->addWidget(label_15);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        checkBox_gridMode = new QCheckBox(tab_3);
        checkBox_gridMode->setObjectName("checkBox_gridMode");

        verticalLayout_4->addWidget(checkBox_gridMode);

        checkBox_axisMode = new QCheckBox(tab_3);
        checkBox_axisMode->setObjectName("checkBox_axisMode");

        verticalLayout_4->addWidget(checkBox_axisMode);

        checkBox_polygonMode = new QCheckBox(tab_3);
        checkBox_polygonMode->setObjectName("checkBox_polygonMode");

        verticalLayout_4->addWidget(checkBox_polygonMode);

        checkBox_trackMode = new QCheckBox(tab_3);
        checkBox_trackMode->setObjectName("checkBox_trackMode");

        verticalLayout_4->addWidget(checkBox_trackMode);


        verticalLayout_3->addLayout(verticalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        verticalLayout_6 = new QVBoxLayout(tab_4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName("groupBox");
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_16 = new QLabel(groupBox);
        label_16->setObjectName("label_16");

        horizontalLayout_8->addWidget(label_16);

        comboBox_serialList = new QComboBox(groupBox);
        comboBox_serialList->setObjectName("comboBox_serialList");

        horizontalLayout_8->addWidget(comboBox_serialList);

        btn_searchSerial = new QPushButton(groupBox);
        btn_searchSerial->setObjectName("btn_searchSerial");

        horizontalLayout_8->addWidget(btn_searchSerial);

        btn_connectSerial = new QPushButton(groupBox);
        btn_connectSerial->setObjectName("btn_connectSerial");

        horizontalLayout_8->addWidget(btn_connectSerial);


        verticalLayout_5->addLayout(horizontalLayout_8);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName("label_17");

        verticalLayout_5->addWidget(label_17);

        textEdit_input = new QTextEdit(groupBox);
        textEdit_input->setObjectName("textEdit_input");

        verticalLayout_5->addWidget(textEdit_input);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName("formLayout");
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_18);

        lineEdit_x = new QLineEdit(groupBox_2);
        lineEdit_x->setObjectName("lineEdit_x");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_x);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName("label_19");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_19);

        lineEdit_y = new QLineEdit(groupBox_2);
        lineEdit_y->setObjectName("lineEdit_y");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_y);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName("label_20");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_20);

        lineEdit_z = new QLineEdit(groupBox_2);
        lineEdit_z->setObjectName("lineEdit_z");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_z);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName("label_21");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_21);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName("label_22");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_22);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName("label_23");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_23);

        lineEdit_alpha = new QLineEdit(groupBox_2);
        lineEdit_alpha->setObjectName("lineEdit_alpha");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_alpha);

        lineEdit_beta = new QLineEdit(groupBox_2);
        lineEdit_beta->setObjectName("lineEdit_beta");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_beta);

        lineEdit_gamma = new QLineEdit(groupBox_2);
        lineEdit_gamma->setObjectName("lineEdit_gamma");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_gamma);

        btn_cacl = new QPushButton(groupBox_2);
        btn_cacl->setObjectName("btn_cacl");

        formLayout->setWidget(6, QFormLayout::SpanningRole, btn_cacl);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName("gridLayout_2");
        lineEdit_calc_best_3 = new QLineEdit(groupBox_3);
        lineEdit_calc_best_3->setObjectName("lineEdit_calc_best_3");

        gridLayout_2->addWidget(lineEdit_calc_best_3, 0, 2, 1, 1);

        lineEdit_calc_best_5 = new QLineEdit(groupBox_3);
        lineEdit_calc_best_5->setObjectName("lineEdit_calc_best_5");

        gridLayout_2->addWidget(lineEdit_calc_best_5, 1, 1, 1, 1);

        lineEdit_calc_best_2 = new QLineEdit(groupBox_3);
        lineEdit_calc_best_2->setObjectName("lineEdit_calc_best_2");

        gridLayout_2->addWidget(lineEdit_calc_best_2, 0, 1, 1, 1);

        lineEdit_calc_best_4 = new QLineEdit(groupBox_3);
        lineEdit_calc_best_4->setObjectName("lineEdit_calc_best_4");

        gridLayout_2->addWidget(lineEdit_calc_best_4, 1, 0, 1, 1);

        lineEdit_calc_best_1 = new QLineEdit(groupBox_3);
        lineEdit_calc_best_1->setObjectName("lineEdit_calc_best_1");

        gridLayout_2->addWidget(lineEdit_calc_best_1, 0, 0, 1, 1);

        lineEdit_calc_best_6 = new QLineEdit(groupBox_3);
        lineEdit_calc_best_6->setObjectName("lineEdit_calc_best_6");

        gridLayout_2->addWidget(lineEdit_calc_best_6, 1, 2, 1, 1);

        btn_send = new QPushButton(groupBox_3);
        btn_send->setObjectName("btn_send");

        gridLayout_2->addWidget(btn_send, 2, 0, 1, 3);


        verticalLayout_5->addWidget(groupBox_3);


        verticalLayout_6->addWidget(groupBox);

        tabWidget->addTab(tab_4, QString());

        horizontalLayout_9->addWidget(tabWidget);

        horizontalLayout_9->setStretch(0, 2);
        horizontalLayout_9->setStretch(1, 1);

        verticalLayout_7->addLayout(horizontalLayout_9);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 35));
        widget->setMaximumSize(QSize(16777215, 35));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_25 = new QLabel(widget);
        label_25->setObjectName("label_25");

        horizontalLayout->addWidget(label_25);

        label_serialState = new QLabel(widget);
        label_serialState->setObjectName("label_serialState");

        horizontalLayout->addWidget(label_serialState);


        verticalLayout_7->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2021", nullptr));
        label_joint1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2022", nullptr));
        label_joint2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2023", nullptr));
        label_joint3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2024", nullptr));
        label_joint4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2025", nullptr));
        label_joint5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2026", nullptr));
        label_joint6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_reset->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\350\277\220\345\212\250\346\216\247\345\210\266", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\237\272\345\272\247", nullptr));
        btn_color1->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\350\202\251\351\203\250", nullptr));
        btn_color2->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\244\247\350\207\202", nullptr));
        btn_color3->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "\350\202\230\351\203\250", nullptr));
        btn_color4->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "\345\260\217\350\207\202", nullptr));
        btn_color5->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "\350\205\225\351\203\250", nullptr));
        btn_color6->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "\346\234\253\347\253\257\346\211\247\350\241\214\345\231\250", nullptr));
        btn_color7->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\212\240\350\275\275\351\205\215\350\211\262\346\226\271\346\241\210", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\250\241\345\236\213\350\256\276\347\275\256", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\350\247\202\345\257\237\350\247\206\350\247\222", nullptr));
        btn_left->setText(QString());
        btn_right->setText(QString());
        btn_down->setText(QString());
        btn_front->setText(QString());
        btn_back->setText(QString());
        btn_up->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "\346\270\262\346\237\223\350\256\276\347\275\256", nullptr));
        checkBox_gridMode->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\275\221\346\240\274", nullptr));
        checkBox_axisMode->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\235\220\346\240\207\350\275\264", nullptr));
        checkBox_polygonMode->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\272\277\346\241\206", nullptr));
        checkBox_trackMode->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\234\253\347\253\257\350\275\250\350\277\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\345\234\272\346\231\257\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\232\344\277\241", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\220\215\347\247\260", nullptr));
        btn_searchSerial->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\344\270\262\345\217\243", nullptr));
        btn_connectSerial->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\344\270\262\345\217\243", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\234\237\346\234\233\345\247\277\346\200\201", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "alpha", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "beta", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "gamma", nullptr));
        btn_cacl->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\256\241\347\256\227", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\234\200\344\274\230\350\247\243", nullptr));
        btn_send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\234\200\344\274\230\350\247\243", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\200\232\344\277\241", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\347\212\266\346\200\201\357\274\232", nullptr));
        label_serialState->setText(QCoreApplication::translate("MainWindow", "\346\234\252\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
