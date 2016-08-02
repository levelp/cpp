#include <cmath> // sqrt
#include "squareeq.h"

const double EPS = 1e-10;

Roots SquareEq::quadraticEquation(double a, double b, double c) {
  Roots r;

  if(a == 0) {
    if(b == 0) {
      if(c == 0) {
        // Генерируем исключение
        throw QString("Бесконечное число решений");
      }

      // Нет решений
      r.numberOfRoots = 0;
      return r;
    }

    // Линейное уравнение
    r.numberOfRoots = 1;
    r.x[0] = -c / b;
    return r;
  }

  // Квадратное уравнение
  double D = b * b - 4 * a * c;

  if(D > EPS) {
    r.numberOfRoots = 2;
    r.x[0] = (-b + sqrt(D)) / (2 * a);
    r.x[1] = (-b - sqrt(D)) / (2 * a);
  } else if(D < -EPS)
    r.numberOfRoots = 0;
  else {
    r.numberOfRoots = 1;
    r.x[0] = -b / (2 * a);
  }

  return r;
}

double SquareEq::calc(double a, double b, double c, double x) {
  return a * pow(x, 2) + b * x + c;
}
