// Singletone - одиночка
// ---------------------
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

// Не можем в статической области памяти
//A a1, a2; // Не компилируется

int main() {
  // Инициализация генератора случайных чисел
  srand (time(NULL));
  //A a1, a2; // Не компилируется
  //A *a2 = new A(); // Тоже не компилируется
  A a1 = A::instance();
  A a2 = A::instance();
  a1.show();
  a2.show();
  return 0;
}
