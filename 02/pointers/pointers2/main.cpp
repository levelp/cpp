// Пример на ссылки и указатели
#include <iostream>

using namespace std;

int c = 0;

void f1(int& i) {
  i = 10;
}

void f2(int i) {
  i = 20;
  cout << "i = " << i << endl;
}

void f3(char* i) {
  // i - указатель, т.е. это
  // переменная содержащая адрес
  //i = &c;
  *i = 33;
}

int main() {
  int a = 2;
  int b = 3;
  int* a_ptr; // Указатель
  a_ptr = &a;

  int& a_ref = a; // Ссылка
  a_ref = b;

  a_ptr = &b;

  cout << "a_ref = " << a_ref << endl;

  f1(a);
  cout << "a = " << a << endl;

  f2(a);
  cout << "a = " << a << endl;

  f3((char*)&a);
  cout << "a = " << a << endl;

  return 0;
}
