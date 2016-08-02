#include "commondata.h"

int CommonData::data = 0;
#ifdef USE_MUTEX
QMutex CommonData::mutex;
#endif
