#include "demowidgetswindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  DemoWidgetsWindow w;
  w.show();

  return a.exec();
}
