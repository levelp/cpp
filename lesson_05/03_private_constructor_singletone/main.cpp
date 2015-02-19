// Для чего использовать private-конструкторы?
// -------------------------------------------
// Шаблон проектирования Singletone
#include <iostream>

using namespace std;

//-->
// Создаем класс S
// Задача: сделать чтобы в программе
// был только один экземпляр этого класса
// Singletone / Одиночка
class S {
  //private: // по-умолчанию и так private
  static int count;
  int id;
  // private (частный) конструктор
  S() {
    count++;
    id = count;
    cout << "Constructor #" << id << endl;
  }
  // Один-единственный экземпляр класса S
  static S* instance;
 public:
  // Единственный способ получить экземпляр
  // класса S - вызвать этот метод
  static S& getInstance() {
    if(instance == NULL)
      instance = new S;

    return *instance;
  }
  void show() {
    cout << "S #" << id << endl;
  }
  ~S() {
    cout << "Destructor: #" << id << endl;
  }
};

int S::count = 0;
S* S::instance = NULL;

int main() {
  // error:'S::S()' is private
  //S s1;
  // error:'S::S()' is private
  //S *s = new S;
  S a = S::getInstance(), b = S::getInstance();
  a.show();
  b.show();
  S c = S::getInstance();
  c.show();
  return 0;
}
//<--
