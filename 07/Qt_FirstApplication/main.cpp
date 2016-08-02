#include "mainwindow.h"
#include <QApplication>

// Точка входа в программу
// argc - количество аргументов командной строки
// argv - массив строк / аргументов командной строки
int main(int argc, char* argv[]) {
  // Обработка событий:
  // механизм сигнал/слот
  QApplication a(argc, argv);

  // Создаём форму
  MainWindow w;
  w.show();

  // Запуск основного цикла обработки
  // событий
  return a.exec();
}
