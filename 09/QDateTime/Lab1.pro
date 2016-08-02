# Работа с датами + создание всего интерфейса
# прямо из кода
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab1
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    datetime.cpp \
    wnd.cpp
HEADERS += datetime.h \
    wnd.h
