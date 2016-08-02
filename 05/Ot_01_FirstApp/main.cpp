#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  // Создаём объект для обработки
  // сообщений
  // Чтобы сигналы передавались в слоты и т.д.
  QApplication a(argc, argv);

  // Создаём основное окно
  MainWindow w;
  // Показываем его
  w.show();

  // Запускаем цикл обработки сообщений
  return a.exec();
}
