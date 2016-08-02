#include <iostream>

using namespace std;

//-->
struct A {
 private:
  int a;

 public:
  A() {
    a = 33;
  }

  // setter - метод для установки значения поля
  void setA(int value) {
    cout << "a = " << value << endl;
    a = value;
  }
  // getter - метод для получения значения поля
  int getA() {
    return a;
  }
};


int main() {
  A a1; // A - класс, a1 - объект
  a1.setA(20);
  cout << a1.getA() << endl;
  return 0;
}
//<--
