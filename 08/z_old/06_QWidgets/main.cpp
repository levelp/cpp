#include "mainwindow.h"
#include "inputwidgets.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  InputWidgets w;
  //MainWindow w;
  w.show();

  return a.exec();
}
