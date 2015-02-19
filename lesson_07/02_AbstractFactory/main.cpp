/// Создание класса в C++ по его идентификатору
/// -------------------------------------------
#include <QCoreApplication>
#include <iostream>
#include <typeinfo>

using namespace std;

/// Иерархия классов
///-->
struct MyClass {
  virtual void show() = 0;
};

struct MyClass1 : public MyClass {
  MyClass1() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
  void show() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

struct MyClass2 : public MyClass {
  MyClass2() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
  void show() {
    cout << __PRETTY_FUNCTION__ << endl;
  }
};

///<--

/// Первый способ
/// -------------
/// Функция - фабрика
///-->
MyClass* CreateInstance(int id) {
  switch(id) {
    case 1:
      return new MyClass1();

    case 2:
      return new MyClass2();

    default:
      cout << "TODO: " << __FUNCTION__ << " for " << id << endl;
  }

  throw id;
}
///<--

void v1() {
  /// Использование
  ///-->
  MyClass* a = CreateInstance(1);
  a->show();
  MyClass* b = CreateInstance(2);
  b->show();
  ///<--
}

/// Второй способ
/// -------------
/// Спецификация шаблона для определённых значений
///-->
template<int id>
MyClass* Create() {
  throw "Need specialization";
}

template<>
MyClass* Create<1>() {
  return new MyClass1();
}

template<>
MyClass* Create<2>() {
  return new MyClass2();
}
///<--

/// Использование
void v2() {
  ///-->
  MyClass* a1 = Create<1>(), *a2 = Create<2>();
  a1->show();
  a2->show();
  ///<--
}

int main() {
  v1();
  v2();
  return 0;
}
