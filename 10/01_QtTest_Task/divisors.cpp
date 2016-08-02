#include "divisors.h"
#include <cmath>

// Подсчёт количества делителей
// Входные данные:
//   N - целое число
// Результат: количество делителей
int calcDiv(int N) {
  int count = 0;
  int sN = sqrt(abs(N));

  for(int i = 1; i <= sN; ++i) {
    if(N % i == 0) {
      count++;
      int i2 = N / i;

      if(i != i2)
        count++;
    }
  }

  return count;
}

int calcDivSlow(int N) {
  int count = 0;

  for(int i = 1; i <= abs(N); ++i) {
    if(N % i == 0)
      count++;
  }

  return count;
}
