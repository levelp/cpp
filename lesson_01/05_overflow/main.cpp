#include <iostream>

using namespace std;

#define SHOW(x) cout << #x << " = " << x << endl;

int main() {
  long long l;
  l = 4294967295U + 1;
  SHOW(l)

  long long l2 = 4294967295ULL + 1;
  SHOW(l2)

  long long l3 = 4294967295U;
  l3 = l3 + 1;
  SHOW(l3)

  SHOW(1 + 2 - 3 * 2)

  return 0;
}
