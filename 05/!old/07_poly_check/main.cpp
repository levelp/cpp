#include <iostream>

using namespace std;

#define SHOW(x) { cout << #x << " = " << x << endl; }

struct A {
  int size = 10;
  virtual int getSize() {
    return size;
  }
};

struct B : public A {
  int size = 100;
  int getSize() {
    return size;
  }
};

int main() {
  A* a = new B();
  SHOW(a->size);
  SHOW(a->getSize());
  return 0;
}
