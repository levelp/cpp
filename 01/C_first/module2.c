#include <ostream>
#include "module2.h"
#include <windows.h>

namespace std {
extern ostream cout;
}

void f() {
  std::cout << "f()" << std::endl;
}
