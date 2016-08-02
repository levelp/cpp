#include <iostream>

using namespace std;

// Макрос S(x) - определение макроса с параметром x
//  #x - вставить x как строчку
//  x - вставить x как значение
#define S(x) cout << __LINE__ << ": " << #x << " = " << x << endl;

struct A {
  virtual void f() {}
};
struct B : public A {
};
struct X : public A {
};

int main() {
  B* b = new B;
  // Приведения в стиле C
  S((A*)b);
  S((X*)b);
  // == Приведения в стиле C++ ==
  // Анализ на этапе компиляции
  S(static_cast<A*>(b));
  // Не компилируется так как X не предок B
  //S(static_cast<X*>(b));
  // Анализ на этапе выполнения
  S(dynamic_cast<A*>(b));
  // Возвращает 0 так как X не предок B
  S(dynamic_cast<X*>(b));
  // Приводим тип не анализируя
  S(reinterpret_cast<X*>(b));
  S(reinterpret_cast<A*>(b));

  return 0;
}

