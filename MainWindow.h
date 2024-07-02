#pragma once

#include <QMainWindow>
#include "Arm_IK.h"
#include "serialport.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void startCacl();

private:
    Ui::MainWindow *ui;
    ARM arm;
    SerialPort *serialPort;
};
