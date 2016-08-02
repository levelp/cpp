// Чистый C
// --------
#include <stdio.h>
#include <stdlib.h>

int main() {
  int N = 10;
  int a, b;

  printf("N = %d\n", N);
  scanf("%d %d", &a, &b);
  /* a -> значение */
  printf("a + b = %d\n", a + b);

  a = b * b;
  printf("a = %d\n", a);

  return 0;
}
