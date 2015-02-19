// Воскрешение уничтоженного объекта
// ---------------------------------
#include <iostream>

using namespace std;

class A;

A* undead = NULL;

// +1, +2, +3, +4...
// -1, -2, -3, -4...
class A {
  static int count; // Количество созданных
  // объектов за всё время работы
  // программы
  static int alive; // Сейчас живых
  // объектов
 public:
  int id; // Идентификатор экзепляра
  // Конструктор
  // 1. Под объект резервируется память
  // 2. Выполняется список инициализации
  //    + конструктор предка
  // 3. Выполняется конструктор
  A() : id(++count) {
    //count++; // Добавляется новый объект
    //id = count;
    alive++;
    cout << "+" << id << " -> " << alive << endl;
  }
  // ~1 = 0
  // Деструктор
  // 1. Выполняется деструктор
  // 2. Вызываются деструктор предка
  // 3. Очищается память
  ~A() {
    alive--;
    cout << "-" << id << " -> " << alive << endl;
    undead = this;
  }
};

int A::count = 0;
int A::alive = 0;

int main() {
  A a;
  {
    A b;
    cout << b.id << endl;
  }
  {
    A h;
  }
  int ii[100];

  for(int i = 0; i < 100; ++i)
    ii[i] = i;

  cout << "undead->id = " << undead->id << endl;
  return 0;
}
