# Комментарии

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtHelloWorld
TEMPLATE = app  # lib


SOURCES += main.cpp\
        mywindow.cpp

HEADERS  += mywindow.h

FORMS    += mywindow.ui
