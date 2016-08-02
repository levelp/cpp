#include <stdio.h>
#include <stdlib.h>

// Константа без типа имеет тип int в C (но не в C++)
const i = 56;

int main() {
  printf("%d\n", i);
  return 0;
}
