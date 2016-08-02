// Поток, увеличивающий значение переменной
// ------------------------------------
#ifndef INCTHREAD_H
#define INCTHREAD_H

#include <QThread>

class IncThread : public QThread {
  Q_OBJECT
 protected:
  void run();
 public:
  int count;
};

#endif // INCTHREAD_H
