//  Решение квадратного уравнения - разбор домашнего задания
// ----------------------------------------------------------
// Задание:
// Написать программу, которое решает квадратное уравнение.
// Пользователь вводит (с клавиатуры) три действительных
// коэффициента a, b, c.
// Программа выводит все решения уравнения (два, одно),
// "решений нет", если их нет или "бесконечно много решений",
// если подходит любое значение x (a = 0, b = 0, c = 0).
// Обработать все варианты исходных данных.
// a*x^2 + b*x + c = 0
#include <iostream>
#include <cmath>

using namespace std; // Пространство имён, чтобы не писать везде std::

const double EPS = 1e-10; // Точность сравнения с нулём

double a, b, c;

// Функция
void answer(double a, double b, double c) {
  double d;

  cout << a << "*x^2 + " << b << "*x + " << c << " = 0 " << std::endl; // Выводим на экран получившуюся формулу

  if  ((fabs(a) <= EPS) & (fabs(b) <= EPS)) {
    if (fabs(c) <= EPS)
      cout << "unlimited answers" << std::endl;
    else
      cout << "numbers not correct" << std::endl;

    return;
  }

  d = b * b - 4 * a * c;

  if (d > EPS) {
    cout << "there are two answers" << std::endl;
    cout << "x1= " << (-b + sqrt(d)) / (2 * a) << " x2= " << (-b - sqrt(d)) / (2 * a) << std::endl;
  } else {
    if (d < 0)
      cout << "there isnt answer" << std::endl;
    else  {
      cout << "threre is only one answer" << std::endl;
      cout << "x= " << (-b) / (2 * a) << std::endl;
      return;
    }

    return;
  }
}

int main() { // Основная функция
  cout << "a*x^2 + b*x + c = 0 " << std::endl; // Выводим на экран
  cout << " a= " ;
  cin  >> a; // Вводим a c клавиатуры
  cout << " b= " ;
  cin  >> b; // Вводим b с клавиатуры
  cout << " c= " ;
  cin  >> c; // Вводим c с клавиатуры


  answer(a, b, c);

  return 0; // Программа завершилась удачно, 0 - код возврата
}
