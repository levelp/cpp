#include <iostream>

using namespace std;

int main() {
  int A[3][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 9, 10}
  };

  // Поиск минимума
  int minValue = A[0][0];

  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      if(A[i][j] < minValue)
        minValue = A[i][j];

  // Сумма всех элементов
  int sum = 0;

  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      sum += A[i][j];

  return 0;
}
