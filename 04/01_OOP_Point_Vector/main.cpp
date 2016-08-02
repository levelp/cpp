#include <iostream>
#include <cmath> // math.h

#define SHOW(x) cout << #x << " = " << x << endl;

using namespace std;

// Класс "Точка"
class Point {
 public:
  double x, y; // Координаты точки
  // Методы:
  // Передвинуть точку
  void move(double dx, double dy) {
    x += dx;
    y += dy;
  }
};

ostream& operator <<(ostream& os, Point& p) {
  os << "(" << p.x << ";" << p.y << ")";
  return os;
}

// Расстояние между 2-мя точками
double distance(Point A, Point B) {
  return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

// Класс "Отрезок"
class Segment {
 public:
  Point A, B; // Концы отрезка
  // Длина отрезка
  double length() {
    return distance(A, B);
  }
  // Передвинуть отрезок
  void move(double dx, double dy) {
    // Для этого двигаем 2 точки
    A.move(dx, dy);
    B.move(dx, dy);
  }
};

int main() {
  Point p = {1.1, 2.0};
  cout << "p = " << p << endl;
  SHOW(p);
  SHOW(p.x);
  SHOW(p.y);
  p.move(2, 0);
  SHOW(p.x);
  SHOW(p.y);
  Point p2 = {3, 4};
  SHOW(distance(p, p2));

  return 0;
}
