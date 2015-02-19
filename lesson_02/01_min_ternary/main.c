// Универсальная функция min на C
#include <stdio.h>
#include <stdlib.h>

// Макрос с использованием тернарного оператора
#define MIN(a,b) (a < b) ? a : b

int min(int a, int b) {
  return (a < b) ? a : b;
}

// Нужен префикс f:  math.h -> abs/fabs
double fmin(double a, double b) {
  return (a < b) ? a : b;
}

int main() {
  int a = 12, b = 4259;
  printf("MIN(%d,%d) = %d\n", a, b, MIN(a, b));
  double d1 = 0.12, d2 = 23.2;
  printf("MIN(%lf,%lf) = %lf\n", d1, d2, MIN(d1, d2));
  return 0;
}
