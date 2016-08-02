#include <iostream>

using namespace std;

void f(int i) {
  i++;
  cout << "i = " << i << endl;
}

void f2(int& i) {
  i++;
  cout << "i = " << i << endl;
}

void f3(int* i) {
  (*i)++;
  cout << "i = " << *i << endl;
}

int main() {
  int i = 3;
  f(i);
  cout << "i = " << i << endl;
  f2(i);
  cout << "i = " << i << endl;
  f3(&i);
  cout << "i = " << i << endl;
  return 0;
}
