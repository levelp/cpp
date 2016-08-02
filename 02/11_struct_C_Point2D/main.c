#include <stdio.h>
#include <stdlib.h>
// Математические функции
#include <math.h>

typedef struct {
  int x, y; // 2 координаты
} P;

// typedef определение_типа название_типа;
typedef long long ll;
//typedef struct Point P;

// Расстояние между двумя точками
double dist(P a, P b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
  ll x = 10;

  P P1 = {0, 0}, P2 = {2, 1}, P3 = {10, -5};

  printf("P3.x = %d  P3.y = %d\n", P3.x, P3.y);

  printf("dist(P1,P2) = %lf\n", dist(P1, P2));

  return 0;
}
