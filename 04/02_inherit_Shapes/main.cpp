#include <iostream>

using namespace std;

struct Shape {
  char name[100]; // У всех фигур есть имя
  int color; // Цвет фигуры
  void method() {
    cout << "method" << endl;
  }
};

class Point : public Shape {
 public:
  double x, y;
};

class Circle : public Shape {
 public:
  Point center; // Центр
  double radius; // Радиус
};

class Square : public Shape {
 public:
  Point p1, p2, p3, p4;
};

int main() {
  Shape shape;
  Square square;
  Circle circle;
  circle.name = "Окружность";
  Point point;
  point.name = "Точка 1";
  return 0;
}
