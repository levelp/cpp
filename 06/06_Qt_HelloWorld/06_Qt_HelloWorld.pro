# Файл проекта Qt
# .pro

# QT - какие модули использовать
QT       += core gui
# Qt5Gui.dll
# Qt<версия><Название_модуля>.dll

# В версии QT выше 4 нужна библиотека widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# TARGET - название исполняемого файла
TARGET = 06_Qt_HelloWorld
# app - исполняемый файл
# lib - разделяемую динамически подгружаемую библиотеку
TEMPLATE = app

# Файлы для компиляции
SOURCES += main.cpp\
        mainwindow.cpp

# Заголовочные файлы
HEADERS  += mainwindow.h

# Формы (интерфейс)
FORMS    += mainwindow.ui
