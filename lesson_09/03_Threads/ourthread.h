#ifndef OURTHREAD_H
#define OURTHREAD_H

#include <QThread>

class OurThread : public QThread {
  Q_OBJECT
 public:
  explicit OurThread(QObject* parent = 0);

  //    void run();

 signals:

 public slots:
  void someSlot();

};

#endif // OURTHREAD_H
