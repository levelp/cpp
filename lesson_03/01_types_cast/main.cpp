// Приведение типов
// ----------------
#include <iostream>

using namespace std;

#define varName(address)  ((int *)  address)

int main() {
  //-->
  long l = 2133214;
  int a = l; // Неявное приведение типов
  cout << " a = " << a << endl;

  double d = l; // Неявное приведение
  int xx = d;

  // Явное приведение типов
  int* iPtr = (int*)l;

  //iPtr = static_cast<int *>(l);
  //iPtr = dynamic_cast<int *>(l);
  iPtr = reinterpret_cast<int*>(l);
  //<--

  return 0;
}
