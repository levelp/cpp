<!-- doc.py -->
Перегрузка операторов в C++. Вывод в поток
------------------------------------------
**Оператор в C++** - это некоторое действие или функция
обозначенная специльным символом (символами).
Чтобы распространять действие операторов на новые
(свои) типы данных в C++ их можно перегружать.
Для перегрузки используется ключевое слово **operator** вместе с прототипом и объявлением функции.
Практика: класс "рациональная дробь"
------------------------------------
Сокращение типа
``` cpp
typedef long long ll;
```

НОД - Наибольший общий делитель.
GCD - Greatest common divisor.
``` cpp
long GCD(long a, long b) {
  return (b == 0) ? a : GCD(b, a % b);
}
```

``` cpp
// Рациональная дробь: p/q
class Rational {
  long p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  void normalize() {
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель
  }
 public:
  // TODO: Конструктор
  Rational(long pi, long qi) :
    p(pi), q(qi) {
    assert(q != 0);
    //if(q == 0){
    //  cout << "q == 0" << endl;
    //  halt(1);
    //}
  }
  Rational(const char* message) {
    cout << message << " ";
    cout << "p = ";
    cin >> p;
    cout << "q = ";
    cin >> q;
    normalize();
  }
  // Показать дробь на экран (в консоль)
  void show(ostream& os = cout) const {
    // Сокращаем дробь если надо
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    long px = p / d; // делим на него числитель
    long qx = q / d; // делим на него знаменатель

    if(qx < 0) {
      px = -px;
      qx = -qx;
    }

    // Если знаменатель равен 1
    // то это целое число
    if(qx == 1)   // Условие (1)
      os << px << endl;
    else {
      // Целая часть
      long whole = px / qx;

      if(whole != 0)
        os << whole << " ";
      else if(px < 0)
        os << "-";

      px -= whole * qx;
      px = abs(px);
      assert(px > 0);
      // Если число целое, то должно было сработать
      // первое условие (1)
      assert(px % qx != 0);
      os << px << "/" << qx << endl;
    }
  }

  // Сложение дробей
  void add(Rational& right) {
    //   p    right.p
    //  --- + -------
    //   q    right.q
    p = p * right.q + right.p * q;
    //  --------------------------
    q =       q * right.q;

    // Для предотвращения переполнений
    normalize();
  }

  // a + b
  const Rational operator+(Rational& right) {
    Rational res = *this;
    res.add(right);
    return res;
  }

  Rational operator+(int right) {
    Rational res = *this;
    Rational r(right, 1);
    res.add(r);
    return res;
  }

  friend
  Rational
  operator+(long left, Rational& right) {
    Rational res(left, 1);
    res.add(right);
    return res;
  }

  void sub(Rational& right) {
    p = p * right.q - right.p * q;
    //  --------------------------
    q =       q * right.q;

    normalize();
  }

  Rational operator-(Rational& right) {
    Rational res = *this;
    res.sub(right);
    return res;
  }

  // Конструктор копирования
  /* Rational(const Rational &r){
     //cout << r.p << "/" << r.q << endl;
     p = r.p;
     q = r.q;
     //cout << "Copy contructor " << p << "/" << q << endl;
   } */

  friend ostream& operator <<(ostream& os, const Rational& r) {
    r.show(os);
    return os;
  }
};

#define SHOW(x) { cout << #x << " = " << (x) << endl; }

int main() {
  /* Rational x(3, 1);
   x.show();

   Rational y(6, 4);
   y.show(); */

  Rational aa(2, 6), bb(3, 6);
  SHOW(aa);
  SHOW(bb);
  SHOW(aa - bb);

  Rational a(4, 6), b(11, 2);
  SHOW(a);
  SHOW(b);
  Rational c = a + b;
  SHOW(c);
  SHOW(a + b);
  SHOW(a - b);
  SHOW(a / b);
  SHOW(a * b);
  SHOW(a);
  SHOW(b);

  // Rational c = b + a;

  int i = 2, j = 3;
  int tt = i + j;
  Rational c1 = i + b;

  b.show();
  c1.show();

  Rational x(4, 6), y(1, 3);
  x.add(y);
  x.show();

  Rational yy("Vvedite:");
  yy.show();

  return 0;
}
```

[main.cpp](main.cpp)

