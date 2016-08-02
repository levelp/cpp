#include <iostream>
#include <math.h>

using namespace std;

double const EPS = 1e-10;

int main() {
  float a = 0, b = 0, c = 0;
  cout << "Решение квадратного уравнения" << endl;
  cout << "Введите коэффициент a:" << endl;
  cin >> a;
  cout << "Введите коэффициент b:" << endl;
  cin >> b;
  cout << "Введите коэффициент c:" << endl;
  cin >> c;

  float d = b * b - 4 * a * c;

  if (d < -EPS)
    cout << "Уравнение не имеет корней" << endl;
  else if (fabs(d) < EPS)
    cout << "Уравнение имеет один корень: " << -b / (2 * a) << endl ;
  else {
    cout << "Уравнение имеет два корня: " << endl;
    cout << "Корень 1: " << (-b - sqrt(d)) / (2 * a) << endl;
    cout << "Корень 2: " << (-b + sqrt(d)) / (2 * a) << endl;
  }

  return 0;
}