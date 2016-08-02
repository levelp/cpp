#include <iostream>

using namespace std;

int main() {
  // Выводим N в двоичной системе счисления
  // разряды в обратном порядке
  int N = 11;

  // while - цикл с предусловием
  while(N) { // while(N != 0) {
    cout << N % 2;
    N /= 2;
  }

  cout << endl;

  // цикл с постусловием
  int sum = 0;

  do {
    cout << "Enter number (0-for exit): ";
    cin >> N;
    sum += N;
  } while(N != 0);

  cout << "sum = " << sum << endl;

  return 0;
}
