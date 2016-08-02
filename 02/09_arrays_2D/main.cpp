#include <iostream>

using namespace std;

#define SHOW(x) cout << #x << " = " << x << endl;

int main() {
  // 3x3 3 строки 3 столбца
  int A[3][3] = {
    // 0  1  2
    { 1, 2, 3 }, // 0
    { 4, 5, 6 }, // 1
    { 7, 9, 10}  // 2
  };
  SHOW(A[2][0]); // 7

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
