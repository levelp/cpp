#include <iostream>

using namespace std;

class Base {
  // Только для "частного" использования
  // т.е. внутри класса Base
  int privateVar;
 protected: // Внутри класса Base
  // и в наследниках
  int protectedVar;
 public:
  int publicVar;
};

class Public : public Base {
  void f() {
    // privateVar = 122; // Недоступна
    protectedVar = 102;
    publicVar = 3;
  }
};

class Protected : protected Base {
  // Так же, как при public-наследовании
  void f() {
    // privateVar = 122; // Недоступна
    protectedVar = 102;
    publicVar = 3;
  }
};

// Наследуем поля только для себя
class Private : private Base { /*, public A */
  void f() {
    // privateVar = 122; // Недоступна
    protectedVar = 102;
    publicVar = 3;
  }
};

int main() {
  Base base;
  base.publicVar = 10;
  // base.privateVar = 1;

  Public pub;
  pub.publicVar = 10;
  // pub.privateVar - недоступна

  Protected p;
  // p.publicVar = 11;

  Private pr;

  cout << "Hello world!" << endl;
  return 0;
}
