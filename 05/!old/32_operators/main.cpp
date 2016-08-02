//  Перегрузка операторов
// -----------------------
// В C++ возможна перегрузка:
// арифметических операций
//   + - * /
// Перегрузка операций сравнения
//   > < >= <= == !=
// Операции вывода в поток, ввода с клавиатуры
//   >> <<
#include <iostream>
#include <cassert>
//#include <assert.h> // для С
#include <cmath>

#define SHOW(x) { cout << #x << " = " << (x) << endl; }

//#define DEBUG1

using namespace std;

// Рациональная дробь: p/q
template <class T = int>  // Параметр шаблона "по-умолчанию"
class Rational {
  T p, q; // p - числитель, q - знаменатель
  T GCD(T, T); // НОД (Наибольший Общий Делитель)
  void normalize(); // Сокращение дроби
 public:
  Rational(T pi = 0, T qi = 1);

  // Getters - методы доступа к данным
  T getP() {
    return p;
  }
  T getQ() {
    return q;
  }
  // Setters
  // void setP(T value){ p = value; }

  // a + b
  Rational operator +(Rational&); // Сложение дробей
  Rational operator -(Rational&); // Вычитание
  Rational operator *(Rational&); // Умножение
  Rational operator /(Rational&); // Деление

  // Ввод из потока
  template <class Q>
  friend istream& operator >>(istream& in, Rational<Q>& r);
  // Ключевое слово friend - функция имеет доступ к закрытым (private/protected)
  // членам класса (полям и методам)

  // Вывод в поток
  template <class Q>
  friend ostream& operator <<(ostream& os, Rational<Q> r);
};

// Наибольший общий делитель
// template <class T = int>  // Параметр шаблона "по-умолчанию"
//class Rational {
//  T GCD(T, T);
template <class T>
T Rational<T>::GCD(T a, T b) {
  return (b == 0) ? a : GCD(b, a % b);
}

// Сокращение дроби
template <class T>
void Rational<T>::normalize() {
  // Находим НОД числителя и знаменателя
  T d = GCD(abs(p), abs(q));
#ifdef DEBUG1
  cout << "p = " << p << " q = " << q <<
       "  GCD = " << d << endl;
#endif // DEBUG
  // Делим числитель и знаменатель на НОД
  p /= d;
  q /= d;
}

template <class T>
Rational<T>::Rational(T pi, T qi) : p(pi), q(qi) {
  assert(q != 0);
  //if(q == 0){
  //  cout << "q == 0" << endl;
  //  halt(1);
  //}
}

template <class T>
Rational<T> Rational<T>::operator +(Rational<T>& right) {
  //  p/q + right.p/right.q
  return Rational(
           p * right.q + right.p * q,
           //--------------------------
           q * right.q );
}

template <class T>
Rational<T> Rational<T>::operator -(Rational& right) {
  return Rational(
           p * right.q - right.p * q,
           //--------------------------
           q * right.q );
}

template <class T>
Rational<T> Rational<T>::operator *(Rational<T>& right) {
  return Rational (
           p * right.p,
           //------------
           q * right.q );
}

template <class T>
Rational<T> Rational<T>::operator /(Rational& right) {
  return Rational (
           p * right.q,
           //------------
           q * right.p );
}

template <class T>
ostream& operator <<(ostream& os, Rational<T> r) {
  // Сокращаем дробь если надо
  r.normalize();

  if(r.q == 1)
    os << r.p;
  else {
#ifdef DEBUG1
    os << "DEBUG: " << r.p << " " << r.q << endl;
#endif // DEBUG
    T whole = r.p / r.q;

    if(whole != 0)
      os << whole << " ";

    if(whole != 0)
      os << abs(r.p % r.q);
    else
      os << (r.p % r.q);

    os << "/" << r.q;
  }

  return os;
}

template <class T>
istream& operator >>(istream& in, Rational<T>& r) {
  cout << "p = ";
  in >> r.p;
  cout << "q = ";
  in >> r.q;
  assert(r.q != 0);
  return in;
}

// Шаблонный "шаблонный" параметр
// Класс, который является шаблоном можно передавать как параметр
// другому классу-шаблону, при этом параметр вложенного шаблона
template<class Type, template< class > class Container >
class MyClass {
 public:
  void showND(Container<Type> r) {
    if(r.getP() > r.getQ())
      cout << r.getP() << " > " << r.getQ() << endl;
    else
      cout << r.getP() << " <= " << r.getQ() << endl;
  }
};


int main() {
  MyClass<int, Rational > ll;

  Rational<> a(4, 6), b(11, 2);
  SHOW(a);
  SHOW(b);
  Rational<> c = a + b;
  SHOW(c);

  ll.showND(a);
  SHOW(a);
  SHOW(b);
  SHOW(a + b);

  Rational<long> x(-5, 3), y(-3, 3), z(5, 6);
  SHOW(x);
  SHOW(y);
  SHOW(x - y);

  Rational<long> t = x + y + z;
  cout << x << " + " << y << " + " << z << " = " << t << endl;

  Rational<int> k(1, 6), l(1, 2);
  cout << k << " + " << l << " = " << (k + l) << endl;

  /*cout << "Vvedite: ";
  Rational<int> yy;
  cin >> yy;
  cout << yy; */

  return 0;
}
