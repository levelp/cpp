#include <iostream>

using namespace std;

class A {
  int i;
  void f();
};

class B {
  int i;
  virtual void f();
};

#define show(x) cout << #x << " = " << x << endl;

int main() {
  show(sizeof(A));
  show(sizeof(B));
  show(sizeof(A*));
  show(sizeof(B*));
  return 0;
}
