#include <iostream>
#include <string>

using namespace std;

const int defaultColor = 255;
const int defaultBorder = 1;

// Фигура
class Shape {
  // Название фигуры
  string name;
  // Цвет фигуры
  int color;
  // Количество точек
  int numOfPoints;
  // Толщина границы (бордюра)
  int border;
 protected:
  // "ABC\0"
  Shape(string name1, int n,
        int c = defaultColor,
        int b = defaultBorder) {
    name = name1;
    color = c;
    numOfPoints = n;
    border = b;
  }
};

// Точка
class Point : public Shape {
  double x, y;
 public:
  Point(string name, double x, double y) :
    Shape(name, 1),
    x(x), y(y) {
    cout << "(" << x << ";" << y << ")"
         << endl;
  }
};

// Квадрат
class Square : public Shape {
  // Левый правый угол
  Point leftUpperCorner;
  // Сторона
  double side;
 public:
  Square(double x, double y, double side) :
    Shape("Square", 4),
    leftUpperCorner("corner", x, y),
    side(side) {
    cout << "Square:" << endl;
    cout << x << ";" << y << endl;
    cout << x + side << ";" << y << endl;
    cout << x + side << ";" << y + side << endl;
    cout << x << ";" << y + side << endl;
  }
};

// Окружность
class Circle : public Shape {
  // Координаты центра
  Point center;
  // Радиус окружности
  double radius;
 public:
  Circle(double x, double y, double radius) :
    Shape("Circle", -1),
    center("center", x, y),
    radius(radius) {
    cout << "Circle: " << x << " " << y
         << "  " << radius << endl;
  }
};

int main() {
  Point p("p", 1.2, 3.2);
  //  Shape s("222",3,3,3);
  Square s(1, 3, 10);
  Circle c(1, 2, 3);
  return 0;
}
