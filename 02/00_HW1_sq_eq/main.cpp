// Квадратное уравнение
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main() {
  double a, b, c, D;
  cout << "Enter a= ";
  cin >> a;
  cout << "Enter b= ";
  cin >> b;
  cout << "Enter c= ";
  cin >> c;
  D = pow(b, 2) - 4 * a * c;
  cout << "Discriminant D = " << D << endl;

  if (D > 0) {
    cout << "D > 0. We have two roots" << endl;
    double x1, x2;
    x1 = (-b + sqrt (D)) / 2 * a;
    cout << "x1= " << x1 << endl;
    x2 = (-b - sqrt (D)) / 2 * a;
    cout << "x2= " << x2 << endl;
  } else if (fabs(D) < 1e-10) {
    cout << "D = 0. We have one root" << endl;
    double x1;
    x1 = (-b + sqrt (D)) / 2 * a;
    cout << "x1= " << x1 << endl;
  } else
    cout << "D < 0. No roots" << endl;

  return 0;
}


