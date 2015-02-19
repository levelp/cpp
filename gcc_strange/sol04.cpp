#include <iostream>
#include <memory.h>

using namespace std;

int main() {
  int* a = new int[3];
  int* b = new int[3];

  a[0] = 0;
  a[1] = 1;
  a[2] = 2;

  b[0] = 3;
  b[1] = 4;
  b[2] = 5;

  memcpy(b, a, sizeof(a)); // Вычисляется размер int, а не всего массива
  cout << b[0] << " " << b[1] << " " << b[2] << endl;
  return 0;
}
