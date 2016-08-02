#ifndef PRIMECALCTHREAD_H
#define PRIMECALCTHREAD_H

#include <QThread>
#include <QListWidget>

class PrimeCalcThread : public QThread {
  Q_OBJECT

  QListWidget* resultsList;
  int fromValue;
  int toValue;

 public:
  explicit PrimeCalcThread(
    QObject* parent,
    QListWidget* resultsList,
    int fromValue,
    int toValue
  );

 protected:
  void run();

 signals:

 public slots:

};

#endif // PRIMECALCTHREAD_H
