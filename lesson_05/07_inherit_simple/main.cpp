#include <iostream>

using namespace std;

// Класс A - предок класса B
class A {
 public:
  int field1;
};

// Класс B - наследник класса A
class B : public A {
 public:
  int field2;
  void methodB() {
    int x = field1 + field2;
  }
};

int main() {
  A a;
  a.field1 = 1;

  B b;
  b.field1 = 10;
  b.field2 = 12;

  return 0;
}
