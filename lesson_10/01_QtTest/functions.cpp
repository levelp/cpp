#include "functions.h"
#include <QString>

// Сумма: a + b
int sum(int a, int b) {
  return a + b;
}

// Факториал
long long factorial(int n) {
  if(n <= 0)
    throw QString("N > 0");

  if(n > 2)
    return n * factorial(n - 1);

  return n;
}

// Численное интегрирование
// Метод трапеций
double integral(dooubleFunc f,
                double from, double to) {
  //
  const int N = 10000;
  double step = (to - from) / N;
  double sum = 0;
  double prevY = f(from);

  for(double x = from; x < to; x += step) {
    double y = f(x + step);
    sum += step * (prevY + y) / 2.0;
    prevY = y;
  }

  return sum;
}

