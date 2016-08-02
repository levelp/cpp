#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point2D {
  double x, y;
};

typedef struct Point2D Point;

double dist(Point A, Point B) {
  return sqrt( pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

int main() {
  Point p1, p2 = {3.2, 4.3};
  p1.x = 10.0;
  p1.y = 2.3;
  printf("p1.x = %lf  p1.y = %lf\n", p1.x, p1.y);
  printf("p2.x = %lf  p2.y = %lf\n", p2.x, p2.y);
  printf("dist(p1,p2) = %lf\n", dist(p1, p2));
  return 0;
}
