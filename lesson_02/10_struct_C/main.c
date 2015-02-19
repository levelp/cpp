#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Complex {
  double re; // Действительная часть
  double im; // Мнимая часть
} zero = {0, 0};

typedef struct Complex Comp;

// Вывод комплексного числа на экран
void show(Comp c) {
  if(fabs(c.im) < 0.00000000001)
    printf("%lf\n", c.re);
  else
    printf("%lf+%lf i\n", c.re, c.im);
}

Comp addComplex(Comp a, Comp b) {
  //Comp res = {a.re + b.re, a.im + b.im};
  Comp res;
  res.re = a.re + b.re;
  res.im = a.im + b.im;
  return res;
}

int main() {
  Comp a = {1, 0};
  Comp b = {2, 1};
  Comp c = addComplex(a, b);

  show(a);
  show(b);
  show(c);

  return 0;
}
