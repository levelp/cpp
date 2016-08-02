// Ссылки в C++
#include <iostream>

using namespace std;

void f1(int x) {
  cout << "x = " << x << endl;
  x++;
  cout << "x = " << x << endl;
}

void f2(int& x) {
  cout << "x = " << x << endl;
  x++;
  cout << "x = " << x << endl;
}

void f3(int* x) {
  cout << "x = " << *x << endl;
  (*x)++;
  cout << "x = " << *x << endl;
}

void example2() {
  int a = 2;
  cout << "a = " << a << endl;
  f1(a);
  cout << "a = " << a << endl;
  a = 10;
  cout << "a = " << a << endl;
  f2(a);
  cout << "a = " << a << endl;
  a = 20;
  cout << "a = " << a << endl;
  f3(&a);
  cout << "a = " << a << endl;
}

void example1() {
  int a = 2; // a - локальная переменная, в ней 2
  int& b = a; // b - ссылка на a, т.е. та же переменная с другим именем
  int* c = &a; // с - указатель на a..
  int d = 10;
  b = 3;
  cout << "a = " << a << "  b = " << b << endl;
  a = 5;
  cout << "a = " << a << "  b = " << b << endl;
  cout << c; // Выводим адрес
  cout << *c; // Выводим значение
  *c = 4;
  cout << "a = " << a << "  b = " << b << " c = " << *c << endl;

  // В с теперь будет адрес d
  c = &d;
  cout << *c << endl; // Теперь выведем значение d
}



void example3() {
  int* c; // c - указатель на целое число
  int d = 45;
  c = &d;
  cout << "d = *c = " << *c << endl;

  {
    int t;
  }
  int j = 1;

}

int main() {
  //example1();
  example2();
  //example3();

  return 0;
}
