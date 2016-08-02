#ifndef THREADEDPERFORMER_H
#define THREADEDPERFORMER_H

#include <QObject>

class ThreadedPerformer : public QObject {
  Q_OBJECT
 public:
  explicit ThreadedPerformer(QObject* parent = 0);

 signals:

 public slots:
  void someSlot(int someArg);

};

#endif // THREADEDPERFORMER_H
