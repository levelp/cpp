#include <iostream>

using namespace std;

class A {
 public:
  int x;
};

class B {
 protected:
  int y;
 public:
  int getY() {
    return y;
  }
  void setY(int value) {
    y = value;
  }
};

class C : public A, private B {
  // Доступны и x и y
};

int main() {
  C c;
  c.x = 10;
  c.getY();
  c.setY(11);

  return 0;
}
