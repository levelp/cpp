#include <iostream>

using namespace std;

struct S {
  int a, b;
  static int staticField;

  static void method1() {
    static int var2 = 19;
    cout << "method1()" << endl;
  }

  // Нестатический метод
  void myMethod() {
    a = 1;
    b = 20;
    staticField = 10;
  }

  friend S function1();
};

S function1() {
  S s;
  s.a = 10;
  s.b = 11;
  return s;
}

struct B : public S {
  static void method2() {
    cout << "method2()" << endl;
    method1();
  }
};

int S::staticField = 10;

#define SHOW(x) { cout << #x << " = " << x << endl; }

int main() {
  S::method1();

  S s, s1;
  s.a = 1;
  s.b = 2;
  s.staticField = 11;
  s1.a = 1;
  s1.b = 2;
  s1.staticField = 12;
  SHOW(s.staticField);
  SHOW(s1.staticField);

  S::staticField = 30;
  SHOW(S::staticField);
  SHOW(s.staticField);
  SHOW(s1.staticField);

  B::staticField = 111;
  B::method1();

  S s2 = function1();

  return 0;
}
