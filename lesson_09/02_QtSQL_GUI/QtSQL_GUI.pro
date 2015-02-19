# Работа с Базой Данных используя SQLite
# и интерфейсную часть на Qt

QT       += core gui sql # Добавили поддержку SQL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_SQL_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
