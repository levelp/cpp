#include <iostream>
#include <assert.h>

using namespace std;

//typedef long long ll;
// НОД - Наибольший общий делитель
long GCD(long a, long b) {
  return (b == 0) ? a : GCD(b, a % b);
}

// Рациональная дробь: p/q
class Rational {
  long p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  void normalize() {
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель    =
  };
 public:
  Rational(long pi, long qi) :
    p(pi), q(qi) {
    assert(q != 0);
    //if(q == 0){     //  cout << "q == 0" << endl;

    //  halt(1);
    //}
  }
  Rational(const char* message) {
    cout << message << " ";
    cout << "p = ";
    cin >> p;
    cout << "q = ";
    cin >> q;
  }
  void show() {
    // Сокращаем дробь если надо
    normalize();

    if(q == 1)
      cout << p << endl;
    else {
      long whole = p / q;

      if(whole != 0)
        cout << whole << " ";

      cout << (p % q) << "/" << q << endl;
    }
  }


  void add(Rational& right) {
    //  p/q + right.p/right.q
    long pNew = p * right.q + right.p * q;
    //   ----   --------------------------
    long qNew =       q * right.q;
    p = pNew;
    q = qNew;
  }


  // a + b
  Rational operator+(Rational& right) {
    Rational res = *this;
    res.add(right);
    return res;
  }


  Rational operator+(int right) {
    Rational res(0, 1);
    res.p = p + right * q;
    //----  --------------
    res.q = q;
    return res;
  }

  friend
  Rational
  operator+(long left, Rational& right) {
    Rational res(0, 1);
    res.p = right.p + left * right.q;
    //----  -------------------------
    res.q = right.q;
    return res;
  }

  void sub(Rational& right) {
    long pNew = p * right.q - right.p * q;
    //   ----   --------------------------
    long qNew = q * right.q;
    p = pNew;
    q = qNew;
  }
  \

  Rational operator-(Rational& right) {
    Rational res = *this;
    res.sub(right);
    return res;
  }


  // TODO:
  //  + Умножение

  void prod(Rational& right) {
    //  (p/q) * (right.p/right.q)
    long pNew = p * right.p;
    long qNew = q * right.q;
    p = pNew;
    q = qNew;
  }

  // a * b
  Rational operator*(Rational& right) {
    Rational res = *this;
    res.prod(right);
    return res;
  }
  //  + Деление
  void div(Rational& right) {
    //  (p/q) / (right.p/right.q)
    long pNew = p * right.q;
    //   ----   --------------------------
    long qNew = q * right.p;
    p = pNew;
    q = qNew;
  }


  // a / b
  Rational operator/(Rational& right) {
    Rational res = *this;
    res.div(right);
    return res;
  }


  // Конструктор копирования
  Rational(const Rational& r) {
    cout << r.p << "/" << r.q << endl;
    p = r.p;
    q = r.q;
    cout << "Copy contructor " << p << "/" << q << endl;
  }
};


int main() {
  Rational a(4, 6), b(11, 2);
  a.show();
  b.show();
  Rational c = a + b;
  c.show();
  // Rational c = b + a;
  Rational c1 = a - b;
  c1.show();
  Rational c2 = a * b;
  c2.show();
  Rational c3 = a / b;
  c3.show();

  int i = 2, j = 3;
  int tt = i + j;
  Rational c4 = i + b;

  b.show();
  c4.show();


  /* Rational x(4,6), y(1,3);
   x.add(y);
   x.show();

  Rational yy("Vvedite:");
   yy.show(); */


  return 0;
}
