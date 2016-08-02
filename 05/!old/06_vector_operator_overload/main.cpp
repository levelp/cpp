#include <iostream>

using namespace std;

// struct   = class
// (public)   (private)
struct Vector {
  Vector(double x, double y) :
    x(x), y(y) {
  }
  Vector operator+(Vector r) {
    Vector res(x + r.x, y + r.y);
    return res;
  }
  Vector minus(Vector r) {
    Vector res(x - r.x, y - r.y);
    return res;
  }
  Vector operator-(Vector r) {
    Vector res(x - r.x, y - r.y);
    return res;
  }
  Vector operator<<(int x) {
    Vector res(this->x - x, y - x);
    return res;
  }
 private:
  double x, y;

  friend ostream& operator<<(ostream&, Vector);
};

ostream& operator<<(ostream& of, Vector v) {
  of << "(" << v.x << "; " << v.y << ")";
  return of;
}

int main() {
  Vector a(1, 2), b(2, 4);
  Vector c = a + b;
  Vector
  d = a.minus(b);
  d = a - b;
  d = a << 2;
  //cout << c.x << " " << c.y << endl;
  cout << c << endl;

  return 0;
}
