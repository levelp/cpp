<!-- doc.py -->
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
[01_copy_contructor/main.cpp](01_copy_contructor/main.cpp)

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

[02_virtual_destructor/task1.cpp](02_virtual_destructor/task1.cpp)

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

[03_iostream_files/a_sum.cpp](03_iostream_files/a_sum.cpp)

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
[03_iostream_files/main.cpp](03_iostream_files/main.cpp)

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

[03_iostream_files/redirect_output.cpp](03_iostream_files/redirect_output.cpp)

