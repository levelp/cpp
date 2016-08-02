#include <iostream>
#include <cstring>

using namespace std;

#define SHOW(x) cout << #x << " = " << x << endl;

struct S {
  char* str;
  int value;
  S() {}
  // Конструктор копирования:
  // ИмяКласса(ИмяКласса& чтоКопируем)
  S(S& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
    value = s.value;
  }
};

int main() {
  char buf[] = "Hello!";
  S a;
  a.str = buf;
  a.value = 42;
  S b1(a);
  S b = a;
  SHOW(a.str);
  SHOW(b.str);
  SHOW(a.value);
  SHOW(b.value);
  SHOW(b1.value);
  b.str[0] = '#';
  SHOW((int)a.str)
  SHOW((int)b.str)
  SHOW(a.str);
  SHOW(b.str);

  return 0;
}
