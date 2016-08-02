/* Демонстрация форматирования вывода в "чистом" С */
#include <stdio.h>
#include <stdlib.h>

int main() {
  long l = 2123456789;
  /* Вывод целого числа */
  int i = 12;
  /* %d - целое число типа int */
  printf("%d  sizeof(int) = %d\n", i, sizeof(i));
  /*
    Спецсимволы:
    \n - перевод строки
    \r - возврат каретки
    \t - TAB (табуляция)
  */
  i = 254;
  /* 0123456789abcdef */
  /* 0123456789ABCDEF */
  printf("%x\n", i); /* Шестнадцатеричный вывод 255->"ff" */
  printf("%X\n", i); /* Шестнадцатеричный вывод большими (прописными) буквами */
  printf("%04X\n", i);
  /* ..с лидирующими нулями "00FF".. */
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
  //long long long lll = 912345678900L;
  // printf("%llld %d\n", lll, sizeof(lll));

  float f = 1.2f;
  printf("%f %d\n", f, sizeof(f));
  // 2 знака после запятой (точки)  3.14159...   3.14
  printf("%.2f %d\n", f, sizeof(f));

  double d = 1.2;
  printf("%.3lf %d\n", d, sizeof(d));

  printf("%10.3lf %d\n", d, sizeof(d));

  char c = 'B';
  printf("%c\n", c);

  char s[] = "HELLO";
  printf("%s\n", s);

  // %n - перевод строки специфичный для платформы
  // 13,10  CR/LF \r\n - Windows
  // 13 - \r - MacOS
  // 10 - \n - Linux

  // scanf()
  // %n

  return 0;
}
