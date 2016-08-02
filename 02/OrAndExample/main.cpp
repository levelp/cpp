#include <iostream>

using namespace std;

int main() {
  for(int a = 0; a <= 1; ++a)
    for(int b = 0; b <= 1; ++b) {
      cout << a << " || " << b << " = " << (a || b) << "  ";
      cout << a << " or " << b << " = " << (a or b) << endl;
      cout << a << " && " << b << " = " << (a && b) << "  ";
      cout << a << " and " << b << " = " << (a and b) << endl;
    }

  return 0;
}
