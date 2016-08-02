#include <iostream>

namespace my_namespace {
int i;
int cout;

namespace inner_namespace {
int b;
}
}
//using namespace std;

int main() {
  my_namespace::i = 10;
  my_namespace::inner_namespace::b = 3;
  //  i = 12;
  my_namespace::cout = 15;

  std::cout << "Hello world!" << std::endl;
  return 0;
}
