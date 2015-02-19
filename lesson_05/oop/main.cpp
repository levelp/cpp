#include <iostream>

using namespace std;

class MyFirstClass { // MyFirstClass - имя класса
 private:
  int privateVar;
 public:
  int i; // Поле i целого типа
  MyFirstClass() { // Конструктор
    i = 2; // Присваиваем значение
    //commonVar = 4;
    count++;
    cout << "Object #" << count << endl;
  }
  static int commonVar;
  static int count;
};

int MyFirstClass::commonVar = 3;
int MyFirstClass::count = 0;

int main() {
  // Объявляю 2 экземпляра (объекта) класса
  MyFirstClass a;
  MyFirstClass b;
  //a.privateVar = 2;
  // Переменная i у каждого объекта своя
  b.i = 3;
  // commonVar - общая для всех объектов этого класса
  a.commonVar = 10;
  cout << "a.commonVar = " << a.commonVar << endl;
  b.commonVar = 13;
  cout << "a.i = " << a.i << endl;
  cout << "b.i = " << b.i << endl;
  cout << "a.commonVar = " << a.commonVar << endl;
  cout << "b.commonVar = " << b.commonVar << endl;

  return 0;
}
