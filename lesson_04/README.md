<!-- doc.py -->
﻿Template. Шаблонные функции. Стратегии
======================================

Обобщённое программирование
---------------------------

Описание шаблона. Шаблонные функции (min, max и т.д.). Шаблонные классы
-----------------------------------------------------------------------

Контейнеры
----------

Стандартная библиотека шаблонов STL: контейнеры, итераторы, алгоритмы, адаптеры, функторы (vector, algorithm)
-------------------------------------------------------------------------------------------------------------


Домашнее задание: Реализовать стек и очередь
--------------------------------------------
Разбор домашнего задания
Полезные макросы для отладки
``` cpp
#define D(x) cout << #x << endl; x;
#define SHOW(x) cout << #x << " = " << x << endl;
```

Элемент стека и очереди
``` cpp
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};

// Стек
struct Stack {
  E* top = NULL; // Вершина стека
};

// Значение поместить на вершину стека
void push(Stack& s, int value) {
  // newElement - переменная в стеке
  //  - указатель на новый элемент стека
  E* newElement = new E;

  // Записываем значение,
  // которое надо поместить
  // на вершину стека
  (*newElement).value = value;
  // второй вариант:
  newElement->value = value;

  // Новый элемент на вершине стека
  // поэтому все остальные следуют за ним
  newElement->next = s.top;

  // Ставим новый элемент в начало списка
  s.top = newElement;
}
// Взять значение с вершины стека
int pop(Stack& s) {
  // Стек не пуст
  assert(s.top != NULL);

  // Запоминаем результат
  // - значение элемента-"вершины" стека
  // 1-A
  int result = s.top->value;

  // Запоминаем ссылку на удаляемый
  // элемент
  // 1-B
  E* toDelete = s.top;

  // 2. Перемещаем вершину на следующий
  s.top = s.top->next;

  // 3. Реально удаляем элемент
  delete toDelete;

  // 4. Возвращаем результат
  return result;
}

struct Queue {
  E* head = NULL; // "Голова" - начало очереди
  E* tail = NULL; // "Хвост" - конец очереди
};

// В конец очереди
void put(Queue& q, int value) {
  // Создаём новый элемент
  E* e = new E;
  e->value = value;
  e->next = NULL;

  // Если очередь пуста
  if(q.head == NULL) {
    q.head = e;
    q.tail = e;
  } else {
    // Если в очереди уже есть элементы
    // "Присоединяем" элемент к последнему
    // элементу в очереди
    q.tail->next = e;
  }
}
// Забрать первый элемент из очереди
int get(Queue& q) {
  // Запоминаем первый элемент
  E* firstElement = q.head;
  // Значение, которое мы в конце вернём
  int value = firstElement->value;
  // Передвигаем указатель на начало
  // очереди на следующий элемент
  q.head = q.head->next;

  // Если очередь пуста, то
  // хвост очереди не указывает ни на
  // какой элемент
  if(q.head == NULL)
    q.tail = NULL;

  // Удаляем первый элемент из
  // динамической памяти
  delete firstElement;

  // Возвращаем его значение
  return value;
}
```

[00_HomeWork_Done/main.cpp](00_HomeWork_Done/main.cpp)

Домашнее задание: Реализовать стек и очередь
--------------------------------------------
Разбор домашнего задания
``` cpp
// Элемент стека и очереди
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};

// Стек
struct Stack {
  E* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) {}
  // Значение поместить на вершину стека
  void push(int value) {
    E* newElement = new E;
    // Записываем значение,
    // которое надо поместить
    // на вершину стека
    newElement->value = value;
    // Новый элемент на вершине стека
    // поэтому все остальные следуют за ним
    newElement->next = top;

    // Ставим новый элемент в начало списка
    top = newElement;
  }
  // Взять значение с вершины стека
  int pop() {
    int result = top->value; // 1. Сохраняем результат - значение элемента-"вершины" стека
    E* e = top; // 2. Запоминаем ссылку на удаляемый элемент
    top = top->next; // 3. Перемещаем вершину стека на следующий элемент
    delete e; // 4. Реально удаляем элемент
    return result; // 5. Возвращаем результат
  }
};

struct Queue {
  E* head; // "Голова" - начало очереди
  E* tail; // "Хвост" - конец очереди
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};
  // В конец очереди
  void put(int value) {
    // Создаём новый элемент
    E* e = new E;
    e->value = value;
    e->next = NULL;

    // Если очередь пуста
    if(head == NULL) {
      head = e;
      tail = e;
    } else {
      // Если в очереди уже есть элементы
      // "Присоединяем" элемент к последнему
      // элементу в очереди
      tail->next = e;
    }
  }
  // Забрать первый элемент из очереди
  int get() {
    // Запоминаем первый элемент
    E* firstElement = head;
    // Значение, которое мы в конце вернём
    int value = firstElement->value;
    // Передвигаем указатель на начало
    // очереди на следующий элемент
    head = head->next;

    // Если очередь пуста, то
    // хвост очереди не указывает ни на
    // какой элемент
    if(head == NULL)
      tail = NULL;

    // Удаляем первый элемент из
    // динамической памяти
    delete firstElement;

    // Возвращаем его значение
    return value;
  }
};
```

``` cpp
  D(Stack s);
  D(s.push(2));
  D(s.push(3));
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  D(Stack s2);
  D(s2.push(10));
  D(s.push(11));
  cout << "11 - " << s.pop() << endl;
  cout << "10 - " << s2.pop() << endl;

  D(Queue q);
  D(q.put(10));
  D(q.put(14));
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;
```

[00_HomeWork_Done_OOP/main.cpp](00_HomeWork_Done_OOP/main.cpp)

Домашнее задание: Реализовать стек и очередь - разбор
-----------------------------------------------------
* FIFO - очередь - First Input First Output
* LIFO - стек - Last Input First Output

Средства отладки:
* Отладчик (пошаговое выполнение,
точки останова, просмотр переменных и т.д.)
* Модульные тесты (проверять утверждения)
* Писать лог/протокол работы
* Ручное тестирование
Элемент стека и очереди
Стек
Конструктор
Значение поместить на вершину стека
Взять значение с вершины стека
Конструктор
Функция, которая вернет
последний элемент,
не работает...
Контракт: очередь не пуста
Элемент у которого
ссылка на следующий отсутствует
Очередь пуста?
Положить значение
в конец очереди
Забрать первый элемент из очереди
Конфигурирование
``` cpp
namespace config {
// Выводить ли сообщения на консоль
bool console = false;
}
```

argc - количество аргументов командной
строки
argv - аргументы командной строки
Выводим все аргументы командной строки
Перенаправляем вывод в файл
assert(s.pop()==3);
[00_HomeWork_Taison4eg/main.cpp](00_HomeWork_Taison4eg/main.cpp)

Приготовление ужина
-------------------
Дано: набор продуктов
их можно смешивать, подогревать
Нужно: хранить набор продуктов,
+ добавлять новый продукт
Компонент еды - конкретный продукт
Список продуктов
Корневой элемент списка
Список пуст?
Добавляем элемент в начало списка
Добавляем элемент в начало
как в стек
Количество данного компонента
Нашли нужный компонент
Если не нашли такого продукта?
Минимум из всех компонент
Сколько у нас данного продукта есть?
Сколько мы можем приготовить
учитывая только этот компонент
Пустой список продуктов
Единица измерения
Новый список - список, что нужно для
приготовления блинов
[01_OOP_Food/main.cpp](01_OOP_Food/main.cpp)

``` cpp
class Stack {
  const static int STACK_SIZE = 100;
  int data[STACK_SIZE];
  // Текущий размер стека
  int count = 0;
 public:
  // Положить данные на вершину стека
  void push(int value) {
    if(count == STACK_SIZE) {
      cout << "Stack is full!" << endl;
      return;
    }

    data[count++] = value;
  }
  // Забрать данные с вершины стека
  int pop() {
    if(count == 0) {
      cout << "Stack is empty!" << endl;
      return -1;
    }

    return data[--count];
  }
};
```

[01_StackDemo/main.cpp](01_StackDemo/main.cpp)

Конструктор - вызывается после создания объекта в памяти
Деструктор - вызывается перед удалением объекта из памяти
Конструктор копирования
[02_vectors/main.cpp](02_vectors/main.cpp)

Конструкторы и деструкторы
--------------------------
``` cpp
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
```

[13_constructor_destructor/main.cpp](13_constructor_destructor/main.cpp)

Конструктор копирования
-----------------------
``` cpp
// Класс "строка"
class string {
  static int count; // Количество строк
  char*    Str;
  int     size;
 public:
  int id; // Идентификатор данной строки
  string(string&); // Конструктор копирования
  // Конструктор
  string(const char* str) {
    id = ++count;
    std::cout << "Constructor #" << id << " \"" << str << "\"" << std::endl;
    size = strlen(str); // "ABC\0"
    Str = new char[size + 1];
    strcpy(Str, str);
  };
  // Вывод строки на экран
  void show() {
    std::cout << Str << std::endl;
  }
  // Деструктор
  ~string() {
    std::cout << "Destructor #" << id << std::endl;
    delete[] Str; // Очищаем динамическую память
  }
  // Перегрузка операции присваивания
  string& operator=(string& right) {
    if(Str != NULL)
      delete[] Str;

    std::cout << "= #" << id << std::endl;
    // if(Str != NULL)
    //   delete[] Str;
    Str = new char[right.size + 1];
    size = right.size;
    strcpy(Str, right.Str);
  }
};

// Конструктор копирования
// Создает копии динамических переменных и ресурсов
string::string(string& x) {
  id = ++count;
  std::cout << "Copy constructor #" << id << std::endl;
  // if(Str != NULL)
  //   delete[] Str;
  Str = new char[x.size + 1];
  size = x.size;
  strcpy(Str, x.Str);
}

int string::count = 0;
```

[14_copy_contructor/main.cpp](14_copy_contructor/main.cpp)

Один элемент списка
``` cpp
struct ListElement {
  int value; // Значение элемента списка
  ListElement* next; // Указатель на
  // следующий элемент списка
};
```

Список целиком, со всеми операциями
``` cpp
struct List {
  // Указатель на первый элемент списка
  // ListElement *root = NULL;
  ListElement* root;
  // Конструктор - метод, который вызывается
  // при создании объекта (экземпляра класса)
  List() { /*: root(NULL)*/
    root = NULL; // Указатель на первый элемент
    // NULL - означает что нет ни одного элемента в списке
  }
  // Деструктор (очистка памяти)
  ~List() {
    while(root != NULL) { // Пока список не пуст
      // Запоминаем 2-ой элемент списка
      // (следующий после первого элемента)
      ListElement* second = root->next;
      // Удаляем первый элемент списка
      delete root;
      // delete:
      //  1. Вызывается деструктор (если есть)
      //  2. Освобождается динамическая память
      root = second;
    }
  }
  // Показать список
  void show() {
    for(ListElement* cur = root;
        cur != NULL;
        cur = cur->next) {
      // cur->value <-> (*cur).value
      cout << cur->value << endl;
    }
  }
  // Добавить элемент в начало
  void addToBegin(int value) {
    // Заводим новый элемент в динамической памяти
    ListElement* e = new ListElement;
    // Заполняем новый элемент
    e->value = value;
    // Подвешиваем к новому элементу старый список
    e->next = root;
    // Теперь root должен ссылаться на новый элемент
    root = e;
  }
  // Добавить элемент в конец
  void addToEnd(int value) {
    // Если список пуст, то добавить в конец
    // это то же что и добавить в начало
    if(root == NULL) {
      addToBegin(value);
      return;
    }

    // Ищем последний элемент
    ListElement* cur = root;

    while(cur->next != NULL)
      cur = cur->next;

    // Убеждаемся в том, что это последний элемент
    // списка
    assert(cur->next == NULL);

    // Заводим новый элемент
    ListElement* newElement = new ListElement;
    newElement->value = value;
    newElement->next = NULL;

    // Подвешиваем новый элемент в конец списка
    cur->next = newElement;
  }
};
```

[15_ListExample/main.cpp](15_ListExample/main.cpp)

﻿Наследование и уровни доступа
-----------------------------


Наследование и уровни доступа
-----------------------------
**Наследование** - способность производного класса
наследовать характеристики существующего базового класса
Базовый класс A
``` cpp
class A {
 public: // Доступно всем
  int a;  // A test;  test.a = 10;
 protected: // Доступно внутри класса и наследникам
  int forChilds; // из методов этого и наследников
 private:  // Доступно только внутри методов
  int privateA; // этого класса
};
```

B - наследник класса A
``` cpp
class B : public A { // Все поля и методы
 public: // кроме private доступны
  int a;
  int b;
  void method1() {
    a = 1;
    b = 2;
    forChilds = 10;
    A::a = 10;
    B::a = 11;
    // privateA = 1; // Невозможно
    // this->privateA;
  }
};

class C : public B {
 public:
  int c;
  int a;
  // if(dynamic_cast<A>(this) != NULL)
};
```

Извне можно обратиться только
к public-полям и методам
b1.forChilds = 5;
```

[16_inherit/main.cpp](16_inherit/main.cpp)

Наследование: поле с тем же имененем
------------------------------------
Пусть есть класс **A**
с полем **x** и методом **show**
``` cpp
class A {
 public:
  int x = -1;
  void show() {
    cout << "x = " << x << endl;
  }
};
```

И его наследник **B**
тоже с полем **x** и методом **show**
``` cpp
class B : public A {
 public:
  int x = -2;
  void show() {
    A::x++;
    cout << "A::x = " << A::x << endl;
    cout << "B::x = " << B::x << endl;
  }
};
```

Как получить доступ к каждому из полей **x**?
``` cpp
int main() {
  A a;
  B b;
  a.x = 1;
  a.show();
  b.x = 2;
  b.show();
  return 0;
}
```

[16_inherit_sameName/main.cpp](16_inherit_sameName/main.cpp)

Наследование
------------
struct A <--> class A { public:
class A <--> struct A { private:
``` cpp
struct A {
  static int staticInClass;
  int a; // Поле доступно отовсюду

  void doA() {
    cout << "doA()" << endl;
    onlyInA = 2;
    cout << "onlyInA = " << onlyInA << endl;
    forChilds = 10;
  };
 private:
  int onlyInA; // Только внутри класса A
 protected:
  int forChilds; // Внутри класса A и в наследниках
};
```

B - наследник A
``` cpp
struct B : public A {
  int b;
  int forChilds; // Поле с тем же именем
  void doB() {
    cout << "doB()" << endl;
    //onlyInA = 2; // Недоступно в наследниках
    doA();
    //cout << "onlyInA = " << onlyInA << endl;
    A::forChilds = 12;
    forChilds = 20; // Работает
    this->forChilds = 20; // Работает

    cout << "A::forChilds = " << A::forChilds << endl;
    cout << "B::forChilds = " << B::forChilds << endl;
  };
};
```


Множественное наследование
show(); // Ошибка компиляции
Мы должны явно указать из какого предка вызываем метод
потому что это глобальная переменная
a.onlyInA = 3; // 'int A::onlyInA' is private
'int A::forChilds' is protected
cout << a.forChilds << endl;
Нет доступа, т.к. onlyInA private
b.onlyInA = 10;
c.a = 1; // Ошибка из-за protected наследования
c.b = 2; // Ошибка из-за protected наследования
c.doA();
c.doB();
x.doL();
[17_inherit/main.cpp](17_inherit/main.cpp)

``` cpp
// Фигура
struct Shape {
  //virtual void show(){
  //  cout << "Shape" << endl;
  //};
  virtual void show() = 0; // Абстрактный метод
 protected:
  // virtual void doA() = 0;
  // virtual void doB() = 0;
  // virtual void doC() = 0;
  // virtual void doD() = 0;
  // virtual void doE() = 0;
  //int x;
 private:
  char c1;
  char c2;
  char c3;
  char c4;
  char c5;
} __attribute__((packed));
```

Квадрат
``` cpp
struct Square : public Shape {
  double side;
  Square(double s) : side(s) { }
  void show() {
    cout << "Square side = " << side << endl;
  }
};
```

Прямоугольник
``` cpp
struct Rectangle : public Shape {
  double height, width;
  Rectangle(double h, double w) :
    height(h), width(w) { }
  void show() {
    cout << "Rectangle " << height <<
         " x " << width << endl;
  }
};
```

``` cpp
int main() {
  // Shape shape; // Ошибка компиляции
  cout << sizeof(Shape) << endl;
  Shape* s[] = {
    new Square(10),
    new Rectangle(2, 3),
    new Square(15),
    // new Shape(),
  };

  for(int i = 0; i < 3; ++i)
    s[i]->show();

  return 0;
}
```

[18_polymorph/main.cpp](18_polymorph/main.cpp)

``` cpp
struct A {
 private:
  int a;

 public:
  A() {
    a = 33;
  }

  // setter - метод для установки значения поля
  void setA(int value) {
    cout << "a = " << value << endl;
    a = value;
  }
  // getter - метод для получения значения поля
  int getA() {
    return a;
  }
};


int main() {
  A a1; // A - класс, a1 - объект
  a1.setA(20);
  cout << a1.getA() << endl;
  return 0;
}
```

[19_setter_getter/main.cpp](19_setter_getter/main.cpp)

Зачем нужны get/set методы?
---------------------------
Don’t Repeat Yourself
http://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself
Дублирование данных
``` cpp
class Square2 {
  double side; // Сторона
  double area; // Площадь
 public:
  // Просто возвращаем значение
  double getSide() {
    return side;
  }
  double getArea() {
    return area;
  }
  // При изменении меняем одновременно
  void setSide(double value) {
    side = value;
    area = value * value;
  }
  void setArea(double value) {
    side = sqrt(value);
    area = value;
  }
};
```

[20_getter_setter_square/main.cpp](20_getter_setter_square/main.cpp)

Реализация метода в отдельном C++ файле
``` cpp
void Square::setArea(double value) {
#ifdef SIDE
  side = sqrt(value);
#else
  area = value;
#endif
}
```

[20_getter_setter_square/square.cpp](20_getter_setter_square/square.cpp)

Инкапсуляция
------------
Объект должен быть "скромным"
Класс "Квадрат"
``` cpp
class Square {
  //private: // Инкапсуляция
#ifdef SIDE
  double side; // Сторона
#else
  double area; // Площадь - сторона в квадрате
#endif // SIDE
 public:
  // Получить сторону квадрата
  double getSide() {
#ifdef SIDE
    return side;
#else
    return sqrt(area);
#endif // SIDE
  }
  // Задать сторону квадрата
  void setSide(double value) {
#ifdef SIDE
    side = value;
#else
    area = value * value;
#endif // SIDE
  }
  // Получить площадь
  double getArea() {
#ifdef SIDE
    return side * side;
#else
    return area;
#endif // SIDE
  }
  // Задать площадь
  void setArea(double value);
};
```

[20_getter_setter_square/square.h](20_getter_setter_square/square.h)

Работа с this
-------------
``` cpp
class Boy;

class Girl {
 public:
  Boy* boy;
  void reg(Boy* b) {
    boy = b;
  }
  void answer();
};

class Boy {
 public:
  Girl* girl;
  //Girl* g;
  void reg(Girl* g) {
    // this->g = g;
    girl = g;
    girl->reg(this);
  }
  void dialog() {
    cout << "Boy: hi!" << endl;
    girl->answer();
  }
  void answer() {
    cout << "Boy: I'm find! And how are you?" << endl;
  }
};

void Girl::answer() {
  cout << "Girl: Hi! How are you?" << endl;
  boy->answer();
}


int main() {
  Girl g;
  Boy b;
  b.reg(&g);

  b.dialog();

  return 0;
}
```

[22_this_demo/main.cpp](22_this_demo/main.cpp)

Diamond Inheritance
-------------------
``` cpp
//   A
//  / \
// B   C
//  \ /
//   D
#include <iostream>

using namespace std;

struct X {
  void show() {
    cout << "X" << endl;
  };
};

struct A {
  char name;
  A() : name('A') {};
  virtual
  void show() {
    cout << "show_A " << name << endl;
  };
};

struct B : virtual public A {
  B() {
    A::name = 'B';
  };
  void show() {
    cout << "show_B " << name << endl;
  };
};

struct C : virtual public A {
  C() {
    A::name = 'C';
  };
  void show() {
    cout << "show_C " << name << endl;
  };
};

struct D : public B, public C {
  D() {
    B::name = 'D';
  };
  void show() {
    cout << "show_D " << B::name << endl;
    /*B::show();
    C::show();
    C::A::show();
    B::A::show(); */
  };
};

int main() {
  /*A a;
  a.show();

  'B b;
  b.show();
  C c;
  c.show(); */

  //D d;
  //d.show();
  /*A* x[4] = {new A, new B, new C, new D};
  for(int i = 0; i < 4; ++i)
    x[i]->show();
  */
  // Полиморфизм
  B* b = new D;
  C* c = new D;
  b->show();
  c->show();

  return 0;

  A* x[4] = { new B, new A, new C, new D };
  /* A* x[4];
   x[0] = new C;
   x[1] = new B;
   x[2] = new A;
   x[3] = new D; */

  cout << "sizeof(X) = " << sizeof(X) << endl;
  cout << "sizeof(*X) = " << sizeof(X*) << endl;

  cout << "+ VMT" << endl;
  cout << "sizeof(A) = " << sizeof(A) << endl;
  cout << "sizeof(*A) = " << sizeof(A*) << endl;

  for(int i = 0; i < 4; ++i)
    x[i]->show();

  for(int i = 0; i < 4; ++i)
    delete x[i];

  return 0;
}
```

[23_diamond_inherit/main.cpp](23_diamond_inherit/main.cpp)

Итерируемся по set
for(vector<int>)
[25_iterator/main.cpp](25_iterator/main.cpp)

C++
Вывод в консоль по-русски:
``` cpp
  //system("chcp 65001");
  SetConsoleOutputCP(CP_UTF8);
  //std::locale::global(std::locale ("en_US.UTF-8"));
  printf("Это моя первая программа!\n");
  //cout << "Текст в UTF-8" << endl;
  //cout << "И он нормально читается в Windows-консоли!" << endl;
```

[28_Russian/hw_utf8.cpp](28_Russian/hw_utf8.cpp)

C++
Вывод в консоль по-русски:
``` cpp
  //setlocale(LC_ALL, "Russian_Russia.UTF-8");
  //setlocale(LC_ALL, "Russian.UTF-8");
  //SetConsoleCP(CP_UTF8);
  //SetConsoleOutputCP(CP_UTF8);
```

[28_Russian/hw_utf8_2.cpp](28_Russian/hw_utf8_2.cpp)

Получаем параметры текущей локали
``` cpp
#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  char language[256] = {0}, country[256] = {0};
  GetLocaleInfo(
    GetUserDefaultLCID(),
    LOCALE_SENGLANGUAGE,
    language, sizeof(language));
  GetLocaleInfo(
    GetUserDefaultLCID(),
    LOCALE_SENGCOUNTRY,
    country, sizeof(country));

  UINT OEM_CP = GetOEMCP(); // Возвращает системную OEM кодовую страницу как число
  // UINT ANSI_CP = GetANSICP();

  printf("%s_%s %d\n", language, country, OEM_CP);

  cout << language << "_" << country << "." << OEM_CP << endl;
}
```

[28_Russian/show_cur_locale.cpp](28_Russian/show_cur_locale.cpp)

Открываем текстовый файл для чтения
``` cpp
  freopen("in.txt", "r", stdin);
```

Открываем текстовый файл для записи
``` cpp
  freopen("out.txt", "w", stdout);
```

TODO: доделайте сами :)
[98_dict_textfile/main.cpp](98_dict_textfile/main.cpp)

﻿Коды ошибок
-----------

* **0xC0000005** - обращение по неправильному указателю.


﻿Домашнее задание: реализовать классы геометрических фигур
---------------------------------------------------------

Базовый класс **Фигура**
``` cpp
struct Shape { // struct -> public:
  virtual void show() = 0; // Абстрактный метод
};
```
Квадрат
``` cpp
struct Square : public Shape {
  double side;
  Square(double s) : side(s) { }
  void show() {
    // TODO: реализовать
  }
};
```

Прямоугольник
``` cpp
struct Rectangle : public Shape {
  double height, width;
  Rectangle(double h, double w) :
    height(h), width(w) { }
  void show() {
    // TODO: реализовать
  }
};
```

Демонстрационная программа показывающая все фигуры:
``` cpp
int main() {
  Shape* s[] = {
    new Square(10),
    new Rectangle(2, 3),
    new Square(15),
  };

  for(int i = 0; i < 3; ++i)
    s[i]->show();

  return 0;
}
```

﻿Домашнее задание: реализовать с использованием STL
--------------------------------------------------

* Самое часто встречающееся число
* Максимум в массиве
* Переводчик текста на основе map


