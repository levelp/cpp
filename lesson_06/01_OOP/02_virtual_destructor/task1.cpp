// Виртуальный деструктор
// ----------------------
#include <stdio.h>
#include <cassert>

// Базовый класс
//-->
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
//<--

// Наследник:
//-->
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
//<--

int main (int argc, char** argp) {
  {
    printf("1\n");
    Test* test = new Test();
    test->init();
    delete test;
    assert(Test::alive == 0);
  }
  {
    printf("2\n");
    Test* test = new Test2();
    /// При выполнении new:
    /// 1. отводится область динамической памяти
    /// 2. вызывается конструктор объекта
    test->init();
    delete test;
    assert(Test::alive == 0);
    assert(Test2::alive2 == 0);
  }
  {
    printf("3\n");
    Test test = Test2();
    test.init();
    assert(Test::alive == 0);
    assert(Test2::alive2 == 0);
  }
  {
    //-->
    Test2 tt;
    tt.init();
    //<--
  }
  return 0;
}
