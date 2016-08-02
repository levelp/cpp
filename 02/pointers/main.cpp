#include <iostream>

using namespace std;

// Исходное значение не меняется
void f1(int i) {
  i++;
  cout << "f1: i = " << i << endl;
}

// Передаём ссылку -> меняем исходное значение
void f2(int& i) {
  i++;
  cout << "f2: i = " << i << endl;
  cout << "Address = " << &i << endl;
}

// Передаём указатель -> меняем исходное значение
void f3(int* i) {
  (*i)++;
  cout << "f3: i = " << *i << endl;
  cout << "Address = " << i << endl;
}

int main() {
  int i = 1;
  cout << "Before: i = " << i << endl;
  f3(&i);
  cout << "After: i = " << i << endl;
  return 0;
}
