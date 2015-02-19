// Объявление и вызов функций
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
  if(a < b)
    return a;
  else
    return b;
}

double fmin(double a, double b) {
  if(a < b)
    return a;
  else
    return b;
}

// fabs, abs

int main() {
  printf("Hello world!\n");
  return 0;
}
