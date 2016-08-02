#include <iostream>

using namespace std;

int main() {
  int a = 10;
  int& b = a; // Ссылка
  // int &bb;  // error: 'bb' declared as
  // reference but not initialized
  int d = 22;
  // &b = d; // Нельзя переопределять ссылки

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  b = 11;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  int* ptr; // Указатель можно не инициализировать

  // Указывает на переменную a
  ptr = &a;
  cout << "*ptr = " << *ptr << endl;

  ptr = &d;
  cout << "*ptr = " << *ptr << endl;

  ptr = NULL;

  return 0;
}
