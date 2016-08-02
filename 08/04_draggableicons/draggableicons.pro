QT += widgets

HEADERS     = dragwidget.h \
    mainwindow.h
RESOURCES   = draggableicons.qrc
SOURCES     = dragwidget.cpp \
              main.cpp \
    mainwindow.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/draganddrop/draggableicons
INSTALLS += target

FORMS += \
    mainwindow.ui
