#include <iostream>

using namespace std;

class A {
 protected:
  char name;
 public:
  A() : name('A') {
    cout << "Constructor A" << endl;
  }
  A(int aa) : name('A') {
    cout << "Constructor2 A" << endl;
  }
  virtual ~A() {
    cout << "Destructor A: " << name << endl;
  }
};

class B : public A {
  int a, b;
 public:
  B() : A(2), a(1), b(a + 2) {
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;
    name = 'B';
    cout << "Constructor B" << endl;
  }
  ~B() {
    cout << "Destructor B: " << name << endl;
  }
};

int main() {
  A* a[2] = { new B, new A };

  for(int i = 0; i < 2; ++i)
    delete a[i];

  return 0;
}
