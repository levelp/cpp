#include <iostream>

using namespace std;

struct Point {
  double x, y;

  // os = cout - типа ostream
  // Point = P
  friend ostream& operator << (ostream& os, Point& p) {
    os << "(" << p.x << "; " << p.y << ") ";
    return os;
  }

  Point operator +(int x) {
    Point res = {this->x + x, this->y};
    return res;
  }
};

int main() {
  Point P = {x: 2.3, y: 3.11};
  Point P2 = P + 10;
  cout << "Point: " << P2 << endl;
  return 0;
}
