#include <iostream>
#include <stdexcept>

using namespace std;

// Наибольший общий делитель
//  НОД(10, 15) = 5
// => Greatest Common Divider
long GCD(long a, long b) {
  long min_val = (a < b) ? (a) : (b);
  long max_val = (a > b) ? (a) : (b);

  while(min_val != 0) {
    long rem = max_val % min_val;
    max_val = min_val;
    min_val = rem;
  }

  return max_val;
}

class Rational {
 public:
  Rational(long numerator_ = 0, long denominator_ = 1) {
    if(denominator_ < 0) {
      denominator_ = -denominator_;
      numerator_ = -numerator_;
    }

    // Если передан знаменатель 0 => генерируем исключение
    if(denominator_ == 0)
      throw domain_error("In Rational constructor denominator_ = 0.");

    numerator = numerator_;
    denominator = denominator_;
    // Сокращение дроби
    normalize();
  }

  Rational(const char* message) {
    cout << message << " ";
    cout << "numerator = ";
    cin >> numerator;
    cout << "denominator = ";
    cin >> denominator;

    normalize();
  }
  // copy constructor
  // Rational b; b.x = new int[1110];
  // Rational a = b; a.x = b.x
  //  после вызова деструктора для b
  //  у 'a' поле 'x' будет указывать на уже освобожденную память
  Rational(const Rational& other) {
    //cout << other.numerator << "/" << other.denominator << endl;
    numerator = other.numerator;
    denominator = other.denominator;
    //cout << "Copy constructor " << numerator << "/" << denominator <<endl;
  }
  Rational& operator=(const Rational& other) {
    if ( this != &other )
      Rational(other).swap(*this);

    return *this;
  }
 public: // methods
  void negative() {
    numerator = -numerator;
  }
  void inverse() {
    if( numerator != 0 ) {
      long temp = numerator;
      numerator = denominator;

      if( temp < 0 ) {
        numerator = -numerator;
        temp = -temp;
      }

      denominator = (unsigned long)temp;
    } else
      throw domain_error("Illegal using of 'inverse' operation: appears division by zero.");
  }
  void add(Rational other) {
    long temp = long(numerator * other.denominator + denominator * other.numerator);
    numerator = temp;
    denominator *= other.denominator;
    normalize();
  }
  void sub(Rational other) {
    other.negative();
    add(other);
  }
  void mult(Rational other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    normalize();
  }
  void div(Rational other) {
    other.inverse();
    mult(other);
  }
  void show() {
    normalize();

    if(denominator == 1)
      cout << numerator << endl;
    else {
      if( numerator < 0 )
        cout << "-";

      long whole = (numerator >= 0) ? (numerator / denominator) : (-numerator / denominator);

      if(whole != 0)
        cout << whole << " ";

      long reminder = (numerator >= 0 ) ? (numerator % denominator) : (-numerator % denominator);
      cout << reminder << "/" << denominator << endl;
    }
  }
 public: // operators
  //unary operators "+" and "-"
  const Rational& operator+() const {
    return *this;
  }
  //    -a + (b*a)
  Rational& operator-() {
    negative();
    return *this;
  }

  //binary operators "+=", "-=", "*=" and "/="
  Rational& operator+=(const Rational& other) {
    add(other);
    return *this;
  }
  Rational& operator-=(const Rational& other) {
    sub(other);
    return *this;
  }
  Rational& operator*=(const Rational& other) {
    mult(other);
    return *this;
  }
  Rational& operator/=(const Rational& other) {
    div(other);
    return *this;

  }
 private:
  //methods
  void normalize() {
    long gcd = GCD(//abs(numerator)
                 ((numerator < 0) ? (-numerator) : (numerator)),
                 denominator);
    // Сокращение дроби
    numerator /= gcd;
    denominator /= gcd;
  }
  void swap(Rational& other) {
    std::swap(numerator, other.numerator);
    std::swap(denominator, other.denominator);
  }

  friend ostream& operator <<(ostream& os, Rational& r) {
    r.normalize();

    if(r.denominator == 1)
      os << r.numerator;
    else {
      if( r.numerator < 0 )
        os << "-";

      long whole = (r.numerator >= 0) ? (r.numerator / r.denominator) :
                   (-r.numerator / r.denominator);

      if(whole != 0)
        os << whole << " ";

      long reminder = (r.numerator >= 0 ) ? (r.numerator % r.denominator) : (-r.numerator % r.denominator);
      os << reminder << "/" << r.denominator;
    }

    return os;
  }

 private:
  long numerator;
  unsigned long denominator;
};

// operators
Rational operator+(const Rational& first, const Rational& second) {
  Rational ret = first;
  ret += second;
  return ret;
}

Rational operator-(const Rational& first, const Rational& second) {
  Rational ret = first;
  ret -= second;
  return ret;
}

Rational operator*(const Rational& first, const Rational& second) {
  Rational ret = first;
  ret *= second;
  return ret;
}

Rational operator/(const Rational& first, const Rational& second) {
  Rational ret = first;
  ret /= second;
  return ret;
}

int main() {
  Rational a(4, 6), b(11, 2);
  // cout << "a = ";
  // a.show();
  // cout << "b = ";
  // b.show();
  cout << "b = " << b << endl;
  return 0;

  Rational c = b + a;
  cout << "c = ";
  c.show();
  int i = 2;
  Rational c1 = i + b;
  cout << "c1 = " << i << " + b =";
  c1.show();

  Rational r_1(50, 100);
  cout << "r_1 = ";
  r_1.show();
  Rational r_2(1, 3);
  cout << "r_2 = ";
  r_2.show();
  Rational r_3(6, 7);
  cout << " r_3 = ";
  r_3.show();
  Rational r_4 = r_1 + r_2;
  cout << "r_4 = r_1 + r_2 = ";
  r_4.show();
  Rational r_5 = r_1 + 1;
  cout << "r_5 = r_1 + 1 =";
  r_5.show();
  Rational r_6 = 1 + r_2;
  cout << "r_6 = 1 + r_2 = ";
  r_6.show();
  Rational r_7 = r_1 - r_3;
  cout << "r_7 = r_1 - r_3 = ";
  r_7.show();
  Rational r_8 = r_1 / r_2;
  cout << "r_8 = r_1/r_2 = ";
  r_8.show();
  Rational r_9 = r_1 * 5;
  cout << "r_9 = r_1*5 = ";
  r_9.show();
  Rational r_10 = 1 + r_1;
  cout << "r_10 = 1 + r_1 = ";
  r_10.show();
  Rational r_11 = r_1 / 5;
  cout << "r_11 = r_1/5 = ";
  r_11.show();
  Rational r_12 = 6 / r_2;
  cout << "r_12 = 6/r_2 = ";
  r_12.show();
  Rational r_13 = 3 + 1 / r_1;
  cout << "r_13 = 3 + 1/r_1 = ";
  r_13.show();
  Rational temp(-43, 21);
  cout << "temp = ";
  temp.show();
  Rational temp_1("Please, enter rational number:");
  cout << "rational number = ";
  temp_1.show();
  return 0;
}
