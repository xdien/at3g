#ifndef COFIG_MODE_H
#define COFIG_MODE_H
#include <QStringList>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class cofig_mode
{
public:
    QString port_name;
    QSerialPort serial;
    QString res;
    cofig_mode();
    void umts_ref();
    QString send_atComm(QString at);
    QStringList avalible_port(); //return list port available in /dev
    bool check_correctPort();
};

#endif // COFIG_MODE_H
