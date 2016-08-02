#ifndef COMMONDATA_H
#define COMMONDATA_H

#include <QMutex>

//#define D(X) X;
//#define D(X) ;

#define USE_MUTEX

class CommonData {
 public:
  // Общие данные, которыми пользуются
  // оба потока
  static int data;
#ifdef USE_MUTEX
  static QMutex mutex;
#endif
};

#endif // COMMONDATA_H
