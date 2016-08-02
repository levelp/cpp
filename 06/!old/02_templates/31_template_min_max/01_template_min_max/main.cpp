// Базовое применение шаблонов
#include <iostream>
#include <cassert>
#include <string>

#define SHOW(x) { cout << #x << " = " << x << endl; }

using namespace std;

// Без использования шаблонов
int min(int a, int b);

int min(int a, int b) {
  cout << "min int" << endl;
  return (a < b) ? a : b;
}

double min(double a, double b);

double min(double a, double b) {
  cout << "min double" << endl;
  return (a < b) ? a : b;
}

// T - параметр шаблона
template <class T>
T min(T a, T b) {
  cout << "min generic" << endl;
  return (a < b) ? a : b;
}

template <class T>
T max(T a, T b) {
  return (a > b) ? a : b;
}

// Шаблонная функция
template <class T>
T findMax(T* a, size_t size) { // size_t - тип, который компилятор использует для индексации массивов
  // Предусловия
  assert(size >= 1); //, "Пустой массив передавать нельзя!");
  T curMax = a[0];

  for(size_t i = 1; i < size; i++)
    if(a[i] > curMax)
      curMax = a[i];

  return curMax;
}

// Параметры шаблонов:
//   типы: class G / typename T
//   любой из типов: int I

// Функция, добавляющая константу
template <class T, int A>
T add(T value) {
  return value + A;
}

struct Point {
  double x, y;
  int operator < (Point& p) {
    return x < p.x;
  }
  friend ostream& operator <<(ostream& os, const Point& p) {
    os << "(" << p.x << "; " << p.y << ") ";
    return os;
  }
};

int main() {
  //assert(2*2 == 5);
  SHOW(min(2, 3));
  SHOW(min(2.1, 2.3));
  SHOW(::min(string("a"), string("test")));
  SHOW(::min<char>('A', 'D'));
  Point p1 = {1, 2}, p2 = {3, 4};
  SHOW(::min(p1, p2));

  double x[] = {5.2, 10.10, 13.5, 11.1};
  SHOW(findMax(x, 4));

  int c[] = {5, 6, 4, 2, 3};
  SHOW(findMax(c, 5));

  char d[] = {'x', 'f', 'B', 'K', 'L' };
  SHOW(findMax(d, 5));

  string s[] = {"hi", "test", "aa", "bb", "test2"};
  SHOW(findMax(s, 5));

  int h[3][3] = {
    { 1, 2,  3 },
    { 4, 16, 5 },
    { 3, 8,  6 },
  };

  SHOW(findMax((int*)h, 9));
}
