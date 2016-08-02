#include <iostream>

using namespace std;

#define SHOW(x) { cout << #x << " = " << x << endl; }

class MyClass {
  const char* objectName = NULL;
  int* data = NULL;
 public:
  int publicField;
  //  Создание объекта
  //   1. Отводится память sizeof(размер_объекта)
  //   2. Присваиваются значения полям
  //   3. Список инициализации из вызванного
  //     конструктора
  //   4. Выполняется код конструктора
  MyClass(const char* name) : objectName(name) {
    cout << "Constructor: " << objectName << endl;
    data = new int[1000];
  }
  void clear() {
  }
  // Уничтожение объекта
  //  1. Выполняется код деструктора
  //  2. Очищается память занятая объектом
  ~MyClass() {
    clear();
    cout << "Destructor: " << objectName << endl;
    delete[] data;
  }
};

int main() {
  SHOW(sizeof(MyClass));
  MyClass a("a"), b("b");
  {
    MyClass c1("c1");
    cout << "Code block 1" << endl;
    c1.~MyClass();
    c1.publicField = 10;
    SHOW(c1.publicField);

    cout << "Before constructor" << endl;
    MyClass* dyn = new MyClass("dyn");
    cout << "After constructor" << endl;
    cout << "Before destructor" << endl;
    delete dyn;
    cout << "After destructor" << endl;
  }
  {
    MyClass c2("c2");
    cout << "Code block 2" << endl;
  }
  return 0;
}
