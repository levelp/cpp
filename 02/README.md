<!-- doc.py -->

Тернарный оператор - (усл) ? T : F
----------------------------------

*Тернарная условная операция* (лат. ternarius - "тройной") (обычно записывается как ?:) - во многих языках программирования операция,
возвращающая свой второй или третий операнд в зависимости от значения логического выражения, заданного первым операндом.

Массивы: одномерные, многомерные
--------------------------------

Условный оператор if else
-------------------------

Множественный выбор switch
--------------------------

Циклы с предусловием и постусловием: while, do while
----------------------------------------------------

Цикл for
--------

Функции
-------


Записи (struct - структуры). typedef. Записи с вариантами (union)
-----------------------------------------------------------------

Операторы break, continue
-------------------------

Модули: заголовочный файл (header), основной файл (.c и .cpp, .h и .hpp)
------------------------------------------------------------------------


Домашнее задание
----------------
Пользователь вводит натуральное число N. Нужно вывести все способы разложить его на слагаемые.
Способы отличающиеся только порядком слагаемых считаются одинаковыми.

Например N = 4:
4 = 4
4 = 3 + 1
4 = 2 + 2
4 = 2 + 1 + 1
4 = 1 + 1 + 1 + 1

Указатели, работа с памятью
===========================

Типы памяти: статическая, динамическая (куча), стек
---------------------------------------------------

Выделение и освобождение динамической памяти (malloc / free)
------------------------------------------------------------

Ссылки и указатели в C++: общее и различия
------------------------------------------

Операторы new и delete
----------------------

Утечки памяти и методы борьбы с ними
------------------------------------

Отличия C и C++ (ссылки, в приведении типов, перегрузка функций)
----------------------------------------------------------------

Использование динамической памяти на примере реализации структур данных: список, стек, очередь и "дерево"
---------------------------------------------------------------------------------------------------------


``` cpp
// Точность сравнения с нулём
const double EPS = 1e-10;
```

``` cpp
void solve_equation(double a, double b, double c) {
  if(fabs(a) < EPS) {
    if(fabs(b) < EPS) {
      if(fabs(c) < EPS) {
        // Если все три коэффициента нули, то x - любой
        // 0x^2 + 0x + 0 = 0
        cout << "x - any number" << endl;
        return;
      }

      // 0*x^2 + 0*x + не_ноль = 0 - решений нет
      cout << "no solutions" << endl;
      return;
    }

    // Линейное уравнение
    // 0*x^2 + b*x + c = 0
    double x = -c / b;
    cout << "x = " << x << endl;
    // Проверка решения
    cout << "0*x^2 + b*x + c = " << 0 * pow(x, 2) + b* x + c << endl;
    return;
  }

  // Вычисление дискриминанта
  double D = pow(b, 2) - 4 * a * c;

  if((fabs(D) < EPS) && (D != 0)) {
    SHOW(a)
    SHOW(b)
    SHOW(c)
    SHOW(D)
    cout << "FIND IT! :)" << endl;
    system("pause");
  }

  cout << "D = " << D << endl;

  if(fabs(D) <= EPS) {
    double x = -b / (2 * a);
    cout << "x = " << x << endl;
    // Проверяем полученный x
    cout << "f(x) = " << a* x* x + b* x + c << endl;
    return;
  }

  if(D < 0) {
    cout << "no solutions" << endl;
    // Комплексные корни
    double x_re = -b / (2 * a);
    double x1_im = +sqrt(-D) / (2 * a);
    double x2_im = -sqrt(-D) / (2 * a);
    cout << "x1 = " << x_re << " + " << x1_im << " i" << endl;
    cout << "x2 = " << x_re << " + " << x2_im << " i" << endl;
    return;
  }

  // D > 0 - 2 действительных корня
  double x1 = (-b + sqrt(D)) / (2 * a);
  double x2 = (-b - sqrt(D)) / (2 * a);
  cout << "x1 = " << x1 << "  x2 = " << x2 << endl;
  // Проверяем полученные решения
  cout << "f(x1) = " << a* x1* x1 + b* x1 + c << endl;
  cout << "f(x2) = " << a* x2* x2 + b* x2 + c << endl;
}
```

``` cpp
  /*while(1) {
    // Коэффициенты квадратного уравнения
    double a = 2, b, c;
    SHOW(a)
    cout << "a = ";
    cin >> a;

    if(!cin.good()) {
      SHOW(a)
      break;
    }

    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << endl;

    // Вызов функции решения квадратного уравнения
    solve_equation(a, b, c);
```

[00_HomeWork_square_eq/main.cpp](00_HomeWork_square_eq/main.cpp)

``` cpp
#define MIN(x,y) (x < y) ? x : y

int MIN2(int x, int y) {
  return (x < y) ? x : y;
}

template <class T>
T MIN3(T x, T y) {
  return (x < y) ? x : y;
}
```

``` cpp
int NN; // Для разложения

// N - оставшееся число для разложения
// m - последнее слагаемое в сумме
//    (из уже имеющихся слагаемых)
//   4 = 3 + 1
void sum(int N, int m) {
  // Слагаемые
  static int A[MAX_N];
  // Количество слагаемых
  static int K = 0;

  // Если от суммы ничего не осталось
  // => окончание рекурсии
  //  выводим ответ.
  if(N == 0) {
    cout << NN << " = ";

    // все слагаемые кроме последнего
    // с ' + '
    // последнее слагаемое с переводом строки
    for(int i = 0; i < K; ++i)
      cout << A[i] <<
           ((i < K - 1) ? " + " : "\n");

    // Вывели ответ => дальше нечего
    // делать в этой ветке рекурсии
    // выходим
    return;
  }

  // N - число, которое надо разложить
  // m - последнее слагаемое
  //   5 = 2 + ...   и ещё есть 4
  //    тогда следующее слагаемое 2, 1
  //   5 = 4 + ...   ещё есть 1
  //    следующее слагаемое максимум 1
  for(int x = min(N, m); x >= 1; --x) {
    // x - текущее слагаемое
    A[K] = x;
    K++;
    // Сумма уменьшилась на x
    // Максимальное слагаемое - x
    // Идём вглубь рекурсии
    sum(N - x, x);
    // Убираем последнее слагаемое x
    K--;
    // 4 = 2 + 1 + 1
    // 4 = 2 + 1 + ... <-- вернулись
    // надо убрать последнее 1
    // 4 = 2 + ...
    // 4 = 1 + 1 + 1 + 1
  }
}

void sum(int N) {
  sum(N, N);
}

int main() {
  // Вводим число N
  cout << "N = ";
  cin >> NN;
  // Вывод разложения на слагаемые
  sum(NN);
  return 0;
}
```

[00_HomeWork_sum/main.cpp](00_HomeWork_sum/main.cpp)

``` cpp
const int a = 0;

int main() {
  int b = 0;

  if(a == b)
    cout << "a = b" << endl;
  else
    cout << "a != b" << endl;

  return 0;
}
```

[01_left_const/main.cpp](01_left_const/main.cpp)

``` cpp
void f(int*);

void f(int* a) {
  *a = 10;
}

int main() {
  int a = 10;
  // aPtr - указатель
  int* aPtr = &a, aa = 2; // aPtr - указатель, b - не указатель
  aPtr = &a; // записываем в него адрес a
  SHOW(a); // a = 10
  // *aPtr = что-то..
  // Записываем значение туда, куда указывает
  // aPtr
  *aPtr = 12; // a = 12
  SHOW(a);
  // Перемещаем указатель
  // теперь он будет указывать на aa
  aPtr = (int*) aa;
  // *aPtr = 1000; -- пишем в неведомую ячейку
  aPtr = &aa;
  *aPtr = 1000;
  SHOW(aa);

  int* bPtr, c;

  int& b = a; // Ссылка
  //int &bb;  // error: 'bb' declared as
  // reference but not initialized
  int d = 22;
  // &b = d; // Нельзя переопределять ссылки

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  b = 11;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  int* ptr; // Указатель можно не инициализировать

  // Указывает на переменную a
  ptr = &a;
  cout << "*ptr = " << *ptr << endl;

  ptr = &d;
  cout << "*ptr = " << *ptr << endl;

  ptr = NULL;

  return 0;
}
```

[02_references/main.cpp](02_references/main.cpp)

Указатели
---------
[03_pointers/main.c](03_pointers/main.c)

``` cpp
  // N < 0 => ошибка
  // 0 углов => пустота
  // 1 угол => точка
  // 2 угла => отрезок
  // 3 угла => треугольник
  // 4 угла => четырёхугольник
  // N >= 5 углов => N-угольник
  int N;
  cout << "Enter number of edges: ";
  cin >> N;

  switch(N) {
    case 1: { // 1 угол => точка
      int i = 1, j = 10;

      for(int k = 0; k < 10; ++k) {
      }

      cout << "point" << endl; // Точка
    }
    break;

    case 0: // 0 углов => пустота или круг
      cout << "emptiness / circle" << endl;
      break;

    case 2: // 2 угла => отрезок
      cout << "segment" << endl;
      break;

    case 3: // 3 угла => треугольник
      cout << "triangle" << endl;
      break;

    case 4: // 4 угла => четырёхугольник
    case 5:
      // Общая обработка для случаев N = 4,5
      cout << N << "th polygon" << endl;
      break;

    //case -1:
    //  cout << "-1" << endl;

    //case -2:
    //  cout << "-2" << endl;

    default:  // N < 0 => ошибка, N >= 5 углов => N-угольник
      cout << ((N < 0) ? "error" : "N-edged polygon") << endl;
      break;

      //case -3:
      //  cout << "-3" << endl;
  }

```

[03_switch/main.cpp](03_switch/main.cpp)

Значение / ссылка / указатель
-----------------------------
* **__FUNCTION__** - имя текущей функции
* **__FILE__** - имя текущего файла
* **__LINE__** - номер текущей строки
Усовершенствованный макрос **SHOW**
``` cpp
#define SHOW(x) cout << __FUNCTION__ << ":" << \
                     __LINE__ << " " << #x << " = " << x << endl;
```

``` cpp
// По значению
void f1(int i) {
  SHOW(i)
  i++; // i - это уже другая переменная
  // значение копируется из внешней i
  // i - локальная переменная
  SHOW(i) // i = 1
}

int globalVar = 10;

// По ссылке (только C++)
void f2(int& i) {
  // У i тот же адрес, что и у j
  cout << "i - alias for j" << endl;
  SHOW(i)
  i++;
  SHOW(i)
  // i = &globalVar;
}

// По указателю
void f3(int* i) {
  (*i)++;
  SHOW(*i)
  i = &globalVar;
}

int main() {
  int j = 0; // i или j не имеет значения
  SHOW(j); // j = 0

  f1(j);
  SHOW(j); // j = 0

  f2(j);
  SHOW(j); // j = 1

  f3(&j);
  SHOW(j);

  return 0;
}
```

[03_var_reference/main.cpp](03_var_reference/main.cpp)

``` cpp
void inc2(int& value) {
  value += 2;
}

int main() {
  int value = 11;
  // int & - объявляем ссылку
  int& b = value; // b и value - одна и та же переменная
  // только с 2-мя именами
  b = 10; // изменилось value
  value = 12; // изменилось b

  int* ptrA, valueA; // ptrA - указатель, valueA - значение
  valueA = 122;

  ptrA = &value; // Указатель ptrA указывает на
  // переменную value

  // *ptrA и value - одна и та же переменная
  value = 1000; // изменится и *ptrA
  *ptrA = 111; // изменится и value

  int d;
  ptrA = &d;

  int x = 1, y = 10;
  inc2(x);
  inc2(y);

  return 0;
}
```

[04_ref_demo/main.cpp](04_ref_demo/main.cpp)

``` cpp
int main() {
  int A[100];
  A[0] = 42;
  A[1] = 56;
  SHOW(A[0])
  SHOW(*A + 10);

  int* X;

  int* B = A; // B - второе имя для массива A
  SHOW(B[0]);
  B[1] = 99;
  SHOW(A[1]); // 99

  A[1] = 101;
  B = A + 1; // Сдвиг на один элемент
  SHOW(A[1]) // 101
  SHOW(B[0]) // 101

  int*& Y = X; // Y - второй имя для переменной X
  X = new int[100];
  int* Z = X;
  X[10] = 55;
  assert(Y[10] == X[10]);
  assert(Z[10] == X[10]);

  X = new int[100];
  X[10] = 56;
  assert(Y[10] == X[10]);
  // Не работает: assert(Z[10] == X[10]);

  int a1 = 10, a2 = 4;
  //  int& BB[] = { &a1, &a2 };
  // TODO: разобраться

  int K = 10;

  //cout << &*Y /* <=> */ Y

  cout << A[0] << endl;
  cout << *A << endl;

  cout << A[1] << endl;
  cout << *(A + 1) << endl;

  cout << B[0] << endl;
  cout << *B << endl;

  cout << B[1] << endl;
  cout << *(B + 1) << endl;

  return 0;
}
```

[04_refs_array/main.cpp](04_refs_array/main.cpp)

``` cpp
  int intArray[10];
  // int - тип элементов массива
  // intArray - название массива
  // 10 - количество элементов
  // Нумерация элементов: 0..9

  // Записываем 23 в первый элемент массива
  intArray[0] = 23;
  intArray[1] = 10; // 10 во второй элемент массива

  cout << intArray[0] + intArray[1] << endl;

  // Увеличить каждый элемент массива на 10
  for(int i = 0; i < 10; ++i)
    intArray[i] += 10;

  // Поиск минимума в массиве
  int minValue = intValue[0];

  for(int i = 1; i < 10; ++i)
    if(intArray[i] < minValue)
      minValue = intArray[i];

  // Поиск максимума в массиве
  int maxValue = intValue[0];

  for(int i = 1; i < 10; ++i)
    if(intArray[i] > maxValue)
      maxValue = intArray[i];

```

[07_arrays/main.cpp](07_arrays/main.cpp)

``` cpp
int arrayMin(int A[], int N) { // var N
  assert(N > 0);
  int curMin = A[0]; // Текущий минимум - первый элемент

  for(int i = 1; i < N; ++i)
    if(A[i] < curMin) // Если встретили элемент меньше
      curMin = A[i];     // => обновили текущий минимум

  return curMin;
}

void f() { // procedure F;
}

int main() {
  assert( 2 * 2 == 4 );

  // Ввод количества элементов массива
  int N;

  do {
    if(!cin.good()) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(),
                 '\n');
    }

    assert(cin.good());
    cout << "N = ";
    cin >> N;
  } while(!cin.good() && N < 1);

  // Заводим массив A в динамической памяти
  int* A = new int[N];

  // Вводим массив с консоли
  for(int i = 0; i < N; ++i) {
    cout << "A[" << i << "] = ";
    cin >> A[i];

    if(!cin.good()) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(),
                 '\n');
      cout << "Error: not a valid integer" << endl;
      --i;
    }
  }

  // Вызываем функцию поиска минимума и
  // выводим результат на консоль
  cout << "min = " << arrayMin(A, N) << endl;

  // Очищаем занимаемую динамическую память
  delete[] A;

  return 0;
}
```

[09_array_task/main.cpp](09_array_task/main.cpp)

``` cpp
const int SIZE = 100000;

// int A[]
// int &A[]
// /*, int arraySize*/ /* параметры */
int arrayMax(int* A) {
  // Предположим, что максимум это первый элемент
  int curMax = A[0];
  A[0] = -10; // Портим массив :)

  // Пробежим по остальным элементам массива
  // если какой-то элемент больше текущего
  // максимума, то запомним новый текущий максимум
  for(int i = 1; i < SIZE; ++i)
    if(A[i] > curMax)
      curMax = A[i];

  cout << "A[0] = " << A[0] << endl;

  return curMax;
}

int main() {
  // Массив в стеке
  int A[SIZE];

  // Заполняем случайными числами
  for(int i = 0; i < SIZE; ++i) {
    A[i] = rand() % 10000;    // от 0 до 9999
  }

  A[0] = -1;
  cout << "A[0] = " << A[0] << endl;

  cout << "max = " << arrayMax(A) << endl;

  cout << "A[0] = " << A[0] << endl;

  return 0;
}
```

[17_task_large_arrays/main.cpp](17_task_large_arrays/main.cpp)

``` cpp
#define MIN(x,y) (x < y) ? x : y

int min2(int x, int y) {
  return (x < y) ? x : y;
}

template <class T>
T min3(T x, T y) {
  return (x < y) ? x : y;
}
```

[HomeWork_3/main.cpp](HomeWork_3/main.cpp)

``` cpp
struct Point {
  double x, y;
};
```

``` cpp
  // Заводим массив в динамической памяти
  int* intArray;
  intArray = new int[1000]; // new со скобками []
  intArray[0] = 10;
  intArray[1] = 23;
  delete[] intArray; // И delete должен быть со скобками

  Point* p = new Point;
  delete p; // delete без скобочек []
```

[cpp_dynamic/main.cpp](cpp_dynamic/main.cpp)

``` cpp
struct StackElement {
  int value; // Значение элемента стека
  StackElement* next; // Указатель на следующий элемент стека
};
```

``` cpp
class Stack { // Можно использовать struct
  StackElement* root;
```

``` cpp
  Stack() : root(NULL) { }
```

``` cpp
  ~Stack() {
    while(root != NULL) {
      StackElement* saveForDelete = root;
      root = root->next;
      delete saveForDelete;
    }
  }
```

``` cpp
  void push(int newValue) {
    // Создали новый элемент стека с новым значением
    StackElement* newElement = new StackElement;
    newElement->value = newValue;
    // "Подвешиваем" root к новому элементу
    newElement->next = root;
    // Делаем новый элемент первым в списке
    root = newElement;
  }
```

``` cpp
  int pop() {
    if(root == NULL) {
      cout << "Stack is empty!" << endl;
      return 0;
    }

    // Получаем верхний элемент
    StackElement* topElement = root;
    // Получаем значение верхнего элемента
    int value = topElement->value;
    // Переставим корень списка на след. элемент
    root = topElement->next;
    // Очистим память
    delete topElement;
    // Вернём значение
    return value;
  }
```

``` cpp
  void show() {
    for(StackElement* cur = root;
        cur != NULL;
        cur = cur->next)
      cout << cur->value << endl;
  }
```

``` cpp
  Stack s;
  s.push(2);
  s.push(4);
  s.push(5);
  s.show();
  cout << "pop result = " << s.pop() << endl;
  s.show();
```

[stack/main.cpp](stack/main.cpp)


Домашнее задание - рекурсия
---------------------------
  ЗАДАНИЕ:
 Пользователь вводит натуральное число N.
 Нужно вывести все способы разложить его на слагаемые.
 Способы отличающиеся только
 порядком слагаемых считаются одинаковыми.

Например N = 4:
* 4 = 4
* 4 = 3 + 1
* 4 = 2 + 2
* 4 = 2 + 1 + 1
* 4 = 1 + 1 + 1 + 1

