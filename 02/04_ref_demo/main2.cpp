#include <iostream>

using namespace std;

int f1(int value) {
  value++;
  cout << "f1 = " << value << endl;
}

int f2(int& value) {
  value++;
  cout << "f2 = " << value << endl;
}

int f3(int* value) {
  (*value)++;
  cout << "f3 = " << *value << endl;
}


int main() {
  /*  int value = 10;
    value = 11;
    // int & - объявляем ссылку
    int &b = value; // b и value - одна и та же переменная
      // только с 2-мя именами
    b = 10; // изменилось value
    value = 12; // изменилось b

    int* ptrA; int valueA;
      // ptrA - указатель, valueA - значение

    ptrA = &value; // Указатель ptrA указывает на
      // переменную value

    // *ptrA и value - одна и та же переменная
    value = 1000; // изменится и *ptrA
    *ptrA = 111; // изменится и value

    int d;
    ptrA = &d;

  */
  int value = 1;

  f1(value);
  cout << "after f1 = " << value << endl;

  f2(value);
  cout << "after f2 = " << value << endl;

  f3(&value);
  cout << "after f3 = " << value << endl;



  return 0;
}
