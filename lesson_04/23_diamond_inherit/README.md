Diamond Inheritance
-------------------
``` cpp
//   A
//  / \
// B   C
//  \ /
//   D
#include <iostream>

using namespace std;

struct X {
  void show() {
    cout << "X" << endl;
  };
};

struct A {
  char name;
  A() : name('A') {};
  virtual
  void show() {
    cout << "show_A " << name << endl;
  };
};

struct B : virtual public A {
  B() {
    A::name = 'B';
  };
  void show() {
    cout << "show_B " << name << endl;
  };
};

struct C : virtual public A {
  C() {
    A::name = 'C';
  };
  void show() {
    cout << "show_C " << name << endl;
  };
};

struct D : public B, public C {
  D() {
    B::name = 'D';
  };
  void show() {
    cout << "show_D " << B::name << endl;
    /*B::show();
    C::show();
    C::A::show();
    B::A::show(); */
  };
};

int main() {
  /*A a;
  a.show();

  'B b;
  b.show();
  C c;
  c.show(); */

  //D d;
  //d.show();
  /*A* x[4] = {new A, new B, new C, new D};
  for(int i = 0; i < 4; ++i)
    x[i]->show();
  */
  // Полиморфизм
  B* b = new D;
  C* c = new D;
  b->show();
  c->show();

  return 0;

  A* x[4] = { new B, new A, new C, new D };
  /* A* x[4];
   x[0] = new C;
   x[1] = new B;
   x[2] = new A;
   x[3] = new D; */

  cout << "sizeof(X) = " << sizeof(X) << endl;
  cout << "sizeof(*X) = " << sizeof(X*) << endl;

  cout << "+ VMT" << endl;
  cout << "sizeof(A) = " << sizeof(A) << endl;
  cout << "sizeof(*A) = " << sizeof(A*) << endl;

  for(int i = 0; i < 4; ++i)
    x[i]->show();

  for(int i = 0; i < 4; ++i)
    delete x[i];

  return 0;
}
```

[main.cpp](main.cpp)

