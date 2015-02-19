#include <iostream>
#include <string>

using namespace std;

// Ключевое слово: static -
//   поле/метод относится к классу целиком
//   а не к конкретному объекту.
class MyClass {
  static int counter; // Количество созданных
  // за всё время работы программы объектов
  // (экземпляров) класса MyClass
  // т.е. оно только увеличивается и не
  // уменьшается при удалении объекта
 public:
  // Идентификатор - уникальный номер
  // данного экземпляра класса
  int id;
  string name;
  // Конструктор - специальный метод
  //   который вызывается сразу после
  //   отведения памяти под объект
  MyClass(string name) : id(++counter),
    name(name) {
    cout << "Constructor #" << id << " "
         << name << endl;
  }
  MyClass() : id(++counter),
    name("default") {
    cout << "Constructor #" << id << " "
         << name << endl;
  }
  // Деструктор - специальный метод
  //  который вызывается прямо перед
  //  удалением объекта из памяти
  ~MyClass() {
    cout << "Destructor #" << id << " "
         << name << endl;
  }
};

// Инициализируем статическое поле класса
int MyClass::counter = 0;

int main() {
  MyClass a("a"), b("b");
  {
    MyClass c("c");
  }
  {
    MyClass d("d");
  }
  MyClass array[4];
  return 0;
}
