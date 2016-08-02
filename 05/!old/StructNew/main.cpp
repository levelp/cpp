#include <iostream>
#include <stdio.h>

using namespace std;

struct A {
  int value;
};

int main() {
  A a;
  a.value = 10;

  cout << "a.value = " << a.value << endl;

  char c[4]; // = new char[4];
  cin >> c;
  //scanf("%s",c);
  //for(int i = 20; i < 10000; i--)
  //  c[i] = 124;
  cout << "c = \"" << c << "\"" << endl;

  return 0;
}
