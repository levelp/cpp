// Перенаправление консольного ввода/вывода
// ----------------------------------------
#include <iostream>
// Подключаем cstdio для **freopen**
//-->
#include <cstdio>
//<--

using namespace std;

int main_redirect() {
  // Ввод из файла вместо консоли:
  //-->
  freopen("sum.in", "r", stdin); // stdin - поток ввода с консоли
  //<--
  // Вывод в файл вместо консоли:
  //-->
  freopen("sum.out", "w", stdout);
  //<--

  // Дальше работаем с файлами как с консолью
  //-->
  long long a, b;
  cin >> a >> b;
  cout << a << " + " << b << " = " << (a + b) << endl;
  //<--
  return 0;
}
