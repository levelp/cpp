#include <iostream>

using namespace std;

struct Color {
  unsigned char R, G, B;
};

struct ShapeWithBorder {
  Color color; // Агрегирование
  int border; // Толщина рамки
};

struct Point {
  double x, y;
};

struct PointWithBorder : public ShapeWithBorder,
  public Point {
  // ..
};

// Квадрат - частный случай прямоугольника
struct Square {
  double side1;
};

struct Rectangle : public Square {
  double side2;
};

int main() {
  cout << "Hello world!" << endl;
  return 0;
}
