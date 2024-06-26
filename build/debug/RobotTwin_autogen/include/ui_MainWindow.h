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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
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
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QSlider *horizontalSlider_3;
    QLabel *label_4;
    QSlider *horizontalSlider_4;
    QLabel *label_5;
    QSlider *horizontalSlider_5;
    QLabel *label_6;
    QSlider *horizontalSlider_6;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        openGLWidget = new CustomOpenGLWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");

        horizontalLayout->addWidget(openGLWidget);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(tab);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        horizontalSlider_2 = new QSlider(tab);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_2);

        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        horizontalSlider_3 = new QSlider(tab);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_3);

        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        horizontalSlider_4 = new QSlider(tab);
        horizontalSlider_4->setObjectName("horizontalSlider_4");
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_4);

        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        horizontalSlider_5 = new QSlider(tab);
        horizontalSlider_5->setObjectName("horizontalSlider_5");
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_5);

        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        horizontalSlider_6 = new QSlider(tab);
        horizontalSlider_6->setObjectName("horizontalSlider_6");
        horizontalSlider_6->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_6);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2021", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2022", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2023", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2024", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2025", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\205\263\350\212\2026", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
