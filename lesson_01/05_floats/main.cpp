// Пример на погрешность вычислений в вещественных числах
#include <iostream>
#include <math.h>
#include <cfloat>

using namespace std;

int main() {
  float f = 0.023; // 4 байта

  long double ld = 0.12; // 10 байт

  double a = 0.1; // 8 байт
  double b = 0.9;
  double c = 1;

  // fabs - взять по модулю
  if((int)(a + b) == (int)c) {
    // DBL_EPSILON * 1000
    //if( fabs((a + b) - c) < 1e-9){
    cout << a << " + " << b << " == " << c << endl;
  } else {
    cout << a << " + " << b << " != " << c << endl;
    cout << a + b << " " << c << endl;
    cout << c - (a + b) << endl;
  }

  return 0;
}
