// Наследование: поле с тем же имененем
// ------------------------------------
#include <iostream>

using namespace std;

// Пусть есть класс **A**
// с полем **x** и методом **show**
//-->
struct A {
  int x = -1;
  void show() {
    cout << "x = " << x << endl;
  }
};
//<--

// И его наследник **B**
// тоже с полем **x** и методом **show**
//-->
struct B : public A {
  int x = -2;
  void show() {
    cout << "x = " << x << endl;
    A::x++;
    cout << "A::x = " << A::x << endl;
    cout << "B::x = " << B::x << endl;
  }
};
//<--

// Как получить доступ к каждому из полей **x**?

//-->
int main() {
  A a;
  B b;
  //a.x = 1;
  a.show();
  //b.x = 2;
  b.A::show();
  b.B::show();
  //b.show();
  return 0;
}
//<--
