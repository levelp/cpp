/// Домашнее задание - структуры данных
/// -----------------------------------
/// Определить структуру данных "точка"
/// (на плоскости, с 2-мя координатами
///  x и y)
/// Реализовать функции сложения и вычитания.
/// Как для векторов.
/// Точка (1, 2) - вектор (1, 2)
///
#include <iostream>
#include <math.h>

using namespace std;

/// Например:
///-->
struct Vector {
  double x, y;
};
///<--

double sqr(double x) {
  return x * x;
}

/// Определяем Точку как Вектор
typedef Vector Point;

/// Растояние между 2-мя точками
double dist(Point a, Point b) {
  return
    sqrt(sqr(a.x - b.x) +
         sqr(a.y - b.y));
}

/// Нужно реализовать:
/// 1. Сумму векторов
Vector sum(Vector A, Vector B) {
  Vector R;
  R.x = A.x + B.x;
  R.y = A.y + B.y;
  return R;
}

/// 2. Разность векторов
Vector sub(Vector A, Vector B) {
  Vector R = { A.x - B.x, A.y - B.y };
  return R;
}

Point sub2(Vector A, Vector B) {
  return Point { A.x - B.x, A.y - B.y };
}

/// 3. Скалярное произведение векторов
double dotProduct(Vector A, Vector B) {
  return A.x * B.x + A.y * B.y;
}

int main() {
  Point a = {1.2, 1.3},
        b = {10.2, 3.3};
  cout << dist(a, b) << endl;

  /// Тестирование вычитания векторов:
  ///-->
  Point c = sub(a, b);
  cout << c.x << " " << c.y << endl;
  Point c2 = sub2(a, b);
  cout << c2.x << " " << c2.y << endl;
  ///<--

  return 0;
}
