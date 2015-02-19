#include <iostream>
#include <assert.h>

using namespace std;

typedef long long ll;

// НОД - Наибольший общий делитель
ll GCD(ll a, ll b) {
  return (b == 0) ? a : GCD(b, a % b);
}

// Рациональная дробь: p/q
class Rational {
  ll p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  void normalize() {
    ll d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель
  }
 public:
  // TODO: Конструктор
  Rational(ll pi, ll qi) {
  };
  // TODO: Ввод с клавиатуры
  Rational(const char* message) {
  }
  // TODO: Показать дробь на экран (в консоль)
  void show() {
  };
  // TODO: Сложение дробей
  // a + b
  Rational operator+(Rational& right) {
    // this - указатель на текущий объект
    // *this - текущий объект
  }

  // TODO: прибавить к дроби целое число
  Rational operator+(int right) {
  }

  // TODO: прибавить к целому число дробь
  friend Rational
  operator+(long left, Rational& right) {
  }

  // TODO: вычитание
  Rational operator-(Rational& right);

  // Конструктор копирования
  Rational(const Rational& r);

  // cout - типа ostream
  friend ostream& operator << (ostream& os, Rational& r) {
    os << r.p << " / " << r.q << " ";
    return os;
  }

  // stream - поток
  // thread - поток/нить
};

int main() {
  Rational a(4, 6), b(11, 2);
  a.show();
  b.show();

  // Rational c = b + a;

  int i = 2, j = 3;
  int tt = i + j;
  Rational c1 = i + b;

  b.show();
  c1.show();

  /* Rational x(4,6), y(1,3);
   x.add(y);
   x.show();

   Rational yy("Vvedite:");
   yy.show(); */

  return 0;
}
