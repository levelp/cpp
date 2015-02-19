#include <iostream>

using namespace std;

int main() {
  double x = 10 / 2 * 5;
  cout << "x = " << x << endl; // 25
  double x2 = 10 / (2 * 5);
  cout << "x2 = " << x2 << endl; // 1
  cout << 10.0 / 2.0 / 5.0 << endl;

  int i = 1;

  for(int i = 1, j = 2; i < 10; i++, j += 2) {

    cout << "  i = " << i <<
         "  j = " << j << endl;
  }

  return 0;
}
