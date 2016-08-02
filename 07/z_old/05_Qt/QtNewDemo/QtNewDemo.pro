#-------------------------------------------------
# Это файл проекта на Qt
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtNewDemo
TEMPLATE = app
  # console - консольное приложение

SOURCES += main.cpp\
        mainwindow.cpp \
    secondwindow.cpp \
    demowindow.cpp

HEADERS  += mainwindow.h \
    secondwindow.h \
    demowindow.h

FORMS    += mainwindow.ui \
    secondwindow.ui \
    demowindow.ui
