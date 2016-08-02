#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  int code = a.exec();

  std::cout << "Program Finished!" << std::endl;

  return 0;
}
