#include <iostream>

using namespace std;

#define xx(a) cout << #a << " = " << a << endl;

template<class T>
T add(T a, T b) {
  return a + b;
}

template<>
char add<char>(char a, char b) {
  return a;
}

template<class T, int i>
T add(T a) {
  return a + i;
}

class MyClass {
};

int main() {
  xx(add<int>(1, 2));
  xx(add<char>('A', 'B'));
  // MyClass c1, c2;
  // add<MyClass>(c1,c2);

  cout << add<int, 10>(1) << endl;
  return 0;
}
