<!-- doc.py -->
Принцип:
1. private - доступно только внутри данного класса
2. protected - + наследникам
3. public - + всем извне
При наследовании:
A -> B -> C -> D...
Уровень доступа - минимум из всех модификаторов
для данного поля/метода.
``` cpp
class Base {
 private:
  // Только для "частного" использования
  // т.е. внутри класса Base
  int privateVar;
 protected: // Внутри класса Base
  int protectedVar;  // и в наследниках
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
  // только public: => protected:
  // protected - наследую для себя и для потомков
  void f() {
    // privateVar = 122; // Недоступна
    protectedVar = 102;
    publicVar = 3;
  }
};

// Наследуем поля только для себя
class Private : private Base { /*, public A */
  // private класса Base недоступен
  // protected и public становятся private
 public:
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
  pr.f();

  return 0;
}
[main.cpp](main.cpp)

