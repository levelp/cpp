#include <iostream>

using namespace std;

// Поиск минимума в массиве
int min_array(int a[], int N) {
  int index = 0; // res - текущий минимум

  // Пробежим по остальному массиву
  // каждый раз добавляя по одному элементу
  // и если он меньше текущего минимума
  // обновим минимум
  for(int i = 1; i < N; ++i)
    index = (a[i] < a[index]) ?
            i : index;

  return a[index];
}

int min_array2(int a[], int N) {
  int cur_min = a[0]; // res - текущий минимум

  // Пробежим по остальному массиву
  // каждый раз добавляя по одному элементу
  // и если он меньше текущего минимума
  // обновим минимум
  for(int i = 1; i < N; ++i)
    if(a[i] < cur_min)
      cur_min = a[i];

  return cur_min;
}

int main() {
  // Индексы: 0  1  2  3
  int a[] = {22, 4, 29, 2};
  // Вызов функции, ожидаем на выходе 4
  cout << min_array(a, 4) << endl;
  return 0;
}
