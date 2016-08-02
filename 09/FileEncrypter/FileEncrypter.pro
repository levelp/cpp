#-------------------------------------------------
#
# Project created by QtCreator 2016-02-03T20:27:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileEncrypter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    encryptthread.cpp

HEADERS  += mainwindow.h \
    encryptthread.h

FORMS    += mainwindow.ui
