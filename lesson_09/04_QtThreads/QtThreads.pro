QT       += core

QT       -= gui

TARGET = QtThreads
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    mythread.cpp \
    observer.cpp \
    inputthread.cpp

HEADERS += \
    mythread.h \
    observer.h \
    inputthread.h
