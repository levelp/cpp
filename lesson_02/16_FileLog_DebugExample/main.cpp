#include <iostream>
#include <stdio.h>

using namespace std;

int globalVar = 4;

void f(int i) {
  cout << "i = " << i << endl;

  if(i > 0)
    f(i - 1);
}

int main() {
  freopen("log.txt", "w", stdout);
  freopen("log_err.txt", "w", stderr);

  cout << "Program started" << endl;
  int a = 2, b = 3;
  a += b;
  cout << "Hello world!" << endl;
  f(10);
  return 0;
}
