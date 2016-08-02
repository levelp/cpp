#include <iostream>
#include <math.h>

using namespace std;

// Точка
struct Point {
  double x, y;
  Point(double xx, double yy) :
    x(xx), y(yy) {
    cout << "Point " << xx << " " << yy << endl;
  }
  //Point(){};
};

// Отрезок
struct Line {
  Point p1, p2;
  Line(double x1, double y1, double x2, double y2)
    : p2(x2, y2), p1(x1, y1) {
    cout << "Line" << endl;
    //p1.x = x1;  p1.y = y1;
    //p2.x = x2;  p2.y = y2;
  }
  // Длина отрезка
  double length() {
    return sqrt(
             pow(p1.x - p2.x, 2) +
             pow(p1.y - p2.y, 2)
           );
  }
};

int main() {
  //Point p(2,3);
  //cout << "p.x = " << p.x << "  p.y = " << p.y << endl;
  Line abracadabra(1, 1, 2, 2);
  cout << "Length of line: " <<
       abracadabra.length() << endl;
  return 0;
}
