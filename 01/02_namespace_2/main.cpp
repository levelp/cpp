#include <iostream>

namespace A {
int i;
}

namespace B {
int i;
}

using namespace std;

int main() {
  A::i = 1;
  B::i = 2;
  return 0;
}
