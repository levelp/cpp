#-------------------------------------------------
#
# Project created by QtCreator 2014-09-25T21:54:36
#
#-------------------------------------------------

QT       -= gui

TARGET = QtDLLExample

# Динамически подключаемая библиотека
# DLL - Windows, so - Linux
TEMPLATE = lib

DEFINES += QTDLLEXAMPLE_LIBRARY

SOURCES += qtdllexample.cpp

HEADERS += qtdllexample.h\
        qtdllexample_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
