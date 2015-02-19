/// Список инициализации в конструкторе
/// -----------------------------------
#include <iostream>

using namespace std;

//#define TWO_CONSTRUCTORS

class Point {
  double x, y;
 public:
#ifdef TWO_CONSTRUCTORS
  Point(double _x) :
    x(_x), y(0) {
    x += 10;
  }
#endif
  Point(double _x, double _y = 0) :
    x(_x), y(_y) {
    x += 10;
  }
};

int main() {
  Point(1);

  return 0;
}
