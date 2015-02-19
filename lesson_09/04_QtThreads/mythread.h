#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread {
  Q_OBJECT

  // Имя потока
  QString name;

  // Количество итераций
  int iterations;

 public:
  explicit MyThread(QObject* parent = 0,
                    QString name = "MyThread",
                    int iterations = 10);

 public slots:

  void run();
};

#endif // MYTHREAD_H
