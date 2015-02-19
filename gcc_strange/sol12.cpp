#include <iostream>
#include <sstream>

using namespace std;


int main() {
  stringstream str;
  int a = 1, b = 2, c = 3, d = 4, e = 5;
  str << a >> b << c >> d << e;
  cout << a << " " << b << " " << c << " " << d << " " << e << endl;
  cout << str.str() << endl;
  return 0;
}