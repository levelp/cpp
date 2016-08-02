# testlib необходим для запуска модульных тестов
QT       += core testlib

QT       -= gui

TARGET = 01_QtTest_Task
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    divisors.cpp \
    tests.cpp

HEADERS += \
    divisors.h \
    tests.h

OTHER_FILES += \
    README.md
