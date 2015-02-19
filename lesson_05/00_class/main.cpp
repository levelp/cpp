#include <iostream>

using namespace std;

class A {
 public:
  int field1;
  int method1(int arg1, double arg2) {
    return arg1 + arg2;
  }
};

struct S {
 private:
  int field1;
  int method1(int arg1, double arg2) {
    return arg1 + arg2;
  }
};

class MyClass {
};

int main() {
  A a1, a2;

  MyClass object1, object2, f;

  object1 = object2;

  return 0;
}
