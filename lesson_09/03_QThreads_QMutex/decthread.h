#ifndef DECTHREAD_H
#define DECTHREAD_H

#include <QThread>

class DecThread : public QThread {
 protected:
  void run();
};

#endif // DECTHREAD_H
