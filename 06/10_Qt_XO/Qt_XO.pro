#-------------------------------------------------
#
# Project created by QtCreator 2014-01-18T11:27:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_XO
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    cellbutton.cpp \
    gamesettings.cpp

HEADERS  += mainwindow.h \
    game.h \
    cellbutton.h \
    gamesettings.h \
    map_size.h

FORMS    += mainwindow.ui \
    gamesettings.ui
