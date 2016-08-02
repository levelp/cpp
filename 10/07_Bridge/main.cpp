#include <iostream>

using namespace std;

// Абстрактный класс (интерфейс)
class Implementor {
 public:
  virtual void operationImpl() = 0;
};

class Bridge {
 public:
  // Исполнитель по-умолчанию
  Implementor* defaultImpl;
  // Предпочитаемый исполнитель
  Implementor* desiredImpl;

  Bridge() {
    defaultImpl = NULL;
    desiredImpl = NULL;
  }

  void operation() {
    if(desiredImpl != NULL) {
      desiredImpl->operationImpl();
      return;
    }

    if(defaultImpl != NULL)
      defaultImpl->operationImpl();
  }
};

class A : public Implementor {
  void operationImpl() {
    cout << "A: operationImpl!!" << endl;
  }
};

class B : public Implementor {
  void operationImpl() {
    cout << "B: operationImpl" << endl;
  }
};


int main() {
  Bridge bridge;
  bridge.operation();

  bridge.defaultImpl = new B();

  bridge.operation();

  bridge.desiredImpl = new A();
  bridge.operation();
  bridge.desiredImpl = NULL;

  bridge.operation();


  return 0;
}
