#-------------------------------------------------
#
# Project created by QtCreator 2014-10-07T20:13:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_QtThreadGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    primecalcthread.cpp

HEADERS  += mainwindow.h \
    primecalcthread.h

FORMS    += mainwindow.ui
