/// Ключевое слово friend
/// =====================
#include <iostream>

using namespace std;

/// Класс X, который будет вызывать
/// приватный метод класса Y
class X {
 public:
  void methodX();
};

class Y {
  // Предоставляем доступ всему классу X:
  //friend class X;
  // Или его конкретному методу
  friend void X::methodX();
  int data = 10;
  void methodY() {
    cout << "methodY: data = " << data << endl;
  }
};

void X::methodX() {
  cout << "methodX" << endl;
  // Call private method
  Y y;
  y.data = 20;
  y.methodY();
}

int main() {
  X x;
  x.methodX();
  return 0;
}
