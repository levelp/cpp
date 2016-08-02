#include <iostream>
#include <math.h>

const double EPS = 1e-9;

using namespace std;

int main() {
  double a, b, c, d, x1, x2;

  cout << "ax^2 + bx + c = 0;" << endl;

  cout << "Enter a: ";
  cin >> a;

  cout << "Enter b: ";
  cin >> b;

  cout << "Enter c: ";
  cin >> c;

  if (a != 0) {
    d = (b * b) - (4 * a * c);
    cout << "D = " << d << ";" << endl;

    if (d < EPS)
      cout << "No solutions";
    else if (d > EPS) {
      x1 = (-b - sqrt(d)) / (2 * a);
      x2 = (-b + sqrt(d)) / (2 * a);
      cout << "x1 = " << x1 << ";" << endl;
      cout << "x2 = " << x2 << ";";
    } else {
      x1 = (-b) / (2 * a);
      cout << "x = " << x1 << ";";
    }
  } else {
    /* Линейное уравнение */
    x1 = -c / b;
    cout << "x1 = " << x1 << ";";
    /* TODO: когда a = 0 и b = 0 тоже можно обработать */
  }

  return 0;
}
