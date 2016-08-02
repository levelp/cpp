<!-- doc.py -->
﻿Введение в Qt, Qt Creator, QtCore, QtGui, отладка
=================================================

Установка Qt. Ссылки для скачивания
-----------------------------------
* Qt Creator: http://qt-project.org/downloads
* http://www.qt.io/download-open-source/

При установке снимите галочку с **msvc 2013 ..** и поставьте на **MinGW 4.9.1**.

QT - история
------------

Первый выход в свет библиотеки Qt состоялся в мае 1995 года.
Первоначально она разрабатывалась Хаавардом Нордом (главный управляющий Trolltech) и Эриком Чамбенгом (президент компании Trolltech).
Хаавард и Эрик встретились в стенах Норвежского Технологического Института, в городе Тронхейме, где они получали высшее образование.

В 1991 году Хаавард написал первые несколько классов, из которых потом и появилась Qt.
Эрик занялся разработкой общего дизайна библиотеки.
На следующий год Эрику пришла в голову идея реализации "сигналов и слотов" - простой но очень мощной парадигмы программирования графического интерфейса.
Хаавард подхватил идею и воплотил ее в код.
К 1993 году они завершили разработку первого графического ядра и приступили к созданию визуальных компонентов (widgets).
В конце года Хаавард предложил Эрику открыть совместное дело и выпустить "лучшую в мире библиотеку реализации графического интерфейса на C++".

**Сигнал** генерируется когда происходит определенное событие.

**Слот** - функция (обработчик), которая вызывается в ответ на определенный сигнал.

В качестве префикса в именах классов был выбран символ "Q", поскольку Хааварду очень нравилось как он выглядел в Emacs.
Символ "t" был выбран потому, что с него начиналось слово "toolkit", по аналогии с "Xt" -- "X toolkit".
Компания была зарегистрирована 4 марта 1994 года под названием "Quasar Technologies", которое затем было преобразовано в "Troll Tech", а затем и в "Trolltech".

В апреле 1997 года вышла Qt 1.2.

В 2001 году вышла Qt 3.

Летом 2005 года была выпущена Qt 4.0.
Имея около 500 классов и более 9000 функций, Qt 4 оказалась больше и богаче любой предыдущей версии;
она была разбита на несколько библиотек, чтобы разработчики могли использовать только нужные им части Qt.
Версия Qt 4 представляет собой большой шаг вперёд по сравнению с предыдущими версиями;
она содержит полностью новый набор эффективных и простых в применении классов-контейнеров, усовершенствованную функциональность архитекторы модель/представление,
быстрый и гибкий фреймфорк графики 2D и мощные классы для просмотра и редактирования текста в кодировке Unicode,
не говоря уже о тысячах небольших улучшений по всему спектру классов Qt.
Qt 4 является первой версией Qt, доступной на всех поддерживаемых платформах как для коммерческой разработки, так и для разработки с открытым исходным кодом.

2012 год - выход Qt 5.0.
Главные изменения в Qt5 связаны с модульностью Qt и активным переходом на декларативное описание интерфейса (Qt Quick).
Это не значит, что Qt перепишут на JavaScript,
просто C++ будет использоваться для написания критичных ко времени выполнения или сложных вещей.
Сохраняется и базовая обратная совместимость: в Qt 5 вошли почти все компоненты Qt 4, кроме устаревших,
большинство модулей из Qt Mobility (теперь это уже не отдельный продукт) и некоторые экспериментальные разработки.

Установка и запуск Qt Creator. Qt Designer
------------------------------------------

Создание простейшего приложения. Сигналы и слоты. Обработка событий
-------------------------------------------------------------------

Проектирование пользовательского интерфейса с учётом требований эргономичности (компоненты, события, сигналы, слоты в Qt)
-------------------------------------------------------------------------------------------------------------------------


﻿Создание приложения в Qt
------------------------
* Запускаем Qt Creator
* Создаём главную форму
* Добавляем виджеты
* Используем сигналы и слоты

Основная программа на Qt
``` cpp
#include "mainwindow.h"
#include <QApplication>
#include <QDebug> // Отладочный вывод в консоль
#include <iostream>

using namespace std;


/// * argc - количество аргументов
/// * argv - параметры командной строки
``` cpp
int main(int argc, char* argv[]) {
  // Печатаем количество аргументов
  cout << "argc: " << argc << endl;

  // И сами аргументы
  for(int i = 0; i < argc; ++i)
    cout << argv[i] << endl;

  // Обработка сигналов
  // Связь сигнал -> слот
  QApplication a(argc, argv);

  // Создаём основное окно
  MainWindow w;
  // Показываем основное окно
  w.show();

  cout << "Starting..." << endl;

  // Запуск основного цикла обработки событий
  int res = a.exec();

  cout << "Closing... res = " << res << endl;
  return res;
}
```

[00_FirstQtApp/main.cpp](00_FirstQtApp/main.cpp)

Слот (обработчик сигнала) - реализуется как обычный метод
``` cpp
void MainWindow::on_closeButton_clicked() {
  qDebug() << "on_closeButton_clicked()";
}

void MainWindow::on_concatButton_clicked() {
  // ui - Ui::MainWindow *ui;
  // Указатель на сгенерированный
  // по *.ui файлу класс Ui::MainWindow
  QLineEdit* line1 = ui->lineEdit_1;
  // line1 - указатель на виджет
  // Чтобы получить текст мы вызываем
  // метод text()
  // который возвращает QString
  QString s1 = line1->text();
  qDebug() << s1;
  qDebug() << ui->lineEdit_2->text();

  // Свойство называется так:
  //    имяСвойства
  // Чтобы получить значение вызываем метод:
  //    имяСвойства()
  // Чтобы поменять значение вызываем метод:
  //   setИмяСвойства(Новое_значение)
  ui->resEdit->setText(s1 +
                       ui->lineEdit_2->text());
}
```

[00_FirstQtApp/mainwindow.cpp](00_FirstQtApp/mainwindow.cpp)

``` cpp
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  // parent - объект при уничтожении которого
  //  должен быть уничтожен и этот объект
  // Обычно основное (главное) окно программы
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  // Слоты - методы-обработчики сигналов
  void on_pushButton_clicked();

  void on_closeButton_clicked();

  void on_concatButton_clicked();

  void on_enableButton_clicked();

 private:
  Ui::MainWindow* ui;
};
```

[00_FirstQtApp/mainwindow.h](00_FirstQtApp/mainwindow.h)

* ﻿Создание приложения в Qt

* НОД - Наибольший общий делитель
* GCD - Greatest Common Divisor
Используем алгоритм Евклида с делением
``` cpp
ll GCD(ll a, ll b) {
  return (b == 0) ? a : GCD(b, a % b);
}
```

Рациональная дробь: p/q
``` cpp
class Rational {
  ll p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  //  4/6 -> НОД(4,6)=2 -> 2/3
  void normalize() {
    ll d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель

    if(q < 0) {
      p = -p;
      q = -q;
    }
  }
 public:
  // Конструктор
  Rational(ll pi, ll qi) : p(pi), q(qi) {
    assert(q != 0);
    normalize();
  };
  // Ввод с клавиатуры
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
    // normalize(); // Нельзя, т.к. он меняет объект
    // Сокращаем дробь если надо
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    long px = p / d; // делим на него числитель
    long qx = q / d; // делим на него знаменатель

    // Заменяем дроби вида -1/-2 на 1/2
    if(qx < 0) {
      px = -px;
      qx = -qx;
    }

    // Если знаменатель равен 1
    // то это целое число
    if(qx == 1)    // Условие (1)
      os << px;
    else { // Иначе есть дробная часть
      // Вычисляем целую часть
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
      os << px << "/" << qx;
    }
  }
  // Сложение дробей
  // a + b
  Rational operator+(Rational& r) {
    // this - указатель на текущий объект
    // *this - текущий объект
    return Rational(p * r.q + r.p * q,
                    q * r.q  );
  }

  // прибавить к дроби целое число
  Rational operator+(int right) {
    return Rational(p + right * q,
                    q);
  }

  // прибавить к целому число дробь
  friend Rational
  operator+(long left, Rational& r) {
    return Rational(left * r.q + r.p,
                    r.q);
  }

  // вычитание
  Rational operator-(Rational& r) {
    return Rational(p * r.q - r.p * q,
                    q * r.q  );
  }

  // Конструктор копирования
  Rational(const Rational& r) {
    p = r.p;
    q = r.q;
  }

  // cout - типа ostream
  friend ostream& operator << (ostream& os,
                               Rational r) {
    r.show(os);
    return os;
  }

  // stream - поток
  // thread - поток/нить
};
```

[00_HomeWork_Done/main.cpp](00_HomeWork_Done/main.cpp)

Конструктор копирования
-----------------------
Создаем собственный класс "Строчка"
``` cpp
struct String {
  char* str; // Здесь храним строчку
  int x; // Дополнительное поле
  // Конструктор
  String(char* initStr) {
    str = new char[strlen(initStr) + 1];
    strcpy(str, initStr);
  }
  // Конструктор копирования
  String(String& s) : String(s.str)  {
    cout << "Copy constructor" << endl;
    x = s.x;
  }
  // Деструктор
  ~String() {
    delete[] str;
  }
};
```

Если написать так, то получим ошибку выполнения,
т.к. пытаемся переписать константу
```cpp
const char *str = "Hello";
str[0] = 'X';
```
[01_OOP/01_copy_contructor/main.cpp](01_OOP/01_copy_contructor/main.cpp)

Виртуальный деструктор
----------------------
Базовый класс
``` cpp
class Test {
 public:
  static int alive;
  virtual void init() {
    printf("Test::init()\n");
  }
  Test() { // Конструктор
    printf("Test::Test()\n");
    alive++;
  }
  // Если убрать virtual, то будет
  // вызываться деструктор предка
  virtual ~Test() { // Деструктор
    printf("Test::~Test()\n");
    alive--;
  }
};

int Test::alive = 0;
```

Наследник:
``` cpp
class Test2 : public Test {
 public:
  static int alive2;
  virtual void init() {
    printf("  Test2::init()\n");
  }
  Test2() { // Неявный вызов конструктора Test
    printf("  Test2::Test2()\n");
    alive2++;
  }
  ~Test2() {
    printf("  Test2::~Test2()\n");
    alive2--;
  }
};

int Test2::alive2 = 0;
```

При выполнении new:
1. отводится область динамической памяти
2. вызывается конструктор объекта
``` cpp
    Test2 tt;
    tt.init();
```

[01_OOP/02_virtual_destructor/task1.cpp](01_OOP/02_virtual_destructor/task1.cpp)

Файловый ввод и вывод с помощью потоков
---------------------------------------
``` cpp
#include <fstream> // Файловый ввод и вывод с помощью потоков
```

``` cpp
  ifstream in("in.txt");
  ofstream out("out.txt");

  int a, b;
  in >> a >> b;
  out << "a + b = " << (a + b) << endl;

  in.close();
  out.close();
```

[01_OOP/03_iostream_files/a_sum.cpp](01_OOP/03_iostream_files/a_sum.cpp)

cin - istream;
cout - ostream;
ifstream - input file stream

Открываем текстовый файл для ввода
``` cpp
  ifstream in("data.txt");
  string s;
  double x, y;
  in >> s >> x >> y;
  cout << s << " " << x << " " << y <<
       "   x + y = " << (x + y) << endl;
  in.close();
```

Перенаправляем вывод в файл **log.txt**:
``` cpp
  freopen("log.txt", "a", stdout);

  cout << "Квадраты чисел:" << endl;

  for(int i = 0; i < 10; ++i)
    cout << i << "^2 = " << i* i << endl;

```

Выходной файл автоматически
закрывается при закрытии программы
[01_OOP/03_iostream_files/main.cpp](01_OOP/03_iostream_files/main.cpp)

Перенаправление консольного ввода/вывода
----------------------------------------
Подключаем cstdio для **freopen**
``` cpp
#include <cstdio>
```

Ввод из файла вместо консоли:
``` cpp
  freopen("sum.in", "r", stdin); // stdin - поток ввода с консоли
```

Вывод в файл вместо консоли:
``` cpp
  freopen("sum.out", "w", stdout);
```

Дальше работаем с файлами как с консолью
``` cpp
  long long a, b;
  cin >> a >> b;
  cout << a << " + " << b << " = " << (a + b) << endl;
```

[01_OOP/03_iostream_files/redirect_output.cpp](01_OOP/03_iostream_files/redirect_output.cpp)

Базовое применение шаблонов
Без использования шаблонов
T - параметр шаблона
Шаблонная функция
Предусловия
Параметры шаблонов:
типы: class G / typename T
любой из типов: int I
Функция, добавляющая константу
assert(2*2 == 5);
[02_templates/31_template_min_max/01_template_min_max/main.cpp](02_templates/31_template_min_max/01_template_min_max/main.cpp)

Утиная типизация - Duck Typing
------------------------------
t.VilyaletHvostom(); // Виляет хвостом
[02_templates/32_template_duck_typing/main.cpp](02_templates/32_template_duck_typing/main.cpp)

a - массив
N - количество элементов
T - параметр шаблона
произвольный тип, с которым можно выполнять
операции (т.е. он подходит по duck typing)
Вывести через запятую
2, 3, 4
[02_templates/33_print_commas/main.cpp](02_templates/33_print_commas/main.cpp)

Шаблон:
* template <class T>
* template <typename T>
Элемент стека и очереди:
``` cpp
template <typename T>
struct E {
  T value; // Значение элемента
  E<T>* next; // Указатель на следующий элемент
};
```

Стек
``` cpp
template <typename T = int> // Значение по-умолчанию int
struct Stack {
  E<T>* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) {}
  // Значение поместить на вершину стека
  void push(T value) {
    E<T>* newElement = new E<T>;
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
  T pop() {
    // Запоминаем результат
    // - значение элемента-"вершины" стека
    // 1-A
    T result = top->value;

    // Запоминаем ссылку на удаляемый
    // элемент
    // 1-B
    E<T>* e = top;

    // 2. Перемещаем вершину на следующий
    top = top->next;

    // 3. Реально удаляем элемент
    delete e;

    // 4. Возвращаем результат
    return result;
  }
};
```

``` cpp
template <typename T>
struct Queue {
  E<T>* head; // "Голова" - начало очереди
  E<T>* tail; // "Хвост" - конец очереди
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};
  // В конец очереди
  void put(T value) {
    // Создаём новый элемент
    E<T>* e = new E<T>;
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
  T get() {
    // Запоминаем первый элемент
    E<T>* firstElement = head;
    // Значение, которое мы в конце вернём
    T value = firstElement->value;
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

[02_templates/33_template_stack_queue/main.cpp](02_templates/33_template_stack_queue/main.cpp)

Задача:
Функция, вычисляющая сумму элементов
массива с произвольным типом данных.
Понятно, что функция применима только если
элементы массива поддерживают операцию
сложения "+"
size_t - целый тип, используемый для индексации массивов
Универсальная функция суммирования
Отдельная функция для суммирования строк
Комплексное число
re - действительная часть
im - мнимая часть
Строки тоже можно "суммировать"
Это называется "Конкатенация строк"
[02_templates/35_template_sum/main.cpp](02_templates/35_template_sum/main.cpp)

Демонстрация "зачем нужны шаблоны"
Задача: мы хотим написать функции сортировки для всех типов данных
Если не использовать шаблоны,
то для 2 типов (int, сhar) требуется две реализации
функции сортировки
Используем простейший алгоритм сортировки
На i-ом шаге сделаем, чтобы на i-ом месте
был минимальный элемент на отрезке массива от i до конца массива
i - начало интервала, пусть j пробегает все элементы после i
на i-ом месте
Меняем два элемента
чтобы на i-ом месте стоял минимальный
элемент
Вторая реализация точно такая же, но int заменяем на char
Меняем два элемента
чтобы на i-ом месте стоял минимальный
элемент
Универсальная сортировка (для любых типов)
template <class T>
Меняем два элемента
чтобы на i-ом месте стоял минимальный
элемент
Массив целых чисел
s<int>(a,3)
Массив букв
Можно применить и к действительным числам
..и к строкам...
...и к любым другим типам данных (в том числе своим)..
..к которым применима операция "меньше"..
[02_templates/36_template_sort/main.cpp](02_templates/36_template_sort/main.cpp)

В цикле мы не можем создавать реализации шаблона
т.к. они создаются на этапе компиляции
error: no matching function for call to 'add(int&)'|
[02_templates/38_template_many_functions/main.cpp](02_templates/38_template_many_functions/main.cpp)

MyClass c1, c2;
add<MyClass>(c1,c2);
[02_templates/l5_template2/main.cpp](02_templates/l5_template2/main.cpp)

template: реализация структуры данных "Список"
----------------------------------------------
Шаблонная функция
Элемент списка
Конструктор
Так нельзя (!!!):
root->next = NULL;
Деструктор - метод, который вызывается при
уничтожении объекта
Добавить в начало списка
Заводим новый элемент списка в динамической памяти
Записываем в него новое значение
(*newElement).value = newValue;
Этот элемент должен встать в начало списка,
т.е. все остальные элементы будут после него.
Показать список
Текущий элемент - сначала 1-ый
Добавить элемент в конец списка
Идём до последнего элемента
for(ListElement* cur = root;
cur->next != NULL; cur = cur->next)
/* Ничего не надо делать :) */;
Создаём новый элемент
Новый элемент ставим в конец списка
myFunction<double>()
make_pair(234, 'c');
List - класс
list - объект этого класса
[02_templates/l5_template/main.cpp](02_templates/l5_template/main.cpp)

Базовое применение шаблонов
---------------------------
Функция в C до шаблонов
Шаблоны есть только в C++
Без использования шаблонов
Шаблонная функция
T - параметр шаблона (произвольный тип данных)
Шаблонная функция
Предусловия
Параметры шаблонов:
типы: class G / typename T
любой из типов: int I
Функция, добавляющая константу
Перегрузка операции '<' для точки
assert(2*2 == 5);
Шаблоны умеют автоматически определять
тип по типам аргументов
Явно указать параметр шаблона
[02_templates/main.cpp](02_templates/main.cpp)

Произведение всех чисел
в массиве A
``` cpp
template <typename T>
T mul(T A[], size_t size) {
  if(typeid(T) == typeid(int))
    cout << "int" << endl;

  if(typeid(T) == typeid(double))
    cout << "double" << endl;

  //cout << typeid(T).name() << endl;
  // TODO: реализовать
  T res = 1; // Произведение 1

  for(size_t i = 0; i < size; ++i)
    res *= A[i]; // Умножаем на все последующие

  return res;
}
```

[02_templates/task_mul/main.cpp](02_templates/task_mul/main.cpp)

Вектор - аналог массива
Массив строк
Вектор строк
Удаляем элемент из середины вектора
Второй пример
[03_STL/1_vector.cpp](03_STL/1_vector.cpp)

Итератор по буквам строки
-------------------------
map - ассоциативный массив
ключ - как индекс в массиве
size_t -
Итератор в строке пробегает по буквам
с первой буквы до последней по одной
Очередная буква строки
Не нашли букву => она первый раз
[03_STL/6_map_count_chars.cpp](03_STL/6_map_count_chars.cpp)

``` cpp
void dict() {
  // Контейнеры:
  //   vector
  //   set
  //   map
  setlocale(LC_ALL, "Russian");

  // Ассоциативный массив
  // A["Hi"] = "Привет";
  // map<key, value>
  map<string, string> dict;

  // dict[3] = 4;
  // dict[3] = 5;

  dict["Привет"] = "Hi";
  dict["Я"] = "I";

  dict["Ты"] = "You";
  cout << dict["Ты"] << endl;

  dict["Ты2"] = "You2";
  cout << dict["Ты"] << endl;

  map<MyClass, string> mm;
  MyClass m;
  mm[m] = "Test";
}
```

[03_STL/7_map_dict.cpp](03_STL/7_map_dict.cpp)

Задача "сортировка строк"
-------------------------
Ввести из файла **in.txt** количество строк N
Ввести из файла N строк
Отсортировать и вывести в файл **out.txt**
``` cpp
  // Вектор для хранения строк
  vector<string> strings;
  // Открываем входной файл
  ifstream in("in.txt");

  // Считываем сами строки
  // in.eof() in.good() - до конца файла
  while(!in.eof()) {
    string s;
    getline(in, s);

    if(in.eof())
      break;

    strings.push_back(s);
    cout << s << endl;
  }

  // Сортируем
  sort(strings.begin(), strings.end());

  // Открываем файл для вывода
  ofstream out("out.txt");

  // Выводим строки
  /*for(int i = 0; i < strings.size(); ++i)
    out << strings[i] << endl; */

  for(vector<string>::iterator
      i = strings.begin();
      i != strings.end();
      ++i )
    out << *i << endl;

  // Закрываем файл
  out.close();
```

[03_STL/8_sort_strings.cpp](03_STL/8_sort_strings.cpp)

sort algorithm example
using default comparison (operator <):
myvector.size()
using function as comp
Сортировка в обратном порядке
using object as comp
print out content:
[03_STL/9_sort_my_comparator.cpp](03_STL/9_sort_my_comparator.cpp)

``` cpp
#define SHOW(x) cout << #x << " = " << x << endl;
#define X(a,b) ((a == b) ? (void)0 : _assert(#a" != "#b, __FILE__, __LINE__))
```

``` cpp
template <class T>
void showCollection(T v) {
  for(size_t i = 0; i < v.size(); ++i)
    cout << v[i] << " ";

  cout << endl;
}
```

[03_STL/common.h](03_STL/common.h)

map<ключ, значение>
m[ключ] = значение;
...
[04_Qt_templates/02_map_example/main.cpp](04_Qt_templates/02_map_example/main.cpp)

Конец слова
Выделяем слово
Переводим слово
[04_Qt_templates/qt_map_example/main.cpp](04_Qt_templates/qt_map_example/main.cpp)

throw 2;
qDebug() << "Error: " << s;
[05_Exceptions/main.cpp](05_Exceptions/main.cpp)

``` cpp
int main(int argc, char* argv[]) {
  // Очередь и обработка событий
  //  Сигнал => Слот
  //  Объект_отправитель отправляет
  //   сигнал
  //  Его получают все объекты_получатели
  //   у которых подходящие слоты
  //   подключены к этому сигналу
  // Пример:
  //   Объект отправитель - Кнопка
  //   Сигнал - нажатие кнопки
  //   При созданнии сигнала этого типа
  //   будут вызваны все функции-обработчики
  //   подключенные к этому сигналу.
  QApplication a(argc, argv);

  // Создаём основное окно программы
  MainWindow w;
  // Показываем его
  w.show();

  // Запускаем цикл обработки событий
  return a.exec();
}
```

[06_Qt_HelloWorld/main.cpp](06_Qt_HelloWorld/main.cpp)

TODO: реализовать перемещение
ui->textEdit->geometry().translate(0, 10);
TODO: реализовать перемещение
TODO: реализовать перемещение
TODO: реализовать перемещение
[HomeWork_1/mainwindow.cpp](HomeWork_1/mainwindow.cpp)




setlocale(LC_CTYPE,"rus");
setlocale(LC_CTYPE,"rus.1251");
setlocale(LC_CTYPE,NULL);
setlocale(LC_ALL, "ru_RU.UTF-8");
setlocale(LC_CTYPE, "UTF-8");
setlocale(LC_ALL, "UTF-8");
SetConsoleOutputCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
system("chcp 65001");
locale u("rus_RUS.utf8"); // или rus.utf8, или просто .utf8 ?
cout.imbue(u);
[console_utf8/main.cpp](console_utf8/main.cpp)

﻿Коды ошибок выполнения
----------------------
* 0xС0000005 - Access violation

﻿Домашняя работа
---------------

1. Посмотреть, собрать, запустить примеры + подготовить вопросы
2. Реализовать перемещение виджета по нажатию кнопок


