#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  //w.show();
  // Показываем главное окно в полноэкранном режиме
  w.showFullScreen();

  return a.exec();
}
