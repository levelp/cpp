// Чистый C
#include <stdio.h>
//#include <stdlib.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Russian");

  int a = 2;
  int b = 3;
  int c = a + b;

  printf("Это моя первая программа!\n");

  printf("%d+%d=%d\n", a, b, c);

  return 0;
}
