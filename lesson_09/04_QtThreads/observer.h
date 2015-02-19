#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>

class Observer : public QObject {
  Q_OBJECT
 public:
  explicit Observer(QObject* parent = 0);

 signals:

 public slots:
  void T1_finished();

};

#endif // OBSERVER_H
