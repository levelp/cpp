#include <iostream>

using namespace std;

int main() {
  // ax + b = 0
  // ax = -b
  // x = -b/a
  // Ввести a и b
  // Вычислить и вывести x
  double a, b, x;
  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;
  x = -b / a;
  // endl - end line
  cout << "x = " << x << endl;
  double check = a * x + b;
  cout << "check = " << check << endl;

  return 0;
}
