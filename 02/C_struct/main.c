// Структуры в чистом C
#include <stdio.h>
#include <stdlib.h>

struct Point {
  int x, y;
  char name[20];
};

typedef struct Point Point2D;

void show(struct Point p) {
  printf("(%d;%d) ", p.x, p.y);
  // cout << "(" << p.x << ";" << p.y << ") ";
}

int main() {
  Point2D p1, p2;
  p1.x = 2;
  p1.y = 10;
  p2.x = 5;
  p2.y = 9;
  show(p1);
  show(p2);
  return 0;
}
