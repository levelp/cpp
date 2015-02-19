#ifndef MINTIMER_H
#define MINTIMER_H
#include <QThread>
#include <QTimer>

class MyThread : public QThread {
  Q_OBJECT
 private:
  int myTime;
 public:
  MyThread(): myTime(10) {}

  void run() {
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), SLOT(slotNextValue()));
    timer.start();
    exec();
  }

 signals:
  void finished() ;
  void currentValue(int);
 public slots:
  void slotNextValue() {
    emit currentValue(++myTime);

    if (myTime > 1000)
      emit finished();
  }
};

#endif // MINTIMER_H
