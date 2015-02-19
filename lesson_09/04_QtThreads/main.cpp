#include <QCoreApplication>
#include <mythread.h>
#include <iostream>
#include <QObject>
#include "observer.h"
#include "inputthread.h"

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  MyThread t1(&a, "T1", 5);
  MyThread t2(&a, "T2", 10);
  MyThread t3;
  t1.start();
  t2.start();
  t3.start();

  // Отслеживаем события в потоке 1
  Observer obs;

  a.connect(&t1, SIGNAL(finished()),
            &obs, SLOT(T1_finished()));

  // Создаём поток для ввода данных
  InputThread it(NULL); //&a);

  // Мы можем присоединить сколько угодно
  // обработчиков к одному сигналу,
  // в частности к событию finished()
  a.connect(&it, SIGNAL(finished()),
            &t1, SLOT(terminate()));
  a.connect(&it, SIGNAL(finished()),
            &t2, SLOT(terminate()));
  a.connect(&it, SIGNAL(finished()),
            &a,  SLOT(quit()));

  // Можем вывести, запущен ли поток
  t1.isRunning();

  t1.wait();

  it.start();

  return a.exec();
}
