#include <iostream>

using namespace std;

// Запоминаем значение выравнивания
// в стеке компилятора
#pragma pack(push)
// Выравнивание по 1 байту
#pragma pack(1)
class A {
 public:
  char a;
  virtual
  void show() {
    cout << " a = " << a << endl;
  }
  A() {
    a = 'A';
  }
};

class A2 {
 public:
  char a;
  void show() {
    cout << " a2 = " << a << endl;
  }
  A2() {
    a = '#';
  }
};

class B : public A, public A2 {
 public:
  char a;
  void show() {
    cout << " a = " << a <<
         "  A::a = " << A::a <<
         "  A2::a = " << A2::a <<
         endl;
  }
  B() {
    a = 'B';
  }
};
// Восстанавливаем предыдущее значение
#pragma pack(pop)

int main() {
  A* a[2] = { new A(), new B() };
  a[0]->show();
  a[1]->show();
  cout << "a = " << a[0]->a << endl;
  cout << "a = " << a[1]->a << endl;
  cout << "sizeof(A) = " << sizeof(A) << endl;
  cout << "sizeof(B) = " << sizeof(B) << endl;
  return 0;
}
