#ifndef TIMERPERFORMER_H
#define TIMERPERFORMER_H

#include <QObject>
#include <QString>

class ThreadedPerformer;

class TimerPerformer : public QObject {
  Q_OBJECT
 public:
  explicit TimerPerformer(QObject* parent = 0);
  void printString(int id, const QString& name, float count, const QString& title);

 signals:
  void firstSignal();
  void secondSignal();

 private slots:
  void timerTimeout();
  void firstSlot();
  void secondSlot();

 protected:
  void timerEvent(QTimerEvent* ev);

 private:
  int m_timerId;
  ThreadedPerformer* m_threadedPerformer;

};

#endif // TIMERPERFORMER_H
