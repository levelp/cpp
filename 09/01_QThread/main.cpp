#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  int* ptr = static_cast<int*>(0x234324);
  // ptr - в стеке
  ptr++; // меняем указатель в стеке
  *ptr++; // меняем значение где-то

  ptr++; // смещаемся на размер того, на что указывает этот ptr
  // т.е. если он int*
  // то на 4 байта (для 32 битной системы)

  return a.exec();
}
