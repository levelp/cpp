#include <iostream>
#include "module1.h"
#include "module2.h"

using namespace std;

int main() {
  cout << "=== module1 ===" << endl;
  v1();
  show1();
  show2();

  cout << "=== module2 ===" << endl;
  v2();
  show1();
  show2();

  return 0;
}


