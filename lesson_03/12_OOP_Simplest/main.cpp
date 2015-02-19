// Объявление класса
// -----------------
#include <iostream>
// c++ 11 M_PI не определена в режиме __STRICT_ANSI__
//#undef __STRICT_ANSI__
//const double M_PI = 4.0 * atan(1);
#include <cmath>
//#include <math.h>

// Храним координаты точек как
// 2 отдельных массива
//-->
const int POINTS = 100;
double x[POINTS], y[POINTS];
//<--

// Создали структуру точка
//-->
struct Point {
  double x, y;
};

// Массив из точек
Point p[140];
// Обращение к элементам массива:
// p[0].x, p[0].y
//<--

// Класс = данные + методы работы
//-->
class Point2D {
 public:
  double x, y;

  void move(double dx, double dy) {
    x += dx;
    y += dy;
  }

  // Повернуть точку относительно
  // начала координат
  // angle - в градусах
  void rotate(double angle) {
    // Перевод из градусов в радианы
    // a - угол в радианах
    double a = angle * M_PI / 180.0;
    double
    nx = x * cos(a) - y * sin(a);
    double
    ny = x * sin(a) + y * cos(a);
    x = nx;
    y = ny;
  }
};
//<--

// Модификаторы доступа: public / private / protected

using namespace std;

Point2D pointsStatic[1000];

// Создание экземпляра
// -------------------
// Пример использования:
//-->
int main() {
  // Два отдельных массива
  x[0] = 1;
  y[0] = 2;
  // ООП
  p[0].x = 1;
  p[0].y = 2;

  Point p1;
  p1.x = 2;

  Point2D p2;
  p2.x = 2;

  Point2D points[100];
  points[10].x = 10.1;
  points[10].y = 10.3;
  points[0].move(1, 2);
  points[1].rotate(1.2);

  Point2D A, B, C;
  A.move(10, 2);

  /*  x[10] = 1;
    y[20] = 2;
    move_point(10, 10, 2); */

  // Динамическая память
  Point2D* p;
  //...
  p = new Point2D;
  p->x = 2;
  p->move(10, 11);
  (*p).move(1, 2);
  delete p;

  // Создаю массив объектов в
  // динамической памяти
  Point2D* pp = new Point2D[10];

  // Удаляю
  delete[] pp;

  return 0;
}
//<--
