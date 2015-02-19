#include <iostream>

using namespace std;

//-->
void inc2(int& value) {
  value += 2;
}

int main() {
  int value = 11;
  // int & - объявляем ссылку
  int& b = value; // b и value - одна и та же переменная
  // только с 2-мя именами
  b = 10; // изменилось value
  value = 12; // изменилось b

  int* ptrA, valueA; // ptrA - указатель, valueA - значение
  valueA = 122;

  ptrA = &value; // Указатель ptrA указывает на
  // переменную value

  // *ptrA и value - одна и та же переменная
  value = 1000; // изменится и *ptrA
  *ptrA = 111; // изменится и value

  int d;
  ptrA = &d;

  int x = 1, y = 10;
  inc2(x);
  inc2(y);

  return 0;
}
//<--
