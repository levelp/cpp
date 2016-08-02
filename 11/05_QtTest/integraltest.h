#ifndef INTEGRALTEST_H
#define INTEGRALTEST_H

#include <QObject>

class IntegralTest : public QObject {
  Q_OBJECT

 private slots:
  // Тестирование интегрирования константной функции
  void testConstant();

  void testLinear();

  void testQuadratic();
};

#endif // INTEGRALTEST_H
