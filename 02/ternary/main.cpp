// Тернарный оператор
#include <iostream>

using namespace std;

int main() {
  int a = 4, b = 0;

  const bool cond = a > 3;

  // Может находиться слева от оператора присваивания
  (cond ? a : b) = 1;

  cout << "a = " << a << "  b = " << b << endl;

  // Вложенные тернарные операторы
  int i = (a < 3) ? ((b < 2) ? 4 : 5 + a + b * 20)
          : (b > 3 ? 4 : 2);

  return 0;
}
