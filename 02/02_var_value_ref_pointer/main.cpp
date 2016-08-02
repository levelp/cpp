#include <iostream>

using namespace std;

#define SHOW(x) cout << "[" << #x << " = " << x << "]" << endl;
#define D(x) cout << #x << endl; x;

int main() {
  // Переменные-значения
  int a = 2;
  double d = 2.5;
  char c = 'A';
  // Переменные-ссылки
  SHOW(a)

  //D(
  int& aa = a;
  //); // aa - имя переменной-ссылки
  // a - имя исходной переменной
  SHOW(a)
  SHOW(aa)
  D(aa = 20);
  SHOW(a);
  SHOW(aa);
  D(a = 15);
  SHOW(a);
  SHOW(aa);
  // Переменные-указатели
  D(int* ptrA = &a); // ptrA - указатель
  SHOW(*ptrA); // Разыменование указателя
  D(*ptrA = 12);
  SHOW(*ptrA);
  SHOW(a);
  D(int b = 22;)
  D(ptrA = &b;)
  SHOW(b);
  SHOW(*ptrA);

  return 0;
}
