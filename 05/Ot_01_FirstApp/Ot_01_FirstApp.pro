# Файл проекта
# ============

# Подключается ядро Qt
# и библиотека для пользовательского интерфейса
QT       += core gui

# Начиная с Qt5 сразу же подключается QtWidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Имя исполняемого файла
TARGET = Qt_01_FirstApp
# Какой тип исполняемого приложения
# app - исполняемый файл (.exe для Windows)
#    исполяемый с флагами выполнения
#        (для Linux / MacOS...)
# lib - библиотека (.dll для Windows,
#       .so для Linux / MacOS)
TEMPLATE = app

# Файлы для компиляции
SOURCES += main.cpp\
        mainwindow.cpp

# Заголовочные файлы
HEADERS  += mainwindow.h

# XML-файлы с нарисованным интерфейсом
FORMS    += mainwindow.ui
