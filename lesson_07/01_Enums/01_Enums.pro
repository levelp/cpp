# Консольные приложения
QT       += core

QT       -= gui

TARGET = 01_Enums
# Добавляем к приложению консоль
CONFIG   += console
# Убираем компоненты которые нужны для вывода
# окон
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
