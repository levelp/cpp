#include <QCoreApplication>
#include <iostream>

using namespace std;

struct A {
  A() {
    cout << "Constructor A" << endl;
  }
  ~A() {
    cout << "Destructor A" << endl;
  }
  int value;
};

// Умный указатель
// Класс, который по функциональности
// как указатель +
// он сам следит за количеством ссылок
// временем жизни и т.д. для объекта
template <class T>
struct SmartPtr {
  SmartPtr(T* p) : ptr(p) {}
  ~SmartPtr() {
    delete ptr;
  }
  T& operator*() {
    return *ptr;
  }
  T* operator->() {
    return ptr;
  }
 private:
  T* ptr;
};

int main(int argc, char* argv[]) {
  // Создаём a - указатель на экземпляр A
  A* a = new A;
  // SmartPtr<A> sp = new A;
  // SmartPtr<A> sp(new A);
  // Создаём sp - умный указатель
  // и передаём ему p для управления
  SmartPtr<A> sp(a);
  sp->value = 10;
  return 0;
}

