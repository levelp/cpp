#include <iostream>

// Итеративное вычисление факториала
long long factorial(int n) {
  long long res = 1;

  // Цикл от большего к меньшему
  for(int i = n; i > 1; --i)
    res *= i;

  return res;
}

// Итеративное вычисление факториала
long long factorial2(int n) {
  long long res = 1;

  // Цикл от меньшего к большему
  for(int i = 2; i <= n; ++i)
    res *= i;

  return res;
}

// Рекурсивный способ вычисления факториала
long long factorial3(int n) {
  if(n == 1)
    return 1;
  else
    return n * factorial3(n - 1);
}

using namespace std;

// Тестирование работы функции
int main() {
  for(int i = 1; i <= 100; ++i) {
    long long res = factorial(i);
    //cout << i << "! = " << res << endl;
    cout << i << "! = "
         << factorial(i) << " "
         << factorial2(i) << " "
         << factorial3(i) << " "
         << endl;
  }

  return 0;
}
