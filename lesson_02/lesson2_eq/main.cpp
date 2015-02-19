#include <iostream>

using namespace std;

int main() {
  int a = 15, b = 23;
  cout << "a = " << a << " b = " << b << endl;

  b -= (a = -a + (b += a));

  //a^=b^=a^=b; // XOR - исключающее или

  int f = 1;
  int g = ++f + ++f + ++f;
  //int g = f++ + f++ + f++;
  //g = f++;
  cout << "f = " << f << " g = " << g << endl;

  //cout << "a = " << a << " b = " << b << endl;
  return 0;
}
