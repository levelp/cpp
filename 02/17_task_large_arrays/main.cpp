#include <iostream>
#include <cstdlib>

using namespace std;

//-->
const int SIZE = 100000;

// int A[]
// int &A[]
// /*, int arraySize*/ /* параметры */
int arrayMax(int* A) {
  // Предположим, что максимум это первый элемент
  int curMax = A[0];
  A[0] = -10; // Портим массив :)

  // Пробежим по остальным элементам массива
  // если какой-то элемент больше текущего
  // максимума, то запомним новый текущий максимум
  for(int i = 1; i < SIZE; ++i)
    if(A[i] > curMax)
      curMax = A[i];

  cout << "A[0] = " << A[0] << endl;

  return curMax;
}

int main() {
  // Массив в стеке
  int A[SIZE];

  // Заполняем случайными числами
  for(int i = 0; i < SIZE; ++i) {
    A[i] = rand() % 10000;    // от 0 до 9999
  }

  A[0] = -1;
  cout << "A[0] = " << A[0] << endl;

  cout << "max = " << arrayMax(A) << endl;

  cout << "A[0] = " << A[0] << endl;

  return 0;
}
//<--