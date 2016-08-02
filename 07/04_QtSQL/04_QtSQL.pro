QT       += core

# Добавили строку для модуля SQL
QT       += sql  # add module Qt SQL

QT       -= gui

TARGET = qt_console
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

TARGET = Qt_SQL

SOURCES += main.cpp

HEADERS  +=

FORMS    +=

# Подключение MySQL
#INCLUDEPATH+=C:/MySQL/include
#LIBS+=C:/MYSQL/MySQL Server <version>/lib/opt/libmysql.lib
# + использовать драйвер QMYSQL
