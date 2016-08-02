<!-- doc.py -->
* НОД - Наибольший общий делитель
* GCD - Greatest Common Divisor
Используем алгоритм Евклида с делением
``` cpp
ll GCD(ll a, ll b) {
  return (b == 0) ? a : GCD(b, a % b);
}
```

Рациональная дробь: p/q
``` cpp
class Rational {
  ll p, q; // p - числитель, q - знаменатель
  // Сокращение дроби
  //  4/6 -> НОД(4,6)=2 -> 2/3
  void normalize() {
    ll d = GCD(p, q); // Вычисляем наибольший общий делитель
    p /= d; // делим на него числитель
    q /= d; // делим на него знаменатель

    if(q < 0) {
      p = -p;
      q = -q;
    }
  }
 public:
  // Конструктор
  Rational(ll pi, ll qi) : p(pi), q(qi) {
    assert(q != 0);
    normalize();
  };
  // Ввод с клавиатуры
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
    // normalize(); // Нельзя, т.к. он меняет объект
    // Сокращаем дробь если надо
    long d = GCD(p, q); // Вычисляем наибольший общий делитель
    long px = p / d; // делим на него числитель
    long qx = q / d; // делим на него знаменатель

    // Заменяем дроби вида -1/-2 на 1/2
    if(qx < 0) {
      px = -px;
      qx = -qx;
    }

    // Если знаменатель равен 1
    // то это целое число
    if(qx == 1)    // Условие (1)
      os << px;
    else { // Иначе есть дробная часть
      // Вычисляем целую часть
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
      os << px << "/" << qx;
    }
  }
  // Сложение дробей
  // a + b
  Rational operator+(Rational& r) {
    // this - указатель на текущий объект
    // *this - текущий объект
    return Rational(p * r.q + r.p * q,
                    q * r.q  );
  }

  // прибавить к дроби целое число
  Rational operator+(int right) {
    return Rational(p + right * q,
                    q);
  }

  // прибавить к целому число дробь
  friend Rational
  operator+(long left, Rational& r) {
    return Rational(left * r.q + r.p,
                    r.q);
  }

  // вычитание
  Rational operator-(Rational& r) {
    return Rational(p * r.q - r.p * q,
                    q * r.q  );
  }

  // Конструктор копирования
  Rational(const Rational& r) {
    p = r.p;
    q = r.q;
  }

  // cout - типа ostream
  friend ostream& operator << (ostream& os,
                               Rational r) {
    r.show(os);
    return os;
  }

  // stream - поток
  // thread - поток/нить
};
```

[main.cpp](main.cpp)

