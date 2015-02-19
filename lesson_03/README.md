<!-- doc.py -->
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

Вычисление минимума
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

[00_HomeWork_2/main.cpp](00_HomeWork_2/main.cpp)

Утверждения: assert, TDD
------------------------
Утверждения нужны для автоматической проверки (тестирования).

Разработка через тестирование (TDD, test-driven development) -
техника разработки программного обеспечения,
которая основывается на повторении очень коротких циклов разработки:
* сначала пишется **тест**, покрывающий желаемое изменение,
* затем пишется **код**, который позволит пройти тест,
* и под конец проводится **рефакторинг** нового кода.

Для создания автоматических тестов можно использовать
функцию **assert**
``` cpp
#include <assert.h>
```

Разрабатываем функцию вычисления факториала.
Контракт - какие обязательства берёт на себя
вызывающая сторона.
``` cpp
long long fact(int n) {
  assert(n >= 0); // Контракт

  if(0 == n)
    return 1;

  return n * fact(n - 1);
}
```

Автоматические тесты
Модульное тестирование
``` cpp
  assert( fact(1) == 1 );
  assert( fact(2) == 2 );
  assert( fact(3) == 6 );
  assert( fact(3) == 1 * 2 * 3);
  assert( fact(4) == 1 * 2 * 3 * 4 );
  assert( fact(5) == 1 * 2 * 3 * 4 * 5 );
  assert( fact(6) == 1 * 2 * 3 * 4 * 5 * 6 );
  assert( fact(7) == 1 * 2 * 3 * 4 * 5 * 6 * 7 );
  assert( fact(0) == 1 );
```

Ручное тестирование функции:
``` cpp
  int N;
  cout << "N = ";
  cin >> N;
  cout << "fact(" << N << ") = " << fact(N) << endl;

  return 0;
```

[01_Assert/main.cpp](01_Assert/main.cpp)

Плотная упаковка - без выравнивания
[01_sizeof/main.cpp](01_sizeof/main.cpp)

Строка в C
----------
Заканчивается на символ 0.
"ABC" -> 'A', 'B', 'C', код 0
strlen(S) - считает символы в строке.

Генерация правильных скобочных последовательностей
--------------------------------------------------
N = 1
* ()

N = 2
* (())
* ()()

N = 3
* ((()))
* (()())
* ...

``` cpp
// Готовая строка скобок
char* S;
// N - сколько пар скобок надо поставить
int N;

// На текущий момент:
// a - сколько открывающих уже стоит
// b - сколько закрывающих уже стоит
// a + b - текущая позиция в строке
void rec(int a, int b) {
  assert(0 <= a);
  assert(0 <= b);
  assert(a <= N);
  assert(b <= N);
  int k = a + b; // Текущая позиция в строке

  // Если расставили все скобки
  if(a == N && b == N) {
    S[k] = 0;
    cout << S << endl;
    return;
  }

  // Можем ли поставить открывающую?
  // Да, если открывающие ещё не кончились
  if(a < N) {
    S[k] = '('; // Ставим открывающую
    rec(a + 1, b); // Рекурсия
  }

  // Можем ли поставить закрывающую?
  // Если закрывающие ещё остались
  // и открывающих больше чем закрывающих
  if(b < N && a > b) {
    S[k] = ')'; // Ставим закрывающую
    rec(a, b + 1); // Рекурсия
  }
}

void rec() {
  //strcpy(S, "()");
  //rec(1, 1);
  rec(0, 0);
}

int main() {
  //N = 2;
  cout << "N = ";
  cin >> N;
  // Отводим память
  S = new char[N * 2 + 1];
  // Заполняем строчку нулями
  // memset( указатель, чем_заполнять, размер )
  memset(S, 0, N * 2 + 1);

  rec();

  // Очищаем память
  delete[] S;
  return 0;
}
```

[01_task_rec/main.cpp](01_task_rec/main.cpp)

Приведение типов
----------------
``` cpp
  long l = 2133214;
  int a = l; // Неявное приведение типов
  cout << " a = " << a << endl;

  double d = l; // Неявное приведение
  int xx = d;

  // Явное приведение типов
  int* iPtr = (int*)l;

  //iPtr = static_cast<int *>(l);
  //iPtr = dynamic_cast<int *>(l);
  iPtr = reinterpret_cast<int*>(l);
```

[01_types_cast/main.cpp](01_types_cast/main.cpp)

Указатели и ссылки
------------------
* Указатели есть и в C и в C++
* Ссылки есть только в C++
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

Передача параметров в функции
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

Указатели, ссылки и массивы
---------------------------
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

Макросы для отладки
-------------------
``` cpp
#define MY_DEBUG
#ifdef MY_DEBUG
#define SHOW(x) cout << __FILE__ << ":" << __LINE__ << " " << #x << " = " << x << endl;
#else
#define SHOW(x) ;
#endif

#define ASSERT_EQ(a,b) ((a == b) ? (void)0 : _assert(#a" != "#b, __FILE__, __LINE__))
```

[05_DebugMacro/main.cpp](05_DebugMacro/main.cpp)

Объединения - union
-------------------
Два и более объекта занимают одну и ту же ячейку памяти
Пример:
``` cpp
union HH {
  int a;
  int b;
  char c;
};
```

Как выглядит переменная какого-то типа в памяти?

Чтобы абстрагироваться от конкретного типа
используем **typedef**:
typedef Определение_типа Имя_нового_типа;
``` cpp
typedef unsigned int MyType;
```

Объединение:
``` cpp
union InMemoryPresentation {
  MyType field; // Поле нашего типа
  unsigned char b[sizeof(MyType)]; // Массив байт того же размера
};
```

``` cpp
  InMemoryPresentation u;
  u.field = 76; // 'A';

  for(int i = 0; i < sizeof(MyType); ++i) {
    cout << i << ". ";

    for(int b = 7; b >= 0; --b) {
      unsigned char byte = u.b[i];
      // Число:    01101110  00001101
      // Ном.бита: 76543210         1
      // Вырезаем b-ый бит
      cout << ((byte >> b) & 1);
    }

    cout << endl;
  }

```

Для intel-совместимых процессоров
младший байт первый
Intel: little-endian: "остроконечный"
big-endian, дословно: "тупоконечный"
TODO: посмотреть endian.h
[05_union/main.cpp](05_union/main.cpp)

Виды памяти
-----------
``` cpp
int data[100000000]; // Статическая память

void f(int N) { // Стек
  //int localArray[100];
  printf("f(%d)\n", N);
  f(N + 1);
}

int main() {
  int data2[100000]; // Стек
  int i;
  f(1);

  for(i = 0; i < 4000; i++) {
    // Динамическая память
    if(malloc(1000000) == NULL) {
      printf("NULL\n");
      break;
    }

    printf("i = %d\n", i);
  }

  return 0;
}
```

[06_0_static_stack/main.c](06_0_static_stack/main.c)

Динамическая память: malloc / free
----------------------------------
``` cpp
  int* intArray;
  intArray = malloc(100); // Отводим память - 100 байт
  intArray = malloc(70 * sizeof(int)); // 70 целых чисел

  if(intArray == NULL) {
    // Памяти не хватило
    printf("No memory :(");
    return;
  }

  intArray[0] = 10;

  // Освобождение памяти
  free(intArray);
```

[06_malloc_free/main.c](06_malloc_free/main.c)

Динамическая память new / delete
--------------------------------
``` cpp
struct MyStruct {
  int a, b;
  double d;
};

int main() {
  // Отводим динамическую память
  MyStruct* p = new MyStruct;
  // p - указатель на динамическую память

  // Освобождаем динамическую память
  delete p; // new без скобок, delete без скобок

  // "Заводим" массив в динамической памяти
  int* intArray = new int[1000];

  // Освобождаем память
  delete[] intArray; // освобождаем со []

  int** array2D = new int* [100];

  for(int i = 0; i < 100; ++i)
    array2D[i] = new int[100];

  // Используем
  array2D[1][3] = 100;

  for(int i = 0; i < 100; ++i)
    delete[] array2D[i];

  delete[] array2D;

  int* array2Dx[100];

  for(int i = 0; i < 100; ++i)
    array2Dx[i] = new int[100];

  // Используем
  array2Dx[1][3] = 100;

  // Очищаем память
  for(int i = 0; i < 100; ++i)
    delete[] array2Dx[i];

  return 0;
}
```

[07_new_delete/main.cpp](07_new_delete/main.cpp)

Структура данных: очередь
-------------------------
``` cpp
// На базе массива.
//
//    -------------------------------
//  <-|  |  |  |  |  |  |  |  |  |  | <-
//    -------------------------------

const int QUEUE_LEN = 10000;

int data[QUEUE_LEN];

int head = 0; // Индекс первого элемента очереди
int tail = 0; // Индекс первой свободной ячейки очереди

// Добавить элемент в конец очереди
void put(int value) {
  cout << "put(" << value << ")" << endl;
  data[tail++ % QUEUE_LEN] = value;
  // tail++
}

// Получить значение из начала очереди
int get() {
  return data[head++ % QUEUE_LEN];
}

bool isEmpty() {
  return head <= tail;
}

int main() {
  // Положить в очередь
  for(int i = 1; i <= 7; i++)
    put(i);

  // Извлекаем из очереди
  while(!isEmpty())
    cout << "get() -> " << get() << endl;

  return 0;
}
```

[09_queue/main.cpp](09_queue/main.cpp)

Стуктура данных: динамический список
------------------------------------
``` cpp
struct ListElement {
  int value;
  ListElement* next;
};

// Указатель на первый элемент списка
ListElement* root = NULL;

// Добавить в начало списка
void addToBegin(int newValue) {
  cout << endl;
  cout << "addToBegin " << newValue << endl;

  ListElement* newElement = new ListElement;
  newElement->value = newValue;
  newElement->next = root; // NULL;

  root = newElement;
}

// Удалить первый элемент списка
void deleteFirst() {
  // Проверяем что список пуст
  // и если это так, выводим сообщение
  // об ошибке и выходим из функции
  if(root == NULL) {
    cout << "List is empty" << endl;
    return;
  }

  // Запоминаем ссылку на перый элемент
  ListElement* firstElement = root;
  cout << endl;
  cout << "deleteFirst " << firstElement->value << endl;

  // Переместим корень (указатель на начало
  // списка) на второй элемент
  root = firstElement->next;

  // Теперь мы можем удалить первый элемент
  // т.к. ссылка на второй элемент
  // уже сохранена
  delete firstElement;
}

void showList() {
  cout << "List: " << endl;

  for(ListElement* curElement = root;
      curElement != NULL;
      curElement = curElement->next)
    cout << curElement->value << endl;
}

int main() {
  addToBegin(2);
  showList();

  addToBegin(10);
  showList();

  addToBegin(-6);
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  deleteFirst();
  showList();

  return 0;
}
```

[10_list/main.cpp](10_list/main.cpp)

Реализация структуры данных "Список"
------------------------------------
Элемент списка
``` cpp
struct ListElement {
  int value; // Значение элемента списка
  ListElement* next; // Указатель на следующий элемент списка
};
```

Список целиком
``` cpp
struct List {
  ListElement* root; // Указатель на первый элемент

  // Конструктор
  List() {
    cout << "Constructor" << endl;
    root = NULL;
    // Так нельзя (!!!):
    // root->next = NULL;
  }

  // Деструктор - метод, который вызывается при
  // уничтожении объекта
  ~List() {
    cout << "Destructor" << endl;
    ListElement* cur = root;

    while(cur != NULL) {
      cur = cur->next;
      delete root;
      root = cur;
    }
  }

  // Добавить в начало списка
  void addToBegin(int newValue) {
    // Заводим новый элемент списка в динамической памяти
    ListElement* newElement = new ListElement;
    // Записываем в него новое значение
    newElement->value = newValue;
    // (*newElement).value = newValue;
    // Этот элемент должен встать в начало списка,
    // т.е. все остальные элементы будут после него.
    newElement->next = root;
    root = newElement;
  }

  // Показать список
  void show() {
    // Текущий элемент - сначала 1-ый
    int No = 0;

    for(ListElement* cur = root;
        cur != NULL; cur = cur->next)
      cout << ++No << ". " << cur->value << endl;
  }

  // Добавить элемент в конец списка
  void addToEnd(int newValue) {
    if(root == NULL) {
      addToBegin(newValue);
      return;
    }

    // Идём до последнего элемента
    ListElement* cur = root;

    while(cur->next != NULL)
      cur = cur->next;

    //for(ListElement* cur = root;
    //    cur->next != NULL; cur = cur->next)
    //    /* Ничего не надо делать :) */;

    // Создаём новый элемент
    ListElement* newElement = new ListElement;
    newElement->value = newValue;
    newElement->next = NULL;

    // Новый элемент ставим в конец списка
    cur->next = newElement;
  }

  // Удаляем элемент списка по значению
  void deleteByValue(int value) {
    cout << "deleteByValue(" << value << ")" << endl;

    // Если список пуст, то искать в нём нечего
    if(root == NULL)
      return;

    // Если первое значение подходит, то удаляем первый элемент
    if(root->value == value) {
      ListElement* toDelete = root;
      root = root->next;
      delete toDelete;
      return;
    }

    ListElement* cur = root;

    // Ищем значение
    while((cur->next != NULL) &&
          (cur->next->value != value))
      cur = cur->next;

    // Ничего не нашли
    if(cur->next == NULL) {
      cout << value << " not found!" << endl;
      return;
    }

    // Мы нашли элемент, который хотим удалить и это
    ListElement* toDelete = cur->next;
    // Соединяем "концы" цепочки
    cur->next = toDelete->next;

    delete toDelete;
  }

  // Удаляем элемент с заданным индексом
  void deleteAt(int index) {
    cout << "deleteAt(" << index << ")" << endl;

    // Если список пуст, то искать в нём нечего
    if(root == NULL)
      return;

    // Если первое значение подходит, то удаляем первый элемент
    if(index == 0) {
      ListElement* toDelete = root;
      root = root->next;
      delete toDelete;
      return;
    }

    ListElement* cur = root;
    // Ищем значение
    int curIndex = 1;

    while((cur->next != NULL) &&
          (curIndex != index)) {
      cur = cur->next;
      curIndex++;
    }

    // Ничего не нашли
    if(cur->next == NULL) {
      cout << "Index " << index << " not found :)" << endl;
      return;
    }

    // Мы нашли элемент, который хотим удалить и это
    ListElement* toDelete = cur->next;
    // Соединяем "концы" цепочки
    cur->next = toDelete->next;

    delete toDelete;
  }
};
```

Тестирование
``` cpp
  List list; // Создали список
  // List - класс
  // list - объект этого класса
  list.addToBegin(5); // Добавляем 5 в начало
  list.addToBegin(3);
  list.addToBegin(43);
  list.addToBegin(56);
  list.addToEnd(111);
  list.show();

  list.deleteByValue(43);
  list.show();

  list.deleteByValue(102);
  list.show();

  cout << "Delete from begining" << endl;
  list.deleteByValue(56);
  list.show();

  cout << "Delete from end of list" << endl;
  list.deleteByValue(111);
  list.show();

  cout << "-- Delete by index tests --" << endl;
  list.addToBegin(5);
  list.addToEnd(8);
  list.show();
  cout << "Delete from begining" << endl;
  list.deleteAt(0);
  list.show();
  cout << "Delete from end of list" << endl;
  list.deleteAt(2);
  list.show();

  list.deleteAt(2);
  list.show();
```

[11_list/main.cpp](11_list/main.cpp)

﻿ООП - принципы: классы, объекты, прототипы
==========================================

Объектно-ориентированное программирование (ООП, OOP): абстракция, инкапсуляция, наследование и полиморфизм
----------------------------------------------------------------------------------------------------------

Парадигма программирования, в которой основные концепции: **объект** и **класс**.

**Класс** - является описанием ещё не существующей сущности (объекта).
 Фактически он описывает устройство объекта, являясь своего рода "чертежом".
Обычно классы разрабатывают таким образом, чтобы их объекты соответствовали объектам предметной области.

**Объект** - сущность, которой можно посылать сообщения, и которая может на них реагировать,
используя свои данные. **Объект** = **экземпляр класса**.
Данные объекта скрыты от остальной программы. Сокрытие данных называется инкапсуляцией.

**Объект** - экземпляр класса, сущность в адресном пространстве вычислительной системы,
появляющаяся при создании экземпляра класса или копирования прототипа.

**Абстрагирование** - выделение набора значимых характеристик объекта, исключая из рассмотрения незначимые.

**Абстракция** - набор всех характеристик объекта, значимых с точки зрения решаемых задач.

**Инкапсуляция** - свойство системы, позволяющее объединить данные и методы,
работающие с ними в классе, и скрыть детали реализации от пользователя.

**Наследование** - свойство системы, позволяющее описать новый класс
на основе уже существующего с частично или полностью заимствующейся функциональностью (данными и методами).
Класс, от которого производится наследование, называется **базовым**, **родительским** или **суперклассом**.
Новый класс - **потомком**, **наследником** (**дочерним**) или **производным** классом.

**Полиморфизм** - возможность использовать объекты с одинаковым
интерфейсом без передачи информации о типе и внутренней структуре объекта.

**Прототип** - объект-образец, по образу и подобию которого создаются другие объекты.
Объекты-копии могут сохранять связь с родительским объектом,
автоматически наследуя изменения в прототипе; эта особенность определяется в рамках конкретного языка.
В языках с прототипированием (например, JavaScript) вместо классов используются объекты-прототипы.

Объявление класса
-----------------
c++ 11 M_PI не определена в режиме __STRICT_ANSI__
#undef __STRICT_ANSI__
const double M_PI = 4.0 * atan(1);
#include <math.h>
Храним координаты точек как
2 отдельных массива
``` cpp
const int POINTS = 100;
double x[POINTS], y[POINTS];
```

Создали структуру точка
``` cpp
struct Point {
  double x, y;
};

// Массив из точек
Point p[140];
// Обращение к элементам массива:
// p[0].x, p[0].y
```

Класс = данные + методы работы
``` cpp
class Point2D {
 public:
  double x, y;

  void move(double dx, double dy) {
    x += dx;
    y += dy;
  }

  // Повернуть точку относительно
  // начала координат
  // angle - в градусах
  void rotate(double angle) {
    // Перевод из градусов в радианы
    // a - угол в радианах
    double a = angle * M_PI / 180.0;
    double
    nx = x * cos(a) - y * sin(a);
    double
    ny = x * sin(a) + y * cos(a);
    x = nx;
    y = ny;
  }
};
```

Модификаторы доступа: public / private / protected
Создание экземпляра
-------------------
Пример использования:
``` cpp
int main() {
  // Два отдельных массива
  x[0] = 1;
  y[0] = 2;
  // ООП
  p[0].x = 1;
  p[0].y = 2;

  Point p1;
  p1.x = 2;

  Point2D p2;
  p2.x = 2;

  Point2D points[100];
  points[10].x = 10.1;
  points[10].y = 10.3;
  points[0].move(1, 2);
  points[1].rotate(1.2);

  Point2D A, B, C;
  A.move(10, 2);

  /*  x[10] = 1;
    y[20] = 2;
    move_point(10, 10, 2); */

  // Динамическая память
  Point2D* p;
  //...
  p = new Point2D;
  p->x = 2;
  p->move(10, 11);
  (*p).move(1, 2);
  delete p;

  // Создаю массив объектов в
  // динамической памяти
  Point2D* pp = new Point2D[10];

  // Удаляю
  delete[] pp;

  return 0;
}
```

[12_OOP_Simplest/main.cpp](12_OOP_Simplest/main.cpp)

Домашняя работа
---------------
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
    // TODO: реализовать
  }
  // Взять значение с вершины стека
  int pop() {
    // TODO: реализовать
  }
};

// Очередь
struct Queue {
  E* head; // "Голова" - начало очереди
  E* tail; // "Хвост" - конец очереди
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};
  // В конец очереди
  void put(int value) {
    // TODO: реализовать
  }
  // Забрать первый элемент из очереди
  int get() {
    // TODO: реализовать
  }
};
```

Пример использования
``` cpp
  Stack s;
  s.push(2);
  s.push(3);
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  Stack s2;
  s2.push(10);
  s.push(11);
  cout << "11 - " << s.pop() << endl;
  cout << "10 - " << s2.pop() << endl;

  Queue q;
  q.put(10);
  q.put(14);
  q.put(99);
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;
  cout << "99 - " << q.get() << endl;
```

[HomeWork/main.cpp](HomeWork/main.cpp)

Домашнее задание:
Реализовать стек и очередь
Элемент стека и очереди
Стек
Конструктор
Значение поместить на вершину стека
Взять значение с вершины стека
Конструктор
В конец очереди
Забрать первый элемент из очереди
[HomeWork/task.cpp](HomeWork/task.cpp)

Домашнее задание - структуры данных
-----------------------------------
Определить структуру данных "точка"
(на плоскости, с 2-мя координатами
x и y)
Реализовать функции сложения и вычитания.
Как для векторов.
Точка (1, 2) - вектор (1, 2)

Например:
``` cpp
struct Point {
  double x, y;
};
```

Нужно реализовать:
1. Сумму векторов
2. Разность векторов
3. Скалярное произведение векторов
Тестирование вычитания векторов:
``` cpp
  Point c = sub(a, b);
  cout << c.x << " " << c.y << endl;
```

[HomeWork_1/main.cpp](HomeWork_1/main.cpp)


