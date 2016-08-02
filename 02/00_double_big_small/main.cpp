#include <iostream>

using namespace std;

#define SHOW(x) cout << #x << " = " << x << endl;

int main() {
  const double BIG = 1e+20;
  double small = 1.0;
  SHOW(BIG + small - BIG);
  SHOW(BIG - BIG + small);
  return 0;
}
