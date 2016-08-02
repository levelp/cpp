// ООП, модификатор const
// const: общий смысл - "нельзя менять"
#include <iostream>

using namespace std;

// C: struct, class - нет
// C++: struct - public, class - private
struct Point {
  double x, y;
  const int id;
  static int count;
  static int showed;
  Point(double x, double y) : id(++count), x(x), y(y) {
  }
  void show() const {
    showed++;
    cout << showed << " (" << x << "; " << y << ")" << endl;
  }
  void move(double dx, double dy) {
    x += dx;
    y += dy;
  }
  const Point moved(double dx, double dy) const {
    Point p(x + dx, y + dy);
    return p;
  }
  void xx(Point& p) const {
    p.x++;
    //x++;
  }
};

int Point::count = 0;
int Point::showed = 0;

const int i = 10;

const Point p(2, 3);
Point p2(3, 4);

const Point p3 = p.moved(10, 2);

void print(const char* message) {
  //message[2] = 'A';
  cout << message << endl;
}

int main() {
  // increment of read-only variable 'i'|
  //i++;
  p.show(); // Можно
  // p.move(2,3); // Нельзя
  p2.move(2, 3);
  print("TEST");
  p3.show();
  p3.xx(p2);
  return 0;
}

