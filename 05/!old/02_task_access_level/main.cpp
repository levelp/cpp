#include <iostream>

class A {
  // Значение - описание где поле видимо
  char* privateA = "only for A";
 protected:
  char* protectedA = "For A and childs";
 public:
  char* publicA = "For all";
};

class Public : public A {
 public:
  void showAll() {
  }
};

class Protected : protected A {
 public:
  void showAll() {
  }
};

class Private : private A {
 public:
  void showAll() {
  }
};

using namespace std;

int main() {
  A a;
  cout << a.publicA << endl;
  Public p1;
  cout << p1.publicA << endl;
  Protected p2;
  Private p3;

  return 0;
}
