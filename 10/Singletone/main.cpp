#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "singletone.h"

using namespace std;

// Singletone
class A : public Singletone<A> {
  // Дружественный класс
  friend class Singletone<A>;

  int id;

  // Конструктор
  A() {
    id = rand() % 10000;
    cout << "Constructor A #" << id << endl;
  }

 public:

  // Деструктор
  ~A() {
    cout << "Destructor A #" << id << endl;
  }
  void show() {
    cout << "id = " << id << endl;
  }
};

// Простейшая реализация Singletone - сделать
// все методы и поля статическими
class SimplestSigletone {
 private:
  SimplestSigletone() { } // Не нужна реализация
 public:
  static int id;
  static int calc(int a);
};


int main() {
  srand (time(NULL));
  //A a1; // Не компилируется
  // A *a2 = new A(); // Тоже не компилируется
  A a = A::instance();
  A aa = A::instance();
  a.show();
  aa.show();
  return 0;
}
