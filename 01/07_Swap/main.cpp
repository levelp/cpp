#include <iostream>

using namespace std;

int main() {
  int a = 12321, b = 352;

  cout << "a = " << a << "  b = " << b << endl;

  // a = a ^ b
  // b = b ^ a
  // a = a ^ b
  a ^= b ^= a ^= b;

  cout << "a = " << a << "  b = " << b << endl;
  return 0;
}
