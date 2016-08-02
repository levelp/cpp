#include <iostream>
#include <algorithm> // sort Алгоритмы из STL

using namespace std;

// Пример массива для сортировки
const int N = 6;
int A[N] = {1, 10, -2, 5, 6, 11};

// Вывод массива
void show() {
  for(int i = 0; i < N; ++i)
    cout << A[i] << " ";

  cout << endl;
}

int main() {
  show();
  // Задание: отсортировать массив
  // {-2, 10, 1, 5, 6, 11}
  // {-2, [ 1, 10, 5, 6, 11 ] }
  // {-2, 1, [5, 10, 6, 11 ] }
  int changes;

  do {
    changes = 0; // нет перестановок в массиве

    for(int i = 0; i < N - 1; ++i) {
      if(A[i] > A[i + 1]) {
        // SWAP
        //int temp = A[i];
        //A[i] = A[i+1];
        //A[i+1] = temp;
        //A[i] ^= A[i+1] ^= A[i] ^= A[i+1];
        cout << "swap(" << A[i] << ", " << A[i + 1] << ")" << endl;
        swap(A[i], A[i + 1]);
        show();
        changes = 1;
      }
    }

    cout << "  changes " << changes << " -> ";
    show();
  } while(changes);

  //  i
  // --------------------
  //  0 | 1 | 2 | 3 | 4
  // --------------------
  //      j
  // i всегда левее чем j
  // Тогда если мы сортируем по возрастанию
  // то A[i] должно быть < чем A[j]
  for(int i = 0; i < N; ++i)
    for(int j = i + 1; j < N; ++j)
      if(A[i] > A[j]) {
        cout << "swap(" << A[i] << ", " << A[j] << ")" << endl;
        swap(A[i], A[j]);
        show();
      }

  // -----
  // | 1 | 0
  // -----
  // | 3 | 1
  // -----
  // | 5 | 2
  // -----
  // | 6 | 3  <-- i
  // -----
  // | 7 | 4
  // -----

  // Снова вывести на экран
  show();

  return 0;
}
