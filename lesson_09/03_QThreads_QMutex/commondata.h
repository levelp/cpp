#ifndef COMMONDATA_H
#define COMMONDATA_H

#include <QMutex>

//#define D(X) X;
#define D(X) ;

class CommonData {
 public:
  static int data;
  static QMutex mutex;
};

#endif // COMMONDATA_H
