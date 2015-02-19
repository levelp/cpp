QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Minner
TEMPLATE = app
SOURCES += main.cpp \
    minner.cpp \
    mainwid.cpp \
    dialogs.cpp
HEADERS += minner.h \
    MinTimer.h \
    mainwid.h \
    Common.h \
    Buttons.h \
    dialogs.h
FORMS += minner.ui

RESOURCES += \
    img.qrc

TRANSLATIONS += minner_ru.ts
