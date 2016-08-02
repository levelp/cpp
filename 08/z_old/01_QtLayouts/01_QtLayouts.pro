# Виджеты и Layout's

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_QtLayouts
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    loginform.cpp

HEADERS  += \
    mainwindow.h \
    loginform.h

FORMS    += \
    mainwindow.ui \
    loginform.ui
