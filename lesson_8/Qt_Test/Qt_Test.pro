#-------------------------------------------------
#
# Project created by QtCreator 2014-01-21T19:03:41
#
#-------------------------------------------------

# testlib - библиотека для модульного тестирования
QT       += testlib core gui  # QApplication

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#QT       -= gui

TARGET = Qt_Test
CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    test_smart.cpp \
    smart.cpp

HEADERS += \
    test_smart.h \
    smart.h
