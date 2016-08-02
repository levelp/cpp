#include <iostream>
#include <cmath>
using namespace std;
#define SHOW(x) cout << #x << " = " << x << endl;

void sq_urav(double a, double b, double c);

const double ZERO = 1e-10;
int main() {
  double a;
  double b;
  double c;
  cout << " a = ";
  cin >> a;
  cout << " b = ";
  cin >> b;
  cout << " c = ";
  cin >> c;
  sq_urav(a, b, c);
  return 0;
}
//----------------------------------------
void sq_urav(double a, double b, double c) {
  if(fabs(a) < ZERO) {
    if(fabs(b) < ZERO) {
      if(fabs(c) < ZERO) {
        cout << "x=any numbers" << endl;
        return;
      }

      cout << "no solution" << endl;
      return;
    }

    double x;
    x = -c / b;
    SHOW(x);
    return;
  }

  double D;
  double x1;
  double x2;
  double real;
  double imagination_1;
  double imagination_2;
  D = pow(b, 2) - 4 * a * c;

  if(D > ZERO) {
    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);
    SHOW(x1);
    SHOW(x2);
    return;
  }

  if(fabs(D) < ZERO) {
    x1 = -b / (2 * a);
    SHOW(x1);
    return;
  }

  if(D < ZERO) {
    real = -b / (2 * a);
    imagination_1 = sqrt(-D) / (2 * a);
    imagination_2 = sqrt(-D) / (2 * a);
    cout << "x1=" << real << "+" << "j" << "*" << imagination_1 << endl;
    cout << "x2=" << real << "-" << "j" << "*" << imagination_2 << endl;
    return;
  }
}
