#include <iostream> // cin / cout
#include <clocale> // setlocale
#include <math.h> // Библиотека с математическими функциями

using namespace std;

int main() {
  // Win1251 и в исходном тексте и в консоли
  setlocale(LC_ALL, "Russian");

  cout << "Решение квадратного уравнения" << endl;
  cout << "ax^2 + bx + c = 0" << endl;

  // Ввод коэффициентов уравнения
  cout << "Ввод коэффициентов уравнения:" << endl;
  double a, b, c;
  cout << "Введите a = ";
  cin >> a;
  cout << "Введите b = ";
  cin >> b;
  cout << "Введите c = ";
  cin >> c;

  // Вычисление дискриминанта
  double D = pow(b, 2) - 4 * a * c;

  // Вычисление и вывод ответа(ов) x
  const double eps = 1e-15; // 10 в минус 15 степени

  if(D >= eps) {
    cout << "Два корня: ";
    double x1 = (-b + sqrt(D)) / (2 * a);
    cout << " x1 = " << x1;
    double x2 = (-b - sqrt(D)) / (2 * a);
    cout << " x2 = " << x2;
    cout << endl;
    cout << "Проверка1: " << (fabs(a * x1 * x1 + b * x1 + c) < eps) << endl;
    cout << "Проверка2: " << (fabs(a * x2 * x2 + b * x2 + c) < eps) << endl;
  } else if(fabs(D) < eps) {
    double x = -b / (2 * a);
    cout << "Один корень: x = " << x << endl;
    cout << "Проверка: " << (fabs(a * x * x + b * x + c) < eps) << endl;
  } else
    cout << "Уравнение не имеет корней" << endl;

  return 0;
}
