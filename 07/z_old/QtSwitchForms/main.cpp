#include "mainwindow.h"
#include "form2.h"
#include <QApplication>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  Form2 form2;
  //form2.show();

  w.form2 = &form2;
  form2.form1 = &w;

  return a.exec(); // Обработка событий
}
