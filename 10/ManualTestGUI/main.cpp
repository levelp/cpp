#include "mainwindow.h"
#include <QApplication>
#include <cstdio>

int main(int argc, char* argv[]) {
  freopen("ManualTestGUI.log", "w", stdout);

  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
