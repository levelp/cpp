/// Главная форма в динамической памяти
/// -----------------------------------
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  /// Создание главной формы:
  ///-->
  MainWindow* w = new MainWindow;
  // Вызов главной формы через указатель
  w->show();

  // Сохраняем результат выполнения...
  int res = a.exec();

  // ...чтобы очистить память...
  delete w;
  // ...и только потом выйти!
  return res;
  ///<--
}
