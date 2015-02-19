#include <vector>
#include <iostream>

using namespace std;

int f() {
  int n;
  cin >> n;
  return n;
}

int main() {
  cout << f() << " " << f();
  return 0;
}