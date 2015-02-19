// ЗАДАЧА: посчитать сумму.
// Нумерация элементов массива с 0
// Все элементы на чётных местах взять с "+"
// Все элементы на нечётных местах с "-"
// Чётные: 0, 2, 4, 6 и т.д.
// Нечётные: 1, 3, 5...
#include <iostream>

using namespace std;

int sum(int A[], int N) {
  // Сумма равна 0
  int result = 0;

  for(int i = 0; i < N; ++i)

    // Если элемент нечётный i % 2 == 1
    // если чётный i % 2 == 0
    //result += (i % 2) ? -A[i] : A[i];
    if(i % 2 == 0)
      result += A[i];
    else
      result -= A[i];


  return result;
}

int sum2(int A[], int N) {
  int result = 0;

  // Суммируем только чётные
  for(int i = 0; i < N; i += 2)
    result += A[i];

  // Суммируем только нечётные
  for(int i = 1; i < N; i += 2)
    result -= A[i];

  return result;
}

int main() {
  int A[6] = {1, 3, -2, 4, 2, 10};
  // 1 - 3 -2 -4 + 2 -10 = -16
  cout << sum(A, 6) << endl;

  int i = 2;
  {
    int i = 10;
    cout << "i = " << i << endl; // i = 10
  }
  cout << "i = " << i << endl; // i = 2

  return 0;
}
