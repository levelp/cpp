#include <iostream>

using namespace std;

int main() {
  cout << "== x++ ==" << endl;
  int x = 1;
  cout << "x = " << x << endl;
  int y = x++;
  cout << "y = " << y << " x = " << x << endl;

  cout << "== ++x ==" << endl;
  x = 1;
  cout << "x = " << x << endl;
  y = ++x;
  cout << "y = " << y << " x = " << x << endl;


  return 0;
}
