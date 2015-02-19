# Используем всё те же основные модули
QT       += core gui
# Добавляется ещё работа с сетью 
QT       += network   # Work with network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtNetwork
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
