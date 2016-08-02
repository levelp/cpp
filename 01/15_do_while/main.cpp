// Цикл с постусловием
// -------------------
// Вывод числа N в двоичной системе счисления
// Двоичные цифры в обратном порядке
#include <iostream>

using namespace std;

int main() {
  //-->
  int N = 254;
  cout << "N = " << N << " = (inverse binary) = ";

  do { // Repeat
    cout << N % 2;
    N /= 2;
  } while(N > 0); // Until

  cout << endl;
  //<--

  return 0;
}
