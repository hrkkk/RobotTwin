#include "serialport.h"
#include <QMessageBox>

SerialPort::SerialPort(QObject *parent):QObject(parent), serial(new QSerialPort(this))
{
    connect(serial, &QSerialPort::readyRead, this, &SerialPort::readData);
    connect(serial, &QSerialPort::errorOccurred, [this](QSerialPort::SerialPortError error) {
        if (error != QSerialPort::NoError) {
            emit errorOccurred(serial->errorString());
        }
    });
}


SerialPort::~SerialPort()
{
    closePort();
}


bool SerialPort::openPort(const QString &portName)
{
    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {
        return true;
    } else {
        emit errorOccurred(serial->errorString());
        return false;
    }
}


void SerialPort::closePort()
{
    if (serial->isOpen()) {
        serial->close();
    }
}


void SerialPort::sendData(const QByteArray &data)
{
    if (serial->isOpen()) {
        serial->write(data);
    } else {
        emit errorOccurred("Serial port is not open");
    }
}


void SerialPort::readData()
{
    const QByteArray data = serial->readAll();
    emit dataReceived(QString::fromLocal8Bit(data));
}

bool SerialPort::isOpen()
{
    return serial->isOpen();
}

