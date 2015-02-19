#include <iostream>

using namespace std;

// a - массив
// N - количество элементов
// T - параметр шаблона
//  произвольный тип, с которым можно выполнять
//  операции (т.е. он подходит по duck typing)
template <class T>
void show(T a[], int N) {
  // Вывести через запятую
  // 2, 3, 4
  for(int i = 0; i < N - 1; ++i)
    cout << a[i] << ", ";

  cout << a[N - 1] << endl;
}

int main() {
  int ints[6] = {2, 4, 6, 7, 10, 11};
  show(ints, 6);

  double d[3] = {2.1, 2.3, 4.5};
  show(d, 3);

  return 0;
}
