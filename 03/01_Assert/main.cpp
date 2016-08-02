/// Модульное тестирование. Утверждения: assert, TDD (Test Driven Development)
/// --------------------------------------------------------------------------
/// Утверждения нужны для автоматической проверки (тестирования).
///
/// Разработка через тестирование (TDD, test-driven development) -
/// техника разработки программного обеспечения,
/// которая основывается на повторении очень коротких циклов разработки:
/// * сначала пишется **тест**, покрывающий желаемое изменение,
/// * затем пишется **код**, который позволит пройти тест,
/// * и под конец проводится **рефакторинг** нового кода.
///
/// Для создания автоматических тестов можно использовать
/// функцию **assert**
#include <iostream>
//-->
#include <assert.h>
//<--

using namespace std;

//#define DEBUG
//#define INFO
//#define TRACE

/// Разрабатываем функцию вычисления факториала.
/// Контракт - какие обязательства берёт на себя
/// вызывающая сторона.
//-->
long long fact(int n) {
  assert(n >= 0); // Контракт

  if(0 == n)
    return 1;

  return n * fact(n - 1);
}
//<--

void unit_tests() {
  /// Автоматические тесты
  /// Модульное тестирование
  //-->
  assert( fact(1) == 1 );
  assert( fact(2) == 2 );
  assert( fact(3) == 6 );
  assert( fact(3) == 1 * 2 * 3);
  assert( fact(4) == 1 * 2 * 3 * 4 );
  assert( fact(5) == 1 * 2 * 3 * 4 * 5 );
  assert( fact(6) == 1 * 2 * 3 * 4 * 5 * 6 );
  assert( fact(7) == 1 * 2 * 3 * 4 * 5 * 6 * 7 );
  assert( fact(0) == 1 );
  //<--
}

int main() {
  unit_tests();

  //freopen("log.txt","w",stdout);

  /// Ручное тестирование функции:
  //-->
  int N;
  cout << "N = ";
  cin >> N;
  cout << "fact(" << N << ") = " << fact(N) << endl;

  return 0;
  //<--
}