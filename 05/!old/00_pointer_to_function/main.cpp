/// Указатель на функцию
/// --------------------
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/// Определение нового типа **MyFunction**
/// Спецификация функции:
/// * тип возвращаемого значения - int
/// * тип первого параметра int
/// * тип второго параметра void*
///-->
typedef int (*MyFunction)(int, void*);
///<--

/// Две реализации функции
///-->
int f1(int a, void* b) {
  cout << __FUNCTION__ << "(" << a << ", " << b << ")" << endl;
  return 1;
}

int f2(int a, void* b) {
  cout << __FUNCTION__ << "(" << a << ", " << b << ")" << endl;
  return 2;
}
///<--

/// Функция, которая на вход получает double
/// и возвращает тоже double (например: sin/cos)
///-->
typedef double (*DoubleFuncPtr)(double);
///<--

void showFuncTable(DoubleFuncPtr f) {
  cout << fixed << setprecision(4);
  cout << "--------------------------" << endl;

  for(double x = -2.0; x < 2.0; x += 0.1)
    cout << setw(8) << x << " -> " << setw(8) << (*f)(x) << endl;
}

int main() {
  MyFunction xFunc = f1; // Какую функцию вызываем
  cout << (*xFunc)(1, NULL) << endl;
  cout << (*xFunc)(2, NULL) << endl;
  xFunc = f2;
  cout << (*xFunc)(10, NULL) << endl;

  // error: invalid conversion from
  // 'int (*)(int, void*)' to
  // 'DoubleFuncPtr {aka double (*)(double)}'
  //showFuncTable(&f1);
  showFuncTable(&sin);
  showFuncTable(cos); // Может не работать

  return 0;
}
//<--

