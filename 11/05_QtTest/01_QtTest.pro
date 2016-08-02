# testlib - библиотека для модульного тестирования
QT       += testlib core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#QT       -= gui

TARGET = Qt_Test
CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myclass.cpp \
    inttostr.cpp \
    functions.cpp \
    alltests.cpp \
    squareeq.cpp \
    simpletests.cpp \
    integraltest.cpp

HEADERS += \
    squareeq.h \
    myclass.h \
    inttostr.h \
    functions.h \
    alltests.h \
    simpletests.h \
    integraltest.h

CODECFORTR = UTF-8
CODECFORSRC = UTF-8
