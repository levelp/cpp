#include <QApplication>
#include <QtTest>
#include <QFile>
#include <iostream>
#include <cstdlib>
#include <cstdio>
// Подключаем модульные тесты
#include "alltests.h"
// Вывод числа в строку
#include "inttostr.h"

#include "simpletests.h"

#include "integraltest.h"

void writeNumbersToFile() {
  // Выведем все числа в файл (чтобы посмотреть на них вручную)
  QFile file("numbers.txt");

  if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qDebug() << file.errorString();
    return;
  }

  QTextStream out(&file);
  out.setCodec("UTF-8");

  for(int i = 999; i <= 2000; ++i)
    out << i << " -> " << intToStr(i) << endl;

  file.close(); // Закрываем файл

}

int main(int argc, char* argv[]) {
  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

  //freopen("testing.txt", "w", stdout);

  QTest::qExec(new SimpleTests());
  QTest::qExec(new AllTests, argc, argv);
  QTest::qExec(new IntegralTest, argc, argv);

  //writeNumbersToFile();

  return 0;
}
