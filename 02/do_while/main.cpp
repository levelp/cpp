// Пример на цикл с постусловием
// Вывод числа N в двоичной системе счисления
// Двоичные цифры в обратном порядке
#include <iostream>

using namespace std;

int main() {
  int N = 6;
  cout << "N = " << N << " = (inverse binary) = ";

  do {
    cout << N % 2;
    N /= 2;
  } while(N > 0);

  cout << endl;

  return 0;
}
