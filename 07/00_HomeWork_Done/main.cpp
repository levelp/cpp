#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  Form1 w;
  w.show();

  return a.exec();
}
