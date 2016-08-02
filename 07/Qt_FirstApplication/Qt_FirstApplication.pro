# Модули Qt
# core - обработка событий
# gui - базовые классы для интерфейса
QT       += core gui

# Для Qt5 и выше добавляем ещё и QtWidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Имя исполняемого файла
TARGET = Qt_FirstApplication

# Шаблон сборки
# app - исполняемый файл (.exe)
# lib - библиотека (.dll)
TEMPLATE = app

# Исходные тексты C++
SOURCES += main.cpp mainwindow.cpp

# Заголовочные файлы
HEADERS += mainwindow.h

# Файлы с формами
FORMS += mainwindow.ui
