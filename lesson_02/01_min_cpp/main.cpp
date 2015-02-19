// В C++ перегрузка функций разрешена
#include <stdio.h>
#include <stdlib.h>

// С точки зрения С++ можно переопределять функции
// (т.е. создавать несколько функций с одинаковым именем,
//   отличающиеся только типами аргументов).
// В обычном С этого делать нельзя
// Поэтому в C есть функции:
//   abs - модуль для целых чисел и
//   fabs - модуль для действительных чисел
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
