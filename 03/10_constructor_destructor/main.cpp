// Конструкторы и деструкторы
// --------------------------
#include <iostream>

using namespace std;

//-->
// struct - С
// class - С++

// Класс = Данные + Методы работы с ними
//        Переменные + Функции
// Ключевое слово class
// Имя_класса
class MyClass {
  // Количество объектов
  static int count;
  int id; // Идентификатор конкретного (данного) объекта
  int* data; // Дополнительные данные объекта
  char* name; // Имя объекта
 public:
  // Конструктор ИмяКласса()
  // Конструктор не возвращает значения
  // Метод, который вызывается после отведения памяти
  // под объект и предназначен для инициализации
  // полей объекта/открытия внешних ресурсов и пр.
  MyClass(char*);
  // Деструктор: ~ИмяКласса()
  ~MyClass();
};

// Инициализация static-переменной
int MyClass::count = 0;

// Список инициализации
// (..) : имя_поля(значение), имя_поля_2(значение) {
MyClass::MyClass(char* n = "") : name(n) {
  // Увеличиваем количество экземпляров и записываем id
  id = ++count;
  cout << "Constructor #" << id << " " << name << endl;
  // Данные в динамической памяти
  data = new int[1000];
  data[0] = 10;
}

MyClass::~MyClass() {
  cout << "Destructor #" << id << " " << name << endl;
  //cout << data << " " << data[0] << endl;
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
  // Создаём объекты в стеке
  // Метафора: стопка книг
  {
    MyClass a("a"), b("b");
  } // Деструкторы для a и для b
  // Объекты в динамической памяти
  MyClass* aa = new MyClass("aa"),
  *bb = new MyClass("bb");

  delete aa;
  delete bb;

  /*A aa(10);
  A bb(aa);
  cout << bb.w << endl; */

  /*MyClass* p = new MyClass; // Конструктор
  delete p; // Деструктор
  */
  cout << "MyClass d[2] >>>" << endl;
  {
    MyClass d[2];
  } // деструкторы для d
  cout << "<<<" << endl;
  cout << "MyClass e[2] >>>" << endl;
  {
    MyClass e[2];
  } // деструкторы для e
  cout << "<<<" << endl;
  /* MyClass f = a; */
  return 0;
}
