// Поток, увеличивающий значение переменной
// ------------------------------------
#ifndef DECTHREAD_H
#define DECTHREAD_H

#include <QThread>

class DecThread : public QThread {
 protected:
  void run();
 public:
  int count;
};

#endif // DECTHREAD_H
