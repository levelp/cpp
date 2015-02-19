#include "decthread.h"
#include "commondata.h"

void DecThread::run() {

  for(int i = 0; i < 100000; ++i) {
    D(CommonData::mutex.lock());
    CommonData::data--;
    D(CommonData::mutex.unlock());
    //msleep(20); // 20 миллисекунд
  }

}
