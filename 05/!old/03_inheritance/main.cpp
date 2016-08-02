#include <iostream>

using namespace std;

class A {
 public: // Доступно извне (пользователям объекта)
  int publicA;
 private: // Доступно только внутри класса A
  int privateA;
 protected: // Доступно наследникам по всей иерархии
  // до первого private наследования
  int protectedA;
 public:
  void methodA() {
    publicA = 1;
    privateA = 2;
    protectedA = 3;
  }
};

class BPublic : public A {
 public:
  void methodBPublic() {
    publicA = 1;
    // privateA = 2; // Недоступен
    // т.к. private доступны только внутри класса
    protectedA = 3;
  }
};

// protected - наследуем класс A
//  только для себя и наследников
class BProtected : protected A {
 public:
  void methodBProtected() {
    publicA = 1;
    // privateA = 2; // Недоступен
    // т.к. private доступны только внутри класса
    protectedA = 3;
  }
};

// В наследнике C доступны те же поля
class C : public BProtected {
  void methodC() {
    publicA = 1;
    // privateA = 2; // Недоступен
    // т.к. private доступны только внутри класса
    protectedA = 3;
  }
};

// private - наследуем класс A
//  только для себя (без наследников)
class BPrivate : private A {
 public:
  void methodBProtected() {
    publicA = 1;
    // privateA = 2; // Недоступен
    // т.к. private доступны только внутри класса
    protectedA = 3;
  }
};

class CBPrivate : public BPrivate {
 public:
  void methodCBPrivate() {
    // Недоступно ничего из A
    //  A -> private B -> public C
    // publicA = 1;
    // privateA = 2; // Недоступен
    // т.к. private доступны только внутри класса
    // protectedA = 3;
  }
};

int main() {
  A a;
  a.publicA = 10;
  // a.privateA = 10; // Недоступно
  // a.protectedA = 10; // Недоступно

  BPublic bPublic;
  bPublic.publicA = 10;
  //bPublic.privateA = 10; // Недоступно
  //bPublic.protectedA = 10; // Недоступно

  BProtected bProtected;
  // bProtected.publicA = 111;

  // C.publicA = 12;

  return 0;
}
