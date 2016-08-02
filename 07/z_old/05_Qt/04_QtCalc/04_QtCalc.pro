QT += core
QT += gui
QT += widgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Имя исполняемого файла
TARGET = MyExe

# app - оконное приложение
TEMPLATE = app

FORMS    += mainwindow.ui

HEADERS  += mainwindow.h \
    CalcStates.h

SOURCES += main.cpp\
   mainwindow.cpp


