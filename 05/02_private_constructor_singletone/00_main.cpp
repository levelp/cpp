/// Private-конструктор
/// -------------------
#include <iostream>

using namespace std;

/// Шаблон Singletone - "Одиночка"
//-->
class MyClass {
  // private constructor
  MyClass() {
    id = ++count;
  };
  static int count;
  static MyClass* instanse; // private
 public:
  int id; // Индентификатор объекта
  static MyClass* getInstanse() {
    if(instanse == NULL) {
      instanse = new MyClass;    // Вызов конструктора
    }

    return instanse;
  }
};

int MyClass::count = 0;
MyClass* MyClass::instanse = NULL;

int main() {
  MyClass* a = MyClass::getInstanse();
  MyClass* b = MyClass::getInstanse();

  cout << "a->id = " << a->id << endl;
  cout << "b->id = " << b->id << endl;
  return 0;
}
//<--