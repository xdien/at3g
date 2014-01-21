#include "mainwindow.h"
#include <QApplication>
//#include <chat.c>
int main(int argc, char *argv[])
{
    //init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
