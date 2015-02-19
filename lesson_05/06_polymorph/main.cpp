#include <iostream>

using namespace std;

// abstract
// interface  C# / Java
class A {
 public:
  virtual void x() = 0;
  /* {
     cout << "A" << endl;
   }; */
};

class B : public A {
 protected:
  void x() {
    cout << "B" << endl;
  };
};

class C : public A {
 public:
  void x() {
    cout << "C" << endl;
  };
};

int main() {
  A* a[2] = { new B, new C };
  a[0]->x();
  a[1]->x();
  /* B* b = new B;
   b->x(); */
  return 0;
}
