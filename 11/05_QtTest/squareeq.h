#ifndef SQUAREEQ_H
#define SQUAREEQ_H

#include <QObject>

// Корни квадратного уравнения
struct Roots {
  int numberOfRoots;
  double x[2];
};

// Решение квадратного уравнения
class SquareEq : public QObject {
  Q_OBJECT

 public:
  Roots quadraticEquation(double a, double b, double c);

  double calc(double a, double b, double c, double x);
};

#endif // SQUAREEQ_H
