// Функции
#include <iostream>

void myFunction() {
  int a;
  //  ...
}

int myFunction1() {
  return 42;
}

namespace my {
void f();
int cout;
int cin;
}


void my::f() {

}

using namespace std;
//using namespace my;

int main() {
  my::cout = 33;
  cout << "cout = " << my::cout << endl;
  return 0;
}
