#include "mythread.h"
#include <iostream>

using namespace std;

MyThread::MyThread(QObject* parent,
                   QString name,
                   int iterations) :
  QThread(parent), name(name),
  iterations(iterations) {
}

void MyThread::run() {
  // Перед этим генерируется сигнал started()
  for(int i = 1; i <= iterations; i++) {
    cout << "{ "
         << name.toStdString() << " "
         << i
         << " }" << endl;
    // Замедляем поток
    sleep(1); // 1 секунда
  }

  // Генерируется сигнал finished()
}
