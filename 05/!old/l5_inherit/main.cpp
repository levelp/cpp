#include <iostream>

using namespace std;

// Наследование
class A {
 public:
  // Полиморфизм
  virtual void show() {
    cout << "A" << endl;
  }
  void method2() { // Этот метод все наследуют
    cout << "Method2" << endl;
  }
};

class B : public virtual A {
 public:
  void show() {
    cout << "B" << endl;
  }
  void bb() {
    cout << "bb" << endl;
  }
};

class C : public virtual A {
 public:
  void show() {
    cout << "C" << endl;
  }
};

class D : public B, public C {
 public:
  void show() {
    cout << "D" << endl;
  }
};

int main() {
  A* a[4] = { new A(), new B(), new C(), new D() };

  for(int i = 0; i < 4; i++)
    a[i]->show();

  B* b = dynamic_cast<B*>(a[2]);
  b->bb();

  return 0;
}
