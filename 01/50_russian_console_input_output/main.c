#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
  setlocale(LC_ALL, "Russian");

  int d = 10;
  long ld = 10000;
  long long lld = 1231222L;

  printf("%d %ld %lld\n", d, ld, lld);

  printf("%x\n", d);
  printf("%X\n", d);

  float f = 1.2f;
  printf("%10.3f %10.3f\n", f, f);
  double dbl = 1.32;
  printf("%lf\n", dbl);
  //    long double ldbl = 1.22;
  //printf("%L\n", ldbl);

  char c = 'D';
  printf("%c\n", c);

  char s[] = "Test";
  printf("%s\n", s);

  return 0;
}
