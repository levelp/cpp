#include <iostream>
#include <math.h>
using namespace std;

struct Vector {
  double X;
  double Y;
};

typedef Vector Vect;

void SHOW(Vect v) {
  cout << "Вектор: " << v.X << " " << v.Y << endl;
};

Vect SumVect(Vect A, Vect B) {
  Vect Sum;
  Sum.X = A.X + B.X;
  Sum.Y = A.Y + B.Y;
  return(Sum);
}

Vect DifVect(Vect A, Vect B) {
  Vect Dif;
  Dif.X = A.X - B.X;
  Dif.Y = A.Y - B.Y;
  return(Dif);
}

Vect MultVect(Vect A, Vect B) {
  Vect Mult;
  Mult.X = A.X * B.X + A.Y * B.Y;
  return(Mult);
}

int main() {
  Vect A = {3.5, 4.1};
  Vect B = {0.3, 6.0};
  SHOW(A);
  SHOW(B);
  cout << "Сумма векторов А и В равна: ";
  SHOW(SumVect(A, B));
  cout << "Разность векторов А и В равна: ";
  SHOW(DifVect(A, B));
  cout << "Скалярное произведение А и В равно: ";
  SHOW(MultVect(A, B));
  return 0;
}
