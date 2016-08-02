#include "decthread.h"
#include "commondata.h"

void DecThread::run() {
  count = 0;
  for(int i = 0; i < 1000; ++i) {
#ifdef USE_MUTEX
    // Захожу "в кабинку" и закрываю дверь
    CommonData::mutex.lock();
#endif
    for(int j = 0; j < 1000; ++j) {
      CommonData::data--;
      count++;
    }
#ifdef USE_MUTEX
    // Выхожу из кабинки и открываю дверь
    CommonData::mutex.unlock();
#endif
    //msleep(20); // 20 миллисекунд
  }

}
