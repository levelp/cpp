// Минимум в массиве
// -----------------
// Пользователь вводит количество элементов
// в массиве.
// Затем каждый элемент массива.
// Все элементы - целые (int).
// Вызывается функция, возвращающая
// минимальный элемент массива
// Массив содержит хотя бы 1 элемент.
// Задание: найти минимум и вернуть

#include <iostream>
#include <limits>
#include <cassert> // для функции assert

using namespace std;

//-->
int arrayMin(int A[], int N) { // var N
  assert(N > 0);
  int curMin = A[0]; // Текущий минимум - первый элемент

  for(int i = 1; i < N; ++i)
    if(A[i] < curMin) // Если встретили элемент меньше
      curMin = A[i];     // => обновили текущий минимум

  return curMin;
}

void f() { // procedure F;
}

int main() {
  assert( 2 * 2 == 4 );

  // Ввод количества элементов массива
  int N;

  do {
    if(!cin.good()) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(),
                 '\n');
    }

    assert(cin.good());
    cout << "N = ";
    cin >> N;
  } while(!cin.good() && N < 1);

  // Заводим массив A в динамической памяти
  int* A = new int[N];

  // Вводим массив с консоли
  for(int i = 0; i < N; ++i) {
    cout << "A[" << i << "] = ";
    cin >> A[i];

    if(!cin.good()) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(),
                 '\n');
      cout << "Error: not a valid integer" << endl;
      --i;
    }
  }

  // Вызываем функцию поиска минимума и
  // выводим результат на консоль
  cout << "min = " << arrayMin(A, N) << endl;

  // Очищаем занимаемую динамическую память
  delete[] A;

  return 0;
}
//<--

