#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cofig_mode.h>
#include "stdio.h"
#include "string"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QDir>
#include "stdio.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cofig_mode itmq;
    ui->cbb_dev->clear();//lam trong truoc khi them items
    ui->cbb_dev->addItems(itmq.avalible_port());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
}

void MainWindow::on_commit_2g_clicked()
{
    cofig_mode sen;
    sen.port_name = ui->cbb_dev->currentText();
    sen.send_atComm("AT!SELRAT=02");
    QMessageBox kq;
    kq.setText(sen.res);
    kq.exec();
}

void MainWindow::on_add_i_clicked()
{
    cofig_mode itmq;
    ui->cbb_dev->clear();//lam trong truoc khi them items
    ui->cbb_dev->addItems(itmq.avalible_port());
}


void MainWindow::on_pushButton_clicked()
{
    cofig_mode sen3;
    sen3.port_name = ui->cbb_dev->currentText();
    sen3.send_atComm("AT!SELRAT=01");
}

void MainWindow::on_pushButton_2_clicked()
{
    cofig_mode moi;
    QString value;
    moi.port_name = ui->cbb_dev->currentText();
    value = moi.send_atComm("AT!GETRAT\?");
    value.trimmed();
        ui->label->setText(value.mid(11,4));
}
