#include <QCoreApplication>
#include "incthread.h"
#include "decthread.h"
#include "commondata.h"
#include <QDebug>
#include <QThread>

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  for(int i = 0; i < 1000; ++i) {
    CommonData::data = 0;
    IncThread it;
    DecThread dt;
    // Запускаем оба потока
    it.start();
    dt.start();

    // Ожидаем завершения
    it.wait();
    dt.wait();

    qDebug() << "data:" << CommonData::data;

    //QThread::currentThread()->sleep(1);
  }

  return 0; // a.exec();
}
// i = 0
// i++;
// 1 - загрузка i - получили 0
// 1-->2
// 2 - загрузка i
// 2 - уменьшаем i = -1
// 2 - записываем i - записываем
// i = -1
// 1<--2
// 1 - У нас 0, увеливаем его, получаем 1
// 1 - записываем 1
// i = 1
