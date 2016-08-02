// Применение цикла for
#include <iostream>

using namespace std;

int main() {
  for(int i = 2; i < 10; i += 2)
    cout << "i = " << i << endl;

  // b < 10 - игнорируется
  for(int a = 2, b = 3; b < 10, a < 20;
      ++a, b += a) {
    cout << "a = " << a <<
         "  b = " << b << endl;
  }

  return 0;
}
