#include "random.h"

#include <QtGlobal> // qrand()

/// Генерация случайного целого числа в диапазоне
/// low..high
///-->
int random(int low, int high) {
  return low + qrand() % (high - low + 1);
}
///<--

