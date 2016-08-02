#include "functions.h"
#include <QString>

// Сумма: a + b = c
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
