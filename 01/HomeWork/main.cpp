//  Решение квадратного уравнения
// -------------------------------
// Задание:
// Написать программу, которое решает квадратное уравнение.
// Пользователь вводит (с клавиатуры) три действительных коэффициента a, b, c.
// Программа выводит все решения уравнения (два, одно), "решений нет",
// если их нет или "бесконечно много решений",
// если подходит любое значение x (a = 0, b = 0, c = 0).
// Обработать все варианты исходных данных.

#include <iostream>
#include <cmath>

using namespace std;

//-->
// Функция должна вывести на экран
void solve_equation(double a, double b, double c) {
  // TODO: реализовать
  // a = 0, b = 0, c = 0
  // 0*x^2 + 0*x + 0 = 0
  // if   return ... double D...
  // cout << "x1 = " <<... ;   cout << "x2 = " << ...;
  // sqrt - извлечение корня
}
//<--

int main() {
  //-->
  // Коэффициенты квадратного уравнения
  double a, b, c;
  // a*x^2 + b*x + c = 0
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "c = ";
  cin >> c;
  cout << endl;

  // Вызов функции решения квадратного уравнения
  solve_equation(a, b, c);
  //<--

  return 0;
}
