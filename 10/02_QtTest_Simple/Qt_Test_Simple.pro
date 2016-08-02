QT       += core testlib # testlib - библиотека для модульного тестирования

QT       -= gui

TARGET = Qt_Test_Simple
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    sum.cpp \
    myclass.cpp

HEADERS += \
    tests.h \
    sum.h \
    myclass.h
