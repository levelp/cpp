#include <iostream>

using namespace std;

class A {
 public:
  A() {
    cout << "Constructor A" << endl;
  }
  virtual ~A() {
    cout << "Destructor A" << endl;
  }
};

class B : public A {
 public:
  B() {
    cout << "Constructor B" << endl;
  }
  ~B() {
    cout << "Destructor B" << endl;
  }
};

int main() {
  A* a = new B;

  delete a;
  return 0;
}
