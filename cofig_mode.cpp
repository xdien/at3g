#include "cofig_mode.h"
#include <string.h>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
using namespace std;
cofig_mode::cofig_mode()
{
}
void cofig_mode::umts_ref()
{
}
QStringList cofig_mode::avalible_port()
{
    QDir dir("/dev");
    QStringList filters;
    QStringList portsName;
    //filters << "ttyS*" << "ttyUSB*";
    filters << "ttyUSB*";
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Files | QDir::System);
    QFileInfoList list = dir.entryInfoList();
    for (int i=0; i< list.size(); i++)
    {
        portsName.append(list.at(i).canonicalFilePath ());
        //portsName.prepend(list.at(i).canonicalFilePath());
    }
    return portsName;
}
QString cofig_mode::send_atComm(QString at)
{
    at.append(13);//error with > 13 byte
    serial.setPortName(port_name);
    if(serial.open(QSerialPort::ReadWrite))
    {
        serial.setBaudRate(QSerialPort::Baud9600);
        serial.setParity(QSerialPort::NoParity);
        serial.setFlowControl(QSerialPort::NoFlowControl);
        serial.setDataBits(QSerialPort::Data8);
        serial.setStopBits(QSerialPort::OneStop);
        if(serial.isWritable())
        {
            qDebug() << serial.write(at.toLocal8Bit());
        }
        if(serial.isReadable())
        {
            if(serial.waitForReadyRead(500))
            {
                 res = QString(serial.readAll());
            }
        }
        serial.close();
        return res;
    }
    else
    {
        QMessageBox loi;
        loi.setText(serial.errorString());
        loi.exec();
        return serial.errorString();
    }
}
bool cofig_mode::check_correctPort()
{
    serial.isRequestToSend()
}
