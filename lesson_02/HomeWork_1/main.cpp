#include <iostream>
#include <math.h>

using namespace std;

struct Point {
  double x, y;
};

double sqr(double x) {
  return x * x;
}

double dist(Point a, Point b) {
  return
    sqrt(sqr(a.x - b.x) +
         sqr(a.y - b.y));
}

typedef Point Vector;

// Сумма
Point sum(Vector A, Vector B) {
  // TODO: Реализовать
  Point R;
  R.x = A.x + B.x;
  R.y = A.y + B.y;
  return R;
}

// Разность
Point sub(Vector A, Vector B) {
  // TODO: Реализовать
  Point R;
  R.x = A.x - B.x;
  R.y = A.y - B.y;
  return R;
}

// Скалярное произведение векторов
double dotProduct(Vector A, Vector B) {
  // TODO: Реализовать
  return A.x * B.x + A.y * B.y;
}

int main() {
  Point a = {1.2, 1.3},
        b = {10.2, 3.3};
  cout << dist(a, b) << endl;

  // Тестирование
  Point c = sub(a, b);

  return 0;
}
