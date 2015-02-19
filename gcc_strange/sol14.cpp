#include <iostream>

using namespace std;

int main() {
  int a, b;
  a = 1;
  b = 2;
  cout << (a, b = a, b) << endl;
  return 0;
}