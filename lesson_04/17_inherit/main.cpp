// Наследование
// ------------
#include <iostream>

using namespace std;

// struct A <--> class A { public:
// class A <--> struct A { private:
//-->
struct A {
  static int staticInClass;
  int a; // Поле доступно отовсюду

  void doA() {
    cout << "doA()" << endl;
    onlyInA = 2;
    cout << "onlyInA = " << onlyInA << endl;
    forChilds = 10;
  };
 private:
  int onlyInA; // Только внутри класса A
 protected:
  int forChilds; // Внутри класса A и в наследниках
};
//<--

// B - наследник A
//-->
struct B : public A {
  int b;
  int forChilds; // Поле с тем же именем
  void doB() {
    cout << "doB()" << endl;
    //onlyInA = 2; // Недоступно в наследниках
    doA();
    //cout << "onlyInA = " << onlyInA << endl;
    A::forChilds = 12;
    forChilds = 20; // Работает
    this->forChilds = 20; // Работает

    cout << "A::forChilds = " << A::forChilds << endl;
    cout << "B::forChilds = " << B::forChilds << endl;
  };
};
//<--

//
struct C : protected B {
  int c;
  void doC() {
    cout << "doC()" << endl;
    forChilds = 20;
    a = 1;
    b = 3;
    doA();
    doB();
  };

  void doA() {
    A::doA();
  }
};

struct D : public C {
  int d;
  void doD() {
    doA();
    doB();
  }
};

class E : public D {
  void doE() {
  }
};

class L {
 public:
  void doL() {
  }
};

// Множественное наследование
class X : public E, private L {
  void doX() {
    L::doL();
  }
};

class G {
 public:
  void show() {
    cout << "Class G" << endl;
  }
  void a(int x, double y) {
  }
  void show(double x) {
    cout << "Class G " << x << endl;
  }
};

class H {
 public:
  void show() {
    cout << "Class H" << endl;
  }
  void show(int x) {
    cout << "Class H " << x << endl;
  }
};

class W : public G, protected H {
 public:
  void w() {
    //show(); // Ошибка компиляции
    // Мы должны явно указать из какого предка вызываем метод
    G::show();
    H::show();
  }
  void a(double y, int x) {
    a(x, y);
  }
  void show1() {
    G::show(2);
    H::show(2.2);
  }
};

A globalA; // В статической памяти
// потому что это глобальная переменная

int main() {
  A a; // В стеке
  a.a = 1;
  a.doA();
  // a.onlyInA = 3; // 'int A::onlyInA' is private
  A* ap = new A; // Динамическая память
  // 'int A::forChilds' is protected
  //cout << a.forChilds << endl;

  B b;
  // Нет доступа, т.к. onlyInA private
  // b.onlyInA = 10;
  b.a = 1;
  b.b = 2;
  b.doA();
  b.doB();

  C c;
  // c.a = 1; // Ошибка из-за protected наследования
  // c.b = 2; // Ошибка из-за protected наследования
  c.c = 3;
  // c.doA();
  // c.doB();
  c.doC();

  X x;
  //x.doL();

  return 0;
}
