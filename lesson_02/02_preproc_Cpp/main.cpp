// Подключение библиотек
#include <iostream>

// Препроцессор
// Preprocessor
//#include <aclui.h>

#define MY_VALUE 2+3+55

#define ADD_2(value) value+2

#define SHOW(x) cout << __FILE__ << \
                     ":" << __LINE__ << " " << \
                     #x << " = " << x << endl

#define forn(i, s, n) for(int i = s; i < (int)n; ++i)

using namespace std;

// Основная программа
int main() {
#ifdef EXTRA_DEBUG
  cout << "Debug info" << endl;
#elif DEBUG2

#endif

#ifndef _WIN32
  ss
#endif // WIN32

  //#ifdef sizeof(int) != 2
  //#error This code only for Linux
  //#endif // WIN32




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

  /*forn(i,0,10)
    forn(j,0,10)
      SHOW(i*j); */

  // Код возврата
  return 0;
}
