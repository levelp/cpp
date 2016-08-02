#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Комлексное число
//  2.2 + 3.4i
// sqrt(-1) = i
struct Complex {
  double re; // Действительная часть
  double im; // Мнимая часть
} zero = {0, 0};

struct Complex c1;

//      Определение    Название
typedef struct Complex Comp;
//      "Comp" = "struct Complex"

// Вывод комплексного числа на экран
//void show(struct Complex c) {
void show(Comp c) {
  // f - double / float
  // f - float
  // lf - double
  // Lf - long double
  if(fabs(c.im) < 0.00000000001) // EPS
    printf("%f\n", c.re);
  else
    printf("%f + %f i\n", c.re, c.im);

  //long double x = 1.1232143;
  //printf("long double %Lf\n", x);
}

Comp addComplex(Comp a, Comp b) {
  Comp res;
  res.re = a.re + b.re;
  res.im = a.im + b.im;
  // Можно написать короче
  //Comp res = {a.re + b.re, a.im + b.im};
  return res;
}

int main() {
  Comp a = {1, 0}; // 1
  Comp b = {2, 1}; // 2 + 1i
  Comp c = addComplex(a, b); // c = a + b

  show(a);
  show(b);
  show(c);

  return 0;
}
