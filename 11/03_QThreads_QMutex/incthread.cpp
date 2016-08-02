#include "incthread.h"
#include "commondata.h"

void IncThread::run() {
  count = 0;
  for(int i = 0; i < 1000; ++i) {
#ifdef USE_MUTEX
    CommonData::mutex.lock();
#endif
    for(int j = 0; j < 1000; ++j) {
      CommonData::data++;
      count++;
    }
#ifdef USE_MUTEX
    CommonData::mutex.unlock();
#endif
    //msleep(10); // 20 миллисекунд
  }

}

