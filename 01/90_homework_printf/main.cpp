#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  // for(инициализация; условие_продолжения;
  //    шаг_после_тела_цикла)
  for(int i = 0; i < 10; i++)
    printf("%3d ", i);

  printf("\n =========== \n");
  //   0   1   2   3   4   5   6   7   8   9

  // ijk..
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++)
      printf("(%2d %2d) ", i, j);

    printf("\n");
  }

  return 0;
}
