// Задача:
// Функция, вычисляющая сумму элементов
// массива с произвольным типом данных.
// Понятно, что функция применима только если
// элементы массива поддерживают операцию
// сложения "+"
#include <iostream>
#include <cassert>

using namespace std;

// size_t - целый тип, используемый для индексации массивов

// Универсальная функция суммирования
template <class T>
T sumArray(T* array, size_t size) {
  T sum = 0;

  for(size_t i = 0; i < size; ++i)
    sum += array[i];

  return sum;
}

// Отдельная функция для суммирования строк
template <>
string sumArray(string* array, size_t size) {
  string sum = "";

  for(size_t i = 0; i < size; ++i)
    sum += array[i];

  return sum;
}

// Комплексное число
struct Complex {
  // re - действительная часть
  // im - мнимая часть
  double re, im;

  Complex(double re = 0.0, double im = 0.0) :
    re(re), im(im) {
  }

  Complex operator +=(Complex& right) {
    this->re += right.re;
    this->im += right.im;
    return *this;
  }

  Complex operator +(Complex& right) {
    Complex res = *this;
    res += right;
    return res;
  }

  friend ostream& operator <<(ostream& os, Complex c);
};

ostream& operator <<(ostream& os, Complex c) {
  os << c.re << " + " << c.im << "i ";
  return os;
}

int main() {
  int a[3] = {1, 10, 15};
  size_t index = 3;
  a[index] = 1;
  cout << sumArray(a, 3) << endl;

  double d[3] = {2.3, 1.2, 1.9};
  cout << sumArray(d, 3) << endl;

  long long ll[2] = {1000000000000, 2000000000000};
  cout << sumArray(ll, 2) << endl;

  // Строки тоже можно "суммировать"
  // Это называется "Конкатенация строк"
  string sa[2] = {"Hello, ", "World!"};
  cout << sumArray(sa, 2) << endl;

  Complex ca[3] = { Complex(1), Complex(2, 4.1),
                    Complex(2, 1)
                  };
  cout << sumArray(ca, 3) << endl;

  return 0;
}
