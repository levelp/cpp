// Подключение библиотек
#include <iostream>

#define MY_VALUE 2+3+55

#define ADD_2(value) value+2
#define SHOW(x) cout << #x << " = " << x << endl;

using namespace std;

// Основная программа
int main() {
  // Вывод на экран строчки
  int a, b;
  /*   cout << "a = ";
     cin >> a;
     cout << "b = ";
     cin >> b;
     cout << "a + b = " << a + b << endl;*/
  cout << ADD_2(10) << endl;

  //int c = 1+2;
  //cin >> c;
  //a = 10;
  // c += a += 2;
  // SHOW(c);

  // Обмен двух переменных значениями
  // без третьей переменной
  a = 2;
  b = 325;
  a ^= b ^= a ^= b; // XOR (исключающее ИЛИ)
  SHOW(a);
  SHOW(b);

  // Код возврата
  return 0;
}
