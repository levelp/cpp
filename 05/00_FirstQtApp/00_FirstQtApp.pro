# Файл проекта
# .pro

# Какие модули Qt используются
#  QtCore - общие для всех компонент Qt классы
#  QtGUI - графический пользовательский интерфейс
QT       += core gui

#  QtWidgets - сами "виджеты"
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Имя исполняемого файла
TARGET = FirstQtApp_MyExe
# .exe - Windows
# исполняемый файл без расширения Linux/Mac
TEMPLATE = app
#TEMPLATE = lib # .DLL .so

# Все .c / .cpp файлы которые нужно компилировать
SOURCES += main.cpp mainwindow.cpp \
    dialog.cpp

# Заголовочные файлы
HEADERS  += mainwindow.h \
    dialog.h

# Описание интерфейса
FORMS    += mainwindow.ui \
    dialog.ui

# Произвольные данные
DISTFILES += \
    README.md

CONFIG   += console

