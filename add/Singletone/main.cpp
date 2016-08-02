#include <iostream>

using namespace std;

#define S(x) cout << __FUNCTION__ << ": " << #x << " = " << x << endl;

// Шаблон "Одиночка"
template <class T>
class Singletone {
  static int count; // Количество
  // Конструктор в protected чтобы его было
  // снаружи не вызывать
 protected:
  Singletone() : id(++count) {
    cout << "Constructor #" << id << endl;
  };
  Singletone(const Singletone& rhs) {
    cout << "Copy constructor" << endl;
  };
  Singletone& operator=(const Singletone& rhs) {};
 public:
  int id;
  // Получение экземпляра класса
  static T& getInstance() {
    // Указатель на единственный экземпляр
    static T instance;
    return instance;
  }
};

template<class T>
int Singletone<T>::count = 0;

class MyClass : public Singletone<MyClass> {
 public:
  int common;
};

int main() {
  MyClass& my = MyClass::getInstance();
  my.common = 10;
  S(my.common);
  MyClass& my2 = MyClass::getInstance();
  S(my2.common);
  return 0;
}
