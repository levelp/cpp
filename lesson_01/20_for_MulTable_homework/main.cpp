// Таблица умножения с выравниванием столбцов
#include <stdio.h>

int main() {
  for(int i = 1; i <= 15; i++) {
    for(int j = 1; j <= 15; j++)
      printf("%3d ", i * j);

    printf("\n");
  }

  return 0;
}
