// Минимум из двух чисел при помощи оператора if
#include <iostream>

using namespace std;

int main() {
  int a = 2, b = 10;

  if(a < b/*-1*/)
    cout << "min = " << a << endl;
  else
    cout << "min = " << b << endl;

  return 0;
}
