#include <iostream>

using namespace std;

void f(int d) {
  int bigArray[10000];
  cout << "d = " << d << endl;
  f(d + 1);
}

int main() {
  f(1);
  return 0;
}
