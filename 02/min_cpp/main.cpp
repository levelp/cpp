// В C++ перегрузка функций разрешена
#include <stdio.h>
#include <stdlib.h>

// С точки зрения С++ можно переопределять функции, в обычном С этого делать нельзя
int min(int a, int b) {
  return (a < b) ? a : b;
}

double min(double a, double b) {
  return (a < b) ? a : b;
}

int main() {
  int a = 12, b = 4259;
  printf("MIN(%d,%d) = %d\n", a, b, min(a, b));
  double d1 = 0.12, d2 = 23.2;
  printf("MIN(%lf,%lf) = %lf\n", d1, d2, min(d1, d2));
  return 0;
}
