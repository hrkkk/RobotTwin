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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CustomOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    CustomOpenGLWidget *openGLWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_angle1;
    QSlider *slider1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_angle2;
    QSlider *slider2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *label_angle3;
    QSlider *slider3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *label_angle4;
    QSlider *slider4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *label_angle5;
    QSlider *slider5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *label_angle6;
    QSlider *slider6;
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
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_gridMode;
    QCheckBox *checkBox_axisMode;
    QCheckBox *checkBox_polygonMode;
    QCheckBox *checkBox_trackMode;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1134, 778);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        openGLWidget = new CustomOpenGLWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");

        horizontalLayout->addWidget(openGLWidget);

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

        label_angle1 = new QLabel(tab);
        label_angle1->setObjectName("label_angle1");

        horizontalLayout_2->addWidget(label_angle1, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_2);

        slider1 = new QSlider(tab);
        slider1->setObjectName("slider1");
        slider1->setMinimum(-180);
        slider1->setMaximum(180);
        slider1->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        label_angle2 = new QLabel(tab);
        label_angle2->setObjectName("label_angle2");

        horizontalLayout_3->addWidget(label_angle2, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_3);

        slider2 = new QSlider(tab);
        slider2->setObjectName("slider2");
        slider2->setMinimum(-180);
        slider2->setMaximum(180);
        slider2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        label_angle3 = new QLabel(tab);
        label_angle3->setObjectName("label_angle3");

        horizontalLayout_4->addWidget(label_angle3, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_4);

        slider3 = new QSlider(tab);
        slider3->setObjectName("slider3");
        slider3->setMinimum(-180);
        slider3->setMaximum(180);
        slider3->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        label_angle4 = new QLabel(tab);
        label_angle4->setObjectName("label_angle4");

        horizontalLayout_5->addWidget(label_angle4, 0, Qt::AlignRight);


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

        label_angle5 = new QLabel(tab);
        label_angle5->setObjectName("label_angle5");

        horizontalLayout_6->addWidget(label_angle5, 0, Qt::AlignRight);


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

        label_angle6 = new QLabel(tab);
        label_angle6->setObjectName("label_angle6");

        horizontalLayout_7->addWidget(label_angle6, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_7);

        slider6 = new QSlider(tab);
        slider6->setObjectName("slider6");
        slider6->setMinimum(-180);
        slider6->setMaximum(180);
        slider6->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider6);

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
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(30, 30));
        pushButton_2->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/leftView.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(30, 30));
        pushButton_3->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/rightView.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(30, 30));
        pushButton_6->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/bottomView.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(30, 30));
        pushButton_5->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/frontView.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon3);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(30, 30));
        pushButton_4->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/backView.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);

        gridLayout->addWidget(pushButton_4, 1, 3, 1, 1);

        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(30, 30));
        pushButton_7->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/topView.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon5);

        gridLayout->addWidget(pushButton_7, 0, 1, 1, 1);


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

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1134, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2021", nullptr));
        label_angle1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2022", nullptr));
        label_angle2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2023", nullptr));
        label_angle3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2024", nullptr));
        label_angle4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2025", nullptr));
        label_angle5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2026", nullptr));
        label_angle6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
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
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_6->setText(QString());
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        pushButton_7->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "\346\270\262\346\237\223\350\256\276\347\275\256", nullptr));
        checkBox_gridMode->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\275\221\346\240\274", nullptr));
        checkBox_axisMode->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\235\220\346\240\207\350\275\264", nullptr));
        checkBox_polygonMode->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\347\272\277\346\241\206", nullptr));
        checkBox_trackMode->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\234\253\347\253\257\350\275\250\350\277\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\345\234\272\346\231\257\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
