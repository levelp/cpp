QT       += core gui

QT       += webkit webkitwidgets

OPENSSL_LIBS='-L/opt/ssl/lib -lssl -lcrypto' ./configure -openssl-linked

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_WebKit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
