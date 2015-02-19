#include "inputthread.h"
#include <iostream>

using namespace std;

InputThread::InputThread(QObject* parent) :
  QThread(parent) {
}

void InputThread::run() {
  // Вводим целое число
  int i;
  cin >> i;
  //  sleep(5);
  // Выводим восклицательные знаки
  // cout << "!!!!";
  //QCoreApplication::exit();
  cout << "InputThread::finished!" << endl;
}
