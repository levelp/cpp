QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Добавляем работу с SQL
QT       += sql

TARGET = QtSQL_Students
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
