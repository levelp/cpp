#include "incthread.h"
#include "commondata.h"

void IncThread::run() {

  for(int i = 0; i < 100000; ++i) {
    D(CommonData::mutex.lock());
    CommonData::data++;
    D(CommonData::mutex.unlock());
    //msleep(10); // 20 миллисекунд
  }

}

