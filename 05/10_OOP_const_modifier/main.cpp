/// Применение модификатора const в ООП
/// -----------------------------------
#include <iostream>
#include <math.h>

using namespace std;

template <typename T, int n>
class Array {
  T a_[n];
 public:
  Array() {
    for(int i = 0; i < n; i++)
      a_[i] = i + 1;
  }
  T& operator[](int i) {
    return a_[i];
  }
  // Метод не модифицирует состояние объекта
  const T& operator[](int i) const {
    return a_[i];
  }
};

class Point {
 public:
  double x, y;
  double distFrom0() const {
    return sqrt(pow(x, 2) + pow(y, 2));
  }
  void move(const double dx, const double dy) { /*const - нельзя */
    x += dx;
    y += dy;
  }
  static const double classConst;
};

const double Point::classConst = 1.0;

int main() {
  const int value = 0;
  const Array<int, 3> a;
  const int& b = a[0];
  //b++;
  const Point p = {1.0, 2.0};
  // Изменяемый массив
  Array<int, 3> varArray;
  int& aa = varArray[0];
  aa = 10;
  cout << p.distFrom0() << endl;
  //p.move(3.4, 4.5);
  return 0;
}
