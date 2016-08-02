#include <iostream>

using namespace std;

class A {
 public:
  int x;
  int uniqueName;
  int var;
};

class A2 {
 private:
  int var; // private
 public:
  int x; // Поле с тем же именем, что и в A
};

class B : public A, public A2 {
  // B - наследует поля и методы и из A и из A2
  void f() {
    // error: reference to 'x' is ambiguous|
    // x = 2;
    A::x = 2;
    A2::x = 10;
    // Если уникальна
    uniqueName = 32;
    // Хоть var из A2 и не видно, всё равно надо
    // указать класс
    A::var = 122;
  }
};


int main() {
  cout << "Hello world!" << endl;
  return 0;
}
