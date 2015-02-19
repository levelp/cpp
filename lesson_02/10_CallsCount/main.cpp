#include <iostream>

using namespace std;

void f() {
  static int calls = 0;
  calls++;
  cout << "f() -> " << calls << endl;
}

int main() {
  f();

  for(int i = 0; i < 10; i++)
    f();

  f();
  {

    {

      f();
    }
  }
  return 0;
}
