# Регулярные выражения

QT       += core gui

# Автоматические тесты
QT       += testlib


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRegExp
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           qregexptest.cpp

HEADERS  += mainwindow.h \
            qregexptest.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md
