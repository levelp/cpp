#include <iostream>

using namespace std;

int main() {
  // Выводим N в двоичной системе счисления
  // разряды в обратном порядке
  int N = 11;

  while(N) {
    cout << N % 2;
    N /= 2;
  }

  cout << endl;

  do {
    cout << "Enter number (0-for exit): ";
    cin >> N;
    //...
  } while(N != 0);

  return 0;
}
