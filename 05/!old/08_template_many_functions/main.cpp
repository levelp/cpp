#include <iostream>

using namespace std;

template <class T, int x>
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

  for(int i = 0; i < 1000; ++i) {
    int x = 1;
    //    x = add<int,i>(x);
  }

  return 0;
}
