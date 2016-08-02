<!-- doc.py -->
Private-конструктор
-------------------
Шаблон Singletone - "Одиночка"
``` cpp
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
```

[00_main.cpp](00_main.cpp)

Для чего использовать private-конструкторы?
-------------------------------------------
Создаем класс S
Задача: сделать чтобы в программе
мог быть только один экземпляр этого класса
Singletone / Одиночка
``` cpp
class S {
  //private: // по-умолчанию и так private
  static int count;
  int id;
  // Один-единственный экземпляр класса S
  static S* instance;
  // private (частный) конструктор
  S() {
    id = ++count;
    cout << "Constructor #" << id << endl;
  }
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
  //S s1, s2;
  // error:'S::S()' is private
  //S *s1 = new S, *s2 = new S;
  S a = S::getInstance(), b = S::getInstance();
  a.show();
  b.show();
  S c = S::getInstance();
  c.show();
  return 0;
}
```

[main.cpp](main.cpp)

