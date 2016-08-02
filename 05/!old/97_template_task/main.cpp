// Пользователь вводит количество чисел
// Затем сами числа.
// Написать универсальную шаблонную функцию
// для поиска максимума в массиве
#include <iostream>
#include <string>

using namespace std;

template<class T>
T findMax(T A[], int N) {
  if(N < 1) throw string("Array is empty");

  // TODO: реализовать
  T m = A[0];

  for(int i = 1; i < N; i++)
    if(A[i] > m)
      m = A[i];

  return m;
}

int main() {
  int N;
  cout << "N = ";
  cin >> N;
  int* A = new int[N];

  for(int i = 0; i < N; i++) {
    cout << "A[" << i << "] = ";
    cin >> A[i];
  }

  cout << findMax(A, N) << endl;
  string S[] = {"Hello", "World", "Test"};
  cout << findMax(S, 3) << endl;
  return 0;
}
