#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>



class SerialPort : public QObject
{
    Q_OBJECT

public:
    explicit SerialPort(QObject *parent = nullptr);
    ~SerialPort();

    bool openPort(const QString &portName);
    void closePort();
    void sendData(const QByteArray &data);
    bool isOpen();

signals:
    void dataReceived(const QString &data);
    void errorOccurred(const QString &errorString);

private slots:
    void readData();

private:
    QSerialPort *serial;
};

#endif // SERIALPORT_H
