#include <QCoreApplication>
#include <iostream> // cout
#include <string> // string
#include <map> // map
#include <cmath>
#include <cassert>

using namespace std;

struct Point {
  double x, y;
  Point() {};
  Point(double x, double y) : x(x), y(y) {
    cout << "Point: " << x << " " << y << endl;
  }
};

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  Point p(1.1, 2.1);

  map<string, Point> triangle;
  triangle.insert(pair<string, Point>("A", Point(1, 2)));
  triangle["B"] = Point(3, 1);
  triangle["C"] = Point(-2, 2);


  Point A = triangle["A"];
  assert(fabs(A.x - 1.0) < 0.001);

  return 0;// a.exec();
}
