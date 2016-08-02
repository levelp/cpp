QT       += core

# Добавили строку для модуля SQL
QT       += sql gui # add module Qt SQL
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_console
# Для включения консольного окна
#CONFIG   += console
#CONFIG   -= app_bundle

TEMPLATE = app

TARGET = Qt_SQL

SOURCES += main.cpp\
           mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# Подключение MySQL
#INCLUDEPATH+=C:/MySQL/include
#LIBS+=C:/MYSQL/MySQL Server <version>/lib/opt/libmysql.lib
# + использовать драйвер QMYSQL
