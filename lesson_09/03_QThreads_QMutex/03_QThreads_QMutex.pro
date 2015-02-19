#-------------------------------------------------
#
# Project created by QtCreator 2015-02-17T22:30:07
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 03_QThreads_QMutex
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    incthread.cpp \
    commondata.cpp \
    decthread.cpp

HEADERS += \
    incthread.h \
    commondata.h \
    decthread.h
