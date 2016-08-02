#include <iostream>

using namespace std;

int main() {
  int a = 2;
  a++;
  ++a; // a = 4

  int b = ++a;
  cout << "a = " << a << "  b = " << b << endl;

  int c = b--;
  cout << "b = " << b << "  c = " << c << endl;

  return 0;
}
