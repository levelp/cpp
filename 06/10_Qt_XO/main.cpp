#include "mainwindow.h"
#include <QApplication>

int MapSize = 3;

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  MainWindow w;
  w.show();

  // Мы можем создать второе такое же окно
  //MainWindow w2;
  //w2.show();

  // Обработка событий - основной цикл работы программы
  return a.exec();
}
