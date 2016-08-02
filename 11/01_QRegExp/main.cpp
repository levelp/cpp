// Работа с регулярными выражениями
#include <QApplication>
#include <QDebug>
#include <QtTest/QTest>
#include "mainwindow.h"
#include "qregexptest.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  // Запуск модульных тестов
  QTest::qExec(new QRegExpTest, argc, argv);

  MainWindow w;
  w.show();

  return a.exec();
}
