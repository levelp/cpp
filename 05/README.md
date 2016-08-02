<!-- doc.py -->
﻿Template. Шаблонные функции. Стратегии
======================================

Обобщённое программирование
---------------------------
*Обобщённое программирование (generic programming)* - парадигма программирования, заключающаяся в таком описании *структур данных* и *алгоритмов*,
которое можно применять к различным типам данных, не меняя само описание.

В C++ ООП реализуется посредством виртуальных функций и наследования, а ОП — с помощью шаблонов классов и функций.

Этапы в решении задачи по методологии ОП:
* Найти полезный и эффективный алгоритм.
* Определить обобщённое представление (параметризовать алгоритм, минимизировав требования к обрабатываемым данным).
* Описать набор (минимальных) требований, удовлетворяя которые всё ещё можно получить эффективные алгоритмы.
* Создать каркас на основе классифицированных требований.

Описание шаблона. Шаблонные функции (min, max и т.д.). Шаблонные классы
-----------------------------------------------------------------------

```cpp
// Описание шаблона функции
template <typename T> T max(T x, T y) {
  if (x < y)
    return y;
  else
    return x;
}
...
// Применение функции, заданной шаблоном
int a = max(10,15);
...
double f = max(123.11, 123.12);
...
```

Контейнеры
----------

Стандартная библиотека шаблонов STL: контейнеры, итераторы, алгоритмы, адаптеры, функторы (vector, algorithm)
-------------------------------------------------------------------------------------------------------------





Домашнее задание: реализовать классы геометрических фигур
---------------------------------------------------------
Базовый класс: Фигура
``` cpp
class Shape {
  // Поля класса:
  // Имя фигуры (строка)
  char* name; // Обязательно private
 protected:
  // Конструктор для вызова из наследников
  Shape(char* name = NULL) : name(name) {
  }
  // Каждая фигура показывает своё имя
 public:
  // Чистая виртуальная функция
  //  => Класс Shape является абстрактным
  //   т.е. нельзя создать экземпляры класса Shape
  //  => Все наследники содержат таблицу
  //   виртуальных функций и должны либо
  //   реализовать этот метод, либо тоже
  //   будут абстрактными.
  virtual void show() = 0;

 protected:
  void showName() {
    if(name != NULL)
      cout << name << " ";
  }
};
```

``` cpp

class Shape2 : public Shape {
 public:
  Shape2(char* name) : Shape(name) {
  }
  void show() {
    cout << "Shape2 ";
    Shape::showName();
  }
};

// Наследники Shape:
class Point : public Shape2 {
  double x, y;
 public:
  // Конструктор
  Point(char* name, double x, double y) :
    x(x), Shape2(name), y(y) {
  }
  // final - нельзя переопределять
  void show() final {
    cout << "Point ";
    Shape::showName();
    cout << "  x = " << x << " y = " << y << endl;
  }
};

class PointX : public Point {
#if 0
  // Не компимлируется
  void show() {
  }
#endif
};

class Line : public Shape {
  // Внутри 2 точки
  Point a, b;
 public:
  // Конструктор
  Line(char* name, Point a, Point b) :
    Shape(name), a(a), b(b) {
  }
  void show() {
    cout << "Line ";
    Shape::showName();
    a.show();
    cout << " - ";
    b.show();
  }
};

class Circle : public Shape {
  // Одна точка и радиус
  Point center;
  double radius;
  // Конструктор
 public:
  Circle(char* name, Point center, double radius) :
    Shape(name), center(center), radius(radius) {
  }
  void show() {
    cout << "Circle ";
    Shape::showName();
    center.show();
    cout << "  radius = " << radius << endl;
  }
};

// Везде метод show() -> показывает свойства фигуры

int main() {
  // error: cannot allocate an object
  // of abstract type 'Shape'
  // Shape* s = new Shape;

  // error: cannot declare variable 's2'
  // to be of abstract type 'Shape'|
  // Shape s2;

  Shape* shapes[5] = {
    new Point("A", 1.2, 2.1),
    new Point("B", 5, 6),
    new Line("AB", Point("A", 1.2, 2.1),
    Point("B", 5, 6)),
    new Circle("CircleA", Point("A", 1.2, 2.1), 5.0),
    new Circle("CircleB", Point("B", 5, 6), 7.2)
  };

  for(int i = 0; i < 5; ++i)
    shapes[i]->show();

  return 0;
}
[00_HomeWork_Done/main.cpp](00_HomeWork_Done/main.cpp)

Указатель на функцию
--------------------
Определение нового типа **MyFunction**
Спецификация функции:
* тип возвращаемого значения - int
* тип первого параметра int
* тип второго параметра void*
``` cpp
typedef int (*MyFunction)(int, void*);
```

Две реализации функции
``` cpp
int f1(int a, void* b) {
  cout << __FUNCTION__ << "(" << a << ", " << b << ")" << endl;
  return 1;
}

int f2(int a, void* b) {
  cout << __FUNCTION__ << "(" << a << ", " << b << ")" << endl;
  return 2;
}
```

Функция, которая на вход получает double
и возвращает тоже double (например: sin/cos)
``` cpp
typedef double (*DoubleFuncPtr)(double);
```

error: invalid conversion from
'int (*)(int, void*)' to
'DoubleFuncPtr {aka double (*)(double)}'
showFuncTable(&f1);
```

[00_pointer_to_function/main.cpp](00_pointer_to_function/main.cpp)

Список инициализации в конструкторе
-----------------------------------
#define TWO_CONSTRUCTORS
[01_ConstructorInitList/main.cpp](01_ConstructorInitList/main.cpp)

Применение модификатора const в ООП
Метод не модифицирует состояние объекта
[01_arrays_const/main.cpp](01_arrays_const/main.cpp)

Создание объекта
1. Отводится память sizeof(размер_объекта)
2. Присваиваются значения полям
3. Список инициализации из вызванного
конструктора
4. Выполняется код конструктора
Уничтожение объекта
1. Выполняется код деструктора
2. Очищается память занятая объектом
[01_contructor_destructor/main.cpp](01_contructor_destructor/main.cpp)

cout
[02_bitfields/main.cpp](02_bitfields/main.cpp)

Конструктор копирования
[02_copy_constructor/main.cpp](02_copy_constructor/main.cpp)

Значение - описание где поле видимо
[02_task_access_level/main.cpp](02_task_access_level/main.cpp)

до первого private наследования
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
protected - наследуем класс A
только для себя и наследников
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
В наследнике C доступны те же поля
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
private - наследуем класс A
только для себя (без наследников)
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
Недоступно ничего из A
A -> private B -> public C
publicA = 1;
privateA = 2; // Недоступен
т.к. private доступны только внутри класса
protectedA = 3;
a.privateA = 10; // Недоступно
a.protectedA = 10; // Недоступно
bPublic.privateA = 10; // Недоступно
bPublic.protectedA = 10; // Недоступно
bProtected.publicA = 111;
C.publicA = 12;
[03_inheritance/main.cpp](03_inheritance/main.cpp)

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

[03_private_constructor_singletone/00_main.cpp](03_private_constructor_singletone/00_main.cpp)

Для чего использовать private-конструкторы?
-------------------------------------------
Шаблон проектирования Singletone
``` cpp
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
```

[03_private_constructor_singletone/main.cpp](03_private_constructor_singletone/main.cpp)

+1, +2, +3, +4...
-1, -2, -3, -4...
объектов за всё время работы
программы
объектов
Конструктор
1. Под объект резервируется память
2. Выполняется список инициализации
+ конструктор предка
3. Выполняется конструктор
count++; // Добавляется новый объект
id = count;
~1 = 0
Деструктор
1. Выполняется деструктор
2. Вызываются деструктор предка
3. Очищается память
[03_task_count_instance/main.cpp](03_task_count_instance/main.cpp)

Добавить элемент в начало списка
Тот элемент, который раньше был первым
теперь должен ссылаться на новый первый элемент
Добавляем элемент в конец списка
Список не пустой
Идея: найти последний элемент списка
Для "старого" последнего элемента
следующий элемент - новый элемент
Для нового элемента: предыдущий -
"старый" последний элемент
Удалить первый элемент списка
Мы удаляем первый элемент, поэтому
предыдущего элемента нет
Удаляем из памяти
Ищем элемент по значению
Нашли элемент с заданным значением!
Если есть следующий
У следующего prev заменяем на на prev
Если есть предыдущий
У предыдущего next заменяем на наш next
Мы удаляем первый элемент, поэтому
root должен указывать на второй
Удалить по индексу
Удалим первый элемент
Снова посмотрим список
Удаляем средний
Удаляем первый элемент
Удаляем единственный элемент
Удаляем последний элемент
[04_DoubleLinkedList/main.cpp](04_DoubleLinkedList/main.cpp)

Воскрешение уничтоженного объекта
---------------------------------
+1, +2, +3, +4...
-1, -2, -3, -4...
объектов за всё время работы
программы
объектов
Конструктор
1. Под объект резервируется память
2. Выполняется список инициализации
+ конструктор предка
3. Выполняется конструктор
count++; // Добавляется новый объект
id = count;
~1 = 0
Деструктор
1. Выполняется деструктор
2. Вызываются деструктор предка
3. Очищается память
[04_object_ref_ressurection/main.cpp](04_object_ref_ressurection/main.cpp)

Перегрузка операторов в C++. Вывод в поток
------------------------------------------
**Оператор в C++** - это некоторое действие или функция
обозначенная специльным символом (символами).
Чтобы распространять действие операторов на новые
(свои) типы данных в C++ их можно перегружать.
Для перегрузки используется ключевое слово **operator** вместе с прототипом и объявлением функции.
Практика: класс "рациональная дробь"
------------------------------------
Сокращение типа
``` cpp
typedef long long ll;
```

НОД - Наибольший общий делитель.
GCD - Greatest common divisor.
``` cpp
long GCD(long a, long b) {
  return (b == 0) ? a : GCD(b, a % b);
}
```

``` cpp
// Рациональная дробь: p/q
class Rational {
  long p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  void normalize() {
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель
  }
 public:
  // TODO: Конструктор
  Rational(long pi, long qi) :
    p(pi), q(qi) {
    assert(q != 0);
    //if(q == 0){
    //  cout << "q == 0" << endl;
    //  halt(1);
    //}
  }
  Rational(const char* message) {
    cout << message << " ";
    cout << "p = ";
    cin >> p;
    cout << "q = ";
    cin >> q;
    normalize();
  }
  // Показать дробь на экран (в консоль)
  void show(ostream& os = cout) const {
    // Сокращаем дробь если надо
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    long px = p / d; // делим на него числитель
    long qx = q / d; // делим на него знаменатель

    if(qx < 0) {
      px = -px;
      qx = -qx;
    }

    // Если знаменатель равен 1
    // то это целое число
    if(qx == 1)   // Условие (1)
      os << px << endl;
    else {
      // Целая часть
      long whole = px / qx;

      if(whole != 0)
        os << whole << " ";
      else if(px < 0)
        os << "-";

      px -= whole * qx;
      px = abs(px);
      assert(px > 0);
      // Если число целое, то должно было сработать
      // первое условие (1)
      assert(px % qx != 0);
      os << px << "/" << qx << endl;
    }
  }

  // Сложение дробей
  void add(Rational& right) {
    //   p    right.p
    //  --- + -------
    //   q    right.q
    p = p * right.q + right.p * q;
    //  --------------------------
    q =       q * right.q;

    // Для предотвращения переполнений
    normalize();
  }

  // a + b
  const Rational operator+(Rational& right) {
    Rational res = *this;
    res.add(right);
    return res;
  }

  Rational operator+(int right) {
    Rational res = *this;
    Rational r(right, 1);
    res.add(r);
    return res;
  }

  friend
  Rational
  operator+(long left, Rational& right) {
    Rational res(left, 1);
    res.add(right);
    return res;
  }

  void sub(Rational& right) {
    p = p * right.q - right.p * q;
    //  --------------------------
    q =       q * right.q;

    normalize();
  }

  Rational operator-(Rational& right) {
    Rational res = *this;
    res.sub(right);
    return res;
  }

  // Конструктор копирования
  /* Rational(const Rational &r){
     //cout << r.p << "/" << r.q << endl;
     p = r.p;
     q = r.q;
     //cout << "Copy contructor " << p << "/" << q << endl;
   } */

  friend ostream& operator <<(ostream& os, const Rational& r) {
    r.show(os);
    return os;
  }
};

#define SHOW(x) { cout << #x << " = " << (x) << endl; }

int main() {
  /* Rational x(3, 1);
   x.show();

   Rational y(6, 4);
   y.show(); */

  Rational aa(2, 6), bb(3, 6);
  SHOW(aa);
  SHOW(bb);
  SHOW(aa - bb);

  Rational a(4, 6), b(11, 2);
  SHOW(a);
  SHOW(b);
  Rational c = a + b;
  SHOW(c);
  SHOW(a + b);
  SHOW(a - b);
  SHOW(a / b);
  SHOW(a * b);
  SHOW(a);
  SHOW(b);

  // Rational c = b + a;

  int i = 2, j = 3;
  int tt = i + j;
  Rational c1 = i + b;

  b.show();
  c1.show();

  Rational x(4, 6), y(1, 3);
  x.add(y);
  x.show();

  Rational yy("Vvedite:");
  yy.show();

  return 0;
}
```

[05_task_rational/main.cpp](05_task_rational/main.cpp)

Ключевое слово: static -
поле/метод относится к классу целиком
а не к конкретному объекту.
за всё время работы программы объектов
(экземпляров) класса MyClass
т.е. оно только увеличивается и не
уменьшается при удалении объекта
Идентификатор - уникальный номер
данного экземпляра класса
Конструктор - специальный метод
который вызывается сразу после
отведения памяти под объект
Деструктор - специальный метод
который вызывается прямо перед
удалением объекта из памяти
Инициализируем статическое поле класса
[06_Class_static/main.cpp](06_Class_static/main.cpp)

struct   = class
(public)   (private)
cout << c.x << " " << c.y << endl;
[06_Vector_operator/main.cpp](06_Vector_operator/main.cpp)

abstract
interface  C# / Java
[06_polymorph/main.cpp](06_polymorph/main.cpp)

Класс A - предок класса B
Класс B - наследник класса A
[07_inherit_simple/main.cpp](07_inherit_simple/main.cpp)

B - наследует поля и методы и из A и из A2
error: reference to 'x' is ambiguous|
x = 2;
Если уникальна
Хоть var из A2 и не видно, всё равно надо
указать класс
[08_inherit_2/main.cpp](08_inherit_2/main.cpp)

..
Квадрат - частный случай прямоугольника
[08_inherit_order/main.cpp](08_inherit_order/main.cpp)

os = cout - типа ostream
Point = P
[09_cout_my_class/main.cpp](09_cout_my_class/main.cpp)

Принцип:
1. private - доступно только внутри данного класса
2. protected - + наследникам
3. public - + всем извне
При наследовании:
A -> B -> C -> D...
Уровень доступа - минимум из всех модификаторов
для данного поля/метода.
``` cpp
class Base {
 private:
  // Только для "частного" использования
  // т.е. внутри класса Base
  int privateVar;
 protected: // Внутри класса Base
  int protectedVar;  // и в наследниках
 public:
  int publicVar;
};

class Public : public Base {
  void f() {
    // privateVar = 122; // Недоступна
    protectedVar = 102;
    publicVar = 3;
  }
};

class Protected : protected Base {
  // Так же, как при public-наследовании
  // только public: => protected:
  // protected - наследую для себя и для потомков
  void f() {
    // privateVar = 122; // Недоступна
    protectedVar = 102;
    publicVar = 3;
  }
};

// Наследуем поля только для себя
class Private : private Base { /*, public A */
  // private класса Base недоступен
  // protected и public становятся private
 public:
  void f() {
    // privateVar = 122; // Недоступна
    protectedVar = 102;
    publicVar = 3;
  }
};

int main() {
  Base base;
  base.publicVar = 10;
  // base.privateVar = 1;

  Public pub;
  pub.publicVar = 10;
  // pub.privateVar - недоступна

  Protected p;
  // p.publicVar = 11;

  Private pr;
  pr.f();

  return 0;
}
[09_private_public_protected/main.cpp](09_private_public_protected/main.cpp)

Доступны и x и y
[10_public_protected_private_combinations/main.cpp](10_public_protected_private_combinations/main.cpp)

Фигура
Название фигуры
Цвет фигуры
Количество точек
Толщина границы (бордюра)
"ABC\0"
Точка
Квадрат
Левый правый угол
Сторона
Окружность
Координаты центра
Радиус окружности
Shape s("222",3,3,3);
[13_InheritShapes/main.cpp](13_InheritShapes/main.cpp)

Шаблонная функция вычисления минимума
Стек заданной длины
T - тип элементов
Size - максимальное количество
(размер стека)
Массив для хранения данных
Количество элементов
Положить в стек значение
Извлечь с вершины стека значение
Очередь заданной длины
Голова и хвост очереди
Количество элементов
Положить в конец очереди
Взять из начала очереди
TODO: Разобрать пример на следующем занятии
Шаблонная функция для печати любой коллекции
[14_template_in_template/main.cpp](14_template_in_template/main.cpp)

Нестатический метод
[31_static/main.cpp](31_static/main.cpp)

ООП, модификатор const
const: общий смысл - "нельзя менять"
C: struct, class - нет
C++: struct - public, class - private
x++;
message[2] = 'A';
increment of read-only variable 'i'|
i++;
p.move(2,3); // Нельзя
[32_const/main.cpp](32_const/main.cpp)

Перегрузка операторов
-----------------------
В C++ возможна перегрузка:
арифметических операций
+ - * /
Перегрузка операций сравнения
> < >= <= == !=
Операции вывода в поток, ввода с клавиатуры
>> <<
#include <assert.h> // для С
#define DEBUG1
Рациональная дробь: p/q
Getters - методы доступа к данным
Setters
void setP(T value){ p = value; }
a + b
Ввод из потока
Ключевое слово friend - функция имеет доступ к закрытым (private/protected)
членам класса (полям и методам)
Вывод в поток
Наибольший общий делитель
template <class T = int>  // Параметр шаблона "по-умолчанию"
class Rational {
T GCD(T, T);
Сокращение дроби
Находим НОД числителя и знаменателя
Делим числитель и знаменатель на НОД
if(q == 0){
cout << "q == 0" << endl;
halt(1);
}
p/q + right.p/right.q
--------------------------
--------------------------
------------
------------
Сокращаем дробь если надо
Шаблонный "шаблонный" параметр
Класс, который является шаблоном можно передавать как параметр
другому классу-шаблону, при этом параметр вложенного шаблона
[32_operators/main.cpp](32_operators/main.cpp)

Переполнение строки - источник уязвимостей
------------------------------------------
``` cpp
  bool passwordCorrect = false;
  char password[10]; // Строка до 9 символов, последний символ 0

  while(true) {
    cout << "Enter password: ";
    cin >> password;

    if(!strcmp(password, "pass"))
      passwordCorrect = true;

    if(passwordCorrect) {
      cout << "OK! Access GRANTED!" << endl;
      system("pause");
      return 0;
    } else
      cout << "Access DENIED :)" << endl;
  }

```

[34_string_overflow/main.cpp](34_string_overflow/main.cpp)

НОД - Наибольший общий делитель
Рациональная дробь: p/q
Сокращение дроби
TODO: Конструктор
TODO: Ввод с клавиатуры
TODO: Показать дробь на экран (в консоль)
TODO: Сложение дробей
a + b
this - указатель на текущий объект
*this - текущий объект
TODO: прибавить к дроби целое число
TODO: прибавить к целому число дробь
TODO: вычитание
Конструктор копирования
cout - типа ostream
stream - поток
thread - поток/нить
Rational c = b + a;
[HomeWork_1/main.cpp](HomeWork_1/main.cpp)

Словарь
Чтение словаря из файла
from - слово на исходном языке
to - перевод
from - ключ, to - значение
dict[from] = to;
out << dict.find(s) << " " << dict.end() << endl;
[HomeWork_2/main.cpp](HomeWork_2/main.cpp)

Новый выбранный шрифт
[InputWidgets/mainwindow.cpp](InputWidgets/mainwindow.cpp)

Точка
Point(){};
Отрезок
p1.x = x1;  p1.y = y1;
p2.x = x2;  p2.y = y2;
Длина отрезка
Point p(2,3);
cout << "p.x = " << p.x << "  p.y = " << p.y << endl;
[PointStuct/main.cpp](PointStuct/main.cpp)

scanf("%s",c);
for(int i = 20; i < 10000; i--)
c[i] = 124;
[StructNew/main.cpp](StructNew/main.cpp)

...
[StructStaticCount/main.cpp](StructStaticCount/main.cpp)

Перевод
Как ввести строку целиком?
Как читать
system("chcp 65001");
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
freopen("out.txt","w",stdout);
Ключ - слово по-английски,
значение - слово по-русски
Словарь = Ассоциативный массив
int p = 1;
fclose(stdin); // !!!
cin >> p;
Считываем
Смотрим в словаре
const int strLen = 1024;
char phrase[strLen];
cin.getline(phrase, strLen);
cout << phrase << endl;
Ищем слово из словаря в строке
cout << inEnglish << " pos " << pos << endl;
[cont_textfiles/main.cpp](cont_textfiles/main.cpp)

потому что в строке символ 0 - окончание строки
Создает копии динамических переменных и ресурсов
SetConsoleCP(65001);
SetConsoleOutputCP(65001);
Добавить в конец кусок строки
Строка должна стать "TestEnd" после этой операции
[copy_constructor/main.cpp](copy_constructor/main.cpp)

Запоминаем значение выравнивания
в стеке компилятора
Выравнивание по 1 байту
Восстанавливаем предыдущее значение
[l5_inherit2/main.cpp](l5_inherit2/main.cpp)

Наследование
Полиморфизм
[l5_inherit/main.cpp](l5_inherit/main.cpp)

Базовый класс "Фигура"
Круг - 1-ый наследник
Прямоугольник - 2-ой наследник
Конструктор
Выводим на экран
[l5_shapes/main.cpp](l5_shapes/main.cpp)

﻿Литература по Qt
----------------
* Боровский А. Qt 4.7+ Практическое программирование на C++. — СПб.: «БХВ-Петербург», 2012. — С. 496. — ISBN 978-5-9775-0757-8.
* Макс Шлее Qt 4.8 Профессиональное программирование на C++. — СПб.: «БХВ-Петербург», 2012. — С. 912. — ISBN 978-5-9775-0736-3.
* Саммерфилд М. Qt. Профессиональное программирование. Разработка кроссплатформенных приложений на С++. — СПб.: «Символ-Плюс», 2011. — С. 560. — ISBN 978-5-93286-207-0.
* Макс Шлее Qt 4.5 Профессиональное программирование на C++. — СПб.: «БХВ-Петербург», 2010. — С. 896. — ISBN 978-5-9775-0398-3.
* Ж. Бланшет, М. Саммерфилд Qt 4: Программирование GUI на C++. 2-е дополненное издание. — М.: «КУДИЦ-ПРЕСС», 2008. — С. 736. — ISBN 978-5-91136-059-7.
* Земсков Ю.В. Qt 4 на примерах. — СПб.: «БХВ-Петербург», 2008. — С. 608. — ISBN 978-5-9775-0256-6.
* Ж. Бланшет, М. Саммерфилд Qt 4: Программирование GUI на C++. — М.: «КУДИЦ-ПРЕСС», 2007. — С. 648. — ISBN 978-5-91136-038-2.
* Макс Шлее Qt 4: Профессиональное программирование на C++. — СПб.: «БХВ-Петербург», 2007. — С. 880. — ISBN 978-5-9775-0010-6.
* Чеботарев А. Библиотека Qt 4. Создание прикладных приложений в среде Linux. — М.: «Диалектика», 2006. — С. 256. — ISBN 5-8459-0996-1.



Утечки памяти
-------------
TODO: SmartPtr для обработки этой ситуации
delete intArray;
delete[] intArray;
[memory_leaks/main.cpp](memory_leaks/main.cpp)

commonVar = 4;
Объявляю 2 экземпляра (объекта) класса
a.privateVar = 2;
Переменная i у каждого объекта своя
commonVar - общая для всех объектов этого класса
[oop/main.cpp](oop/main.cpp)

Умные указатели
Умный указатель (Smart Pointer) — класс (обычно шаблонный),
имитирующий интерфейс обычного указателя и добавляющий некую новую функциональность,
например, проверку границ при доступе или очистку памяти.
В STL есть: std::auto_ptr
Обычный класс
Использует динамическую память
Умный указатель
``` cpp
template <class T>
class SmartPtr {
  T* ptr;
 public:
  SmartPtr(T* p) {
    ptr = p;
  }
  // Автоматическая отчистка динамической памяти
  ~SmartPtr() {
    delete ptr;
  }
  T* operator ->() { // Переход по ссылке
    return ptr;
  }
  T& operator*() { // Оператор разыменования
    return *ptr;
  }
};
```

setlocale(LC_ALL, "Russian");
SmartPtr<int[]> m2 = new int[10];
[smart_pointer/main.cpp](smart_pointer/main.cpp)

set - множество (неповторяющиеся элементы)
Вектор - аналог массива
a.insert(2, 10);
a.remove(3);
[stl/main.cpp](stl/main.cpp)


