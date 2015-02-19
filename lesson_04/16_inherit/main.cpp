// Наследование и уровни доступа
// -----------------------------
// **Наследование** - способность производного класса
// наследовать характеристики существующего базового класса
#include <iostream>

using namespace std;

// Базовый класс A
//-->
class A {
 public: // Доступно всем
  int a;  // A test;  test.a = 10;
 protected: // Доступно внутри класса и наследникам
  int forChilds; // из методов этого и наследников
 private:  // Доступно только внутри методов
  int privateA; // этого класса
};
//<--

// B - наследник класса A
//-->
class B : public A { // Все поля и методы
 public: // кроме private доступны
  int a;
  int b;
  void method1() {
    a = 1;
    b = 2;
    forChilds = 10;
    A::a = 10;
    B::a = 11;
    // privateA = 1; // Невозможно
    // this->privateA;
  }
};

class C : public B {
 public:
  int c;
  int a;
  // if(dynamic_cast<A>(this) != NULL)
};
//<--

int main() {
  // Извне можно обратиться только
  // к public-полям и методам
  A a1, a2;
  a1.a = 1;
  B b1;
  b1.a = 2;
  b1.b = 3;
  //b1.forChilds = 5;

  return 0;
}
//<--
