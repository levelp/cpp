#include "observer.h"
#include <iostream>

using namespace std;

Observer::Observer(QObject* parent) :
  QObject(parent) {
}

void Observer::T1_finished() {
  // Получили сигнал что поток 1 завершился
  cout << "Observer::T1_finished()" << endl;
}
