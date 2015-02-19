/* Демонстрация форматирования вывода в "чистом" С */
#include <stdio.h>
#include <stdlib.h>

int main() {
  long l = 2123456789;
  /* Вывод целого числа */
  int i = 12;
  printf("%d %d\n", i, sizeof(i));
  i = 254;
  printf("%x\n", i); /* Шестнадцатеричный вывод */
  printf("%X\n", i); /* Шестнадцатеричный вывод большими (прописными) буквами */
  printf("%04X\n", i); /* ..с лидирующими нулями.. */
  printf("%4X\n", i);
  /* Вывод длинного целого */
  printf("%ld %d\n", l, sizeof(l));
  // Вывод ещё более длинного целого :)
  long long ll = 912345678900L;
  printf("%lld %d\n", ll, sizeof(ll));

  // signed / unsigned
  // знаковый / беззнаковый
  unsigned int ui = 3000000000;
  printf("%u\n", ui);

  // 'long long long' is too long for GCC
  // long long long lll = 912345678900L;
  // printf("%llld %d\n", lll, sizeof(lll));

  float f = 1.2f;
  printf("%f %d\n", f, sizeof(f));
  // 2 знака после запятой (точки)
  printf("%.2f %d\n", f, sizeof(f));

  double d = 1.2;
  printf("%.3lf %d\n", d, sizeof(d));

  char c = 'B';
  printf("%c\n", c);

  char s[] = "HELLO";
  printf("%s\n", s);

  return 0;
}
