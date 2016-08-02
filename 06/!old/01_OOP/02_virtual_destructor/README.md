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

[task1.cpp](task1.cpp)

