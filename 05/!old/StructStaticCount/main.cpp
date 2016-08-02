#include <iostream>

using namespace std;

struct A {
  static int cnt; // static - принадлежит ко всему классу
  int id;
  A(const char* name) {
    ++cnt; // cnt++;
    id = cnt;
    cout << name << " #" << id << endl;
  }
};

int A::cnt = 0;

int main() {
  A a("a"), b("b");
  // ...
  {

    A d("d"), e("e");
  }
  cout << b.cnt << endl;
  return 0;
}
