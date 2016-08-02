#include <iostream>

using namespace std;

// __FILE__ - имя файла (исходника)
#define S(x) { cout << __FUNCTION__ << ":" << __LINE__ \
                      << " " << #x << " = " << x << endl; }

// По значению
void f1(int i) {
  S(i);
  i++;
  S(i);
}

// По ссылке - только в C++
void f2(int& i) {
  S(i);
  i++;
  S(i);
}

// По указателю
void f3(int* i) {
  S(*i);
  (*i)++;
  S(*i);
}

int main() {
  int i = 0;
  S(i);
  f1(i);

  S(i);
  f2(i);

  S(i);
  f3(&i);

  S(i);
  return 0;
}
