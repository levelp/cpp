// Конструкторы и деструкторы
// --------------------------
#include <iostream>

using namespace std;

//-->
// struct - С
// class - С++

// Ключевое слово class
// Имя_класса
class MyClass {
  // Количество объектов
  static int count;
  // Идентификатор данного объекта
  int id;
  int* data;
 public:
  // Конструктор
  MyClass();
  // Деструктор
  ~MyClass();
};

// Инициализация static-переменной
int MyClass::count = 0;

MyClass::MyClass() {
  count++;
  id = count;
  cout << "Constructor #" << id << endl;

  data = new int[1000];
  data[0] = 10;
}

MyClass::~MyClass() {
  cout << "Destructor #" << id << endl;

  cout << data << " " << data[0] << endl;
  delete[] data;
}

struct A {
  int w;
  A(int v) {
    w = v;
  }
};
//<--

int main() {
  MyClass a, b;
  /* MyClass *aa = new MyClass,
     *bb = new MyClass;

   delete aa;
   delete bb;
  */
  /*A aa(10);
  A bb(aa);
  cout << bb.w << endl; */

  /*MyClass* p = new MyClass; // Конструктор
  delete p; // Деструктор
  */
  {
    MyClass d[2];
  } // деструкторы для d
  {
    MyClass e[2];
  } // деструкторы для e
  MyClass f = a;
  return 0;
}
