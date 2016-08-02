#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  // Создаём Qt-приложение
  QApplication a(argc, argv);
  // Создаём основное окно
  MainWindow w;
  // Показываем его
  w.show();

  // Обработка событий приложения
  return a.exec();
}
