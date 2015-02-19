#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T20:48:19
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBrowser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    urlcomplete.cpp \
    mockurlworker.cpp

HEADERS  += mainwindow.h \
    urlcomplete.h \
    urlworker.h \
    mockurlworker.h

FORMS    += mainwindow.ui \
    mainwindow2.ui
