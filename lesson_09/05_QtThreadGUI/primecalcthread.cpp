#include "primecalcthread.h"
#include <cmath> // для sqrt
#include <QDebug>

PrimeCalcThread::PrimeCalcThread(
  QObject* parent,
  QListWidget* resultsList,
  int fromValue,
  int toValue
) :
  QThread(parent), resultsList(resultsList),
  fromValue(fromValue), toValue(toValue) {
}

void PrimeCalcThread::run() {
  // Будем каждое число проверять на простоту
  for(int n = fromValue;
      n < toValue; ++n) {
    // Проверяем n на простоту
    bool isPrime = true;
    int upperBound = sqrt(n);

    for(int i = 2; i <= upperBound; ++i)
      if(n % i == 0) {
        isPrime = false;
        break;
      }

    // Если простое, то выводим в интерфейс
    if(isPrime) {
      QString s = QString("%1").arg(n);
      QListWidgetItem* item =
        new QListWidgetItem();
      item->setText(s);
      resultsList->addItem(item);
      //msleep(50);

    }
  }
}
