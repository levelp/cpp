/// Основная программа
/// ------------------
#include <QCoreApplication>
#include <mythread.h>
#include <iostream>
#include <QObject>
#include "observer.h"
#include "inputthread.h"

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  // Создаём 3 потока
  MyThread t1(&a, "T1", 15);
  MyThread t2(&a, "T2", 30);
  MyThread t3;
  // Запускаем их (начинает выполнятся метод run)
  t1.start();
  t2.start();
  t3.start();

  // Отслеживаем события в потоке 1
  Observer obs;

  // Когда поток t1 завершится
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

  // Запускаем поток InputThread
  it.start();

  // Можем вывести, запущен ли поток
  t1.isRunning();

  t1.wait();
  t2.wait();
  t3.wait();
  it.wait();

  // Обработка всех сигналов
  return a.exec();
}
