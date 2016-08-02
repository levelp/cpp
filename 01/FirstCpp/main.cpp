#include <iostream>

namespace a {
int x;
}

namespace b {
int x;
}

using namespace a;
using namespace b;

int main() {
  a::x = 1;
  b::x = 2;
  //x = 10;
  std::cout << "Hello world!" << std::endl;
  // endl - EndLine
  // Windows - CR LF  13 10
  // Linux - LF - 10
  // MacOS - CR - 13
  return 0;
}

