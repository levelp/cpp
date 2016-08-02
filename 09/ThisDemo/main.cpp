#include <iostream>

using namespace std;

// this - это указатель на текущий
// экземпляр класса (на объект)

// Точка
class Point {
  // Поля
  double x, y;
 public:
  Point(double x, double y) : x(x) {
    // Используем this для явного указания
    // что это поле класса
    this->x = x;
    this->y = y;
    Point::x = x;
    this->f();
  }
  void f() {
    /*...что-то */
  }
};

class Line {
  Point p1, p2;
  int i;
  //...
  double d;
};

int main(int argc, char* argv[]) {
  return 0;
}

