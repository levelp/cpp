#ifndef TESTS_H
#define TESTS_H

#include <QObject>

class Tests : public QObject {
  Q_OBJECT
 public:
  explicit Tests(QObject* parent = 0);

 private slots:
  void testDivisors();
};

#endif // TESTS_H
