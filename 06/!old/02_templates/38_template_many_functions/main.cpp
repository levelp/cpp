#include <iostream>

using namespace std;

template <class T, int x = 5>
T add(T t) {
  return t + x;
}

int main() {
  int x = 1;
  x = add<int, 1>(x);
  x = add<int, 2>(x);
  x = add<int, 3>(x);
  x = add<int, 4>(x);
  x = add<int, 5>(x);

  // В цикле мы не можем создавать реализации шаблона
  // т.к. они создаются на этапе компиляции
  for(int i = 0; i < 1000; ++i) {
    int x = 1;
    // error: no matching function for call to 'add(int&)'|
    x = add<int, i>(x);
  }

  return 0;
}
