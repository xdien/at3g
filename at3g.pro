#-------------------------------------------------
#
# Project created by QtCreator 2014-01-12T16:11:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = at3g
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cofig_mode.cpp

HEADERS  += mainwindow.h \
    cofig_mode.h

FORMS    += mainwindow.ui

OTHER_FILES +=
CONFIG += serialport
LIBS += -ludev
DEFINES += HAVE_LIBUDEV
