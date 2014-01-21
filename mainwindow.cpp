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
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    cofig_mode itm;
    ui->cbb_dev->clear();//lam trong truoc khi them items
    ui->cbb_dev->addItems(itm.avalible_port());
}


void MainWindow::on_pushButton_clicked()
{
    cofig_mode sen3;
    sen3.port_name = ui->cbb_dev->currentText();
    sen3.send_atComm("AT!SELRAT=01");
}

void MainWindow::on_pushButton_2_clicked()
{

}
