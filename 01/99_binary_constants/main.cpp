// Представление двоичных констант в C++
// -------------------------------------
#include <iostream>

using namespace std;

// Рекурсивный "шаблон"
//-->
template<long long N>
struct bin {
  enum {
    value = (N % 8) + (bin < N / 8 >::value << 1)
  };
};

template<>
struct bin<0> {
  enum { value = 0 };
};

// Macro-processing glue: force the number to be octal to both
// end the recursion chain and make posible more digits
#define binary(n) bin<0##n>::value

// Проверка работы макроса
int main() {
  cout << bin<01000>::value << endl;
  cout << bin<1000>::value << endl;
  cout << binary(01000) << endl;
  cout << binary(1000) << endl;
  return 0;
}
//<--
