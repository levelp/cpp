#include <QtTest/QTest>
/// Подключаем все модули для тестирования
///-->
#include "inttostr.h"
#include "functions.h"
#include "myclass.h"
#include "squareeq.h"
// И свой заголовочный файл
#include "alltests.h"
///<--

AllTests::AllTests(QObject* parent) :
  QObject(parent) {
}

/// Тестирование вычисления максимума
void AllTests::max() {
  ///-->
  MyClass a(this);
  // QCOMPARE( вызов_тестируемой_функции, ожидаемое_значение );
  QCOMPARE(a.max(2, 3), 3);  // 1 тест
  QCOMPARE(a.max(2, 4), 4);  // 2 тест
  QCOMPARE(a.max(5, 1), 5);
  QCOMPARE(a.max(1, 2), 2);
  QCOMPARE(a.max(-10, -20), -10);
  ///<--
}

/// Тестирование вычисления факториала
void AllTests::factorial() {
  ///-->
  QCOMPARE( ::factorial(1), 1LL );
  QCOMPARE( ::factorial(2), 2 * 1LL );
  QCOMPARE( ::factorial(3), 3 * 2 * 1LL );
  QCOMPARE( ::factorial(4), 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(5), 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(6), 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(7), 7 * 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(8), 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1LL );
  QCOMPARE( ::factorial(9), 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1LL );

  // Проверка исключения (ожидаемое исключение)
  try {
    ::factorial(-1);
    // Если мы оказались в этом месте программы,
    // то метод факториал не сгенерировал исключение
    QFAIL("Exception expected!");
  } catch(QString q) {
    QCOMPARE( q, QString("N > 0"));
  }

  ///<--
}

void AllTests::rootsTest() {
  /// Квадратное уравнение
  /// TDD - Test Driven Development
  ///-->
  SquareEq a;
  Roots roots = a.quadraticEquation(1, 0, 0);

  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], 0.0);

  roots = a.quadraticEquation(4, 0, 0);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], 0.0);

  roots = a.quadraticEquation(1, 0, -1);
  QCOMPARE(roots.numberOfRoots, 2);
  QCOMPARE(roots.x[0], 1.0);
  QCOMPARE(roots.x[1], -1.0);

  roots = a.quadraticEquation(1, 0, 1);
  QCOMPARE(roots.numberOfRoots, 0);

  roots = a.quadraticEquation(0, 1, 1);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], -1.0);

  roots = a.quadraticEquation(0, 0, 1);
  QCOMPARE(roots.numberOfRoots, 0);

  roots = a.quadraticEquation(0, 2, 1);
  QCOMPARE(roots.numberOfRoots, 1);
  QCOMPARE(roots.x[0], -0.5);
  QCOMPARE(a.calc(0, 2, 1, roots.x[0]), 0.0);

  // 0*x*x + 0*x + 0 = 0
  try {
    a.quadraticEquation(0, 0, 0);
    QFAIL("Exception expected!");
  } catch(QString q) {
    QCOMPARE( q, QString("Бесконечное число решений"));
  }

  ///<--
}

/// Число в строку
void AllTests::intToStrBefore100() {
  QCOMPARE(intToStr(0), QString("Ноль"));
  QCOMPARE(intToStr(1), QString("Один"));
  QCOMPARE(intToStr(2), QString("Два"));
  QCOMPARE(intToStr(3), QString("Три"));
  QCOMPARE(intToStr(4), QString("Четыре"));
  QCOMPARE(intToStr(5), QString("Пять"));
  QCOMPARE(intToStr(9), QString("Девять"));
  QCOMPARE(intToStr(10), QString("Десять"));
  QCOMPARE(intToStr(11), QString("Одиннадцать"));
  QCOMPARE(intToStr(12), QString("Двенадцать"));
  QCOMPARE(intToStr(13), QString("Тринадцать"));
  QCOMPARE(intToStr(14), QString("Четырнадцать"));
  QCOMPARE(intToStr(15), QString("Пятнадцать"));
  QCOMPARE(intToStr(16), QString("Шестнадцать"));
  QCOMPARE(intToStr(17), QString("Семьнадцать"));
  QCOMPARE(intToStr(18), QString("Восемьнадцать"));
  QCOMPARE(intToStr(19), QString("Девятьнадцать"));
  QCOMPARE(intToStr(20), QString("Двадцать"));
  QCOMPARE(intToStr(21), QString("Двадцать один"));
  QCOMPARE(intToStr(22), QString("Двадцать два"));
  QCOMPARE(intToStr(26), QString("Двадцать шесть"));
  QCOMPARE(intToStr(30), QString("Тридцать"));
  QCOMPARE(intToStr(31), QString("Тридцать один"));
  QCOMPARE(intToStr(32), QString("Тридцать два"));
  QCOMPARE(intToStr(40), QString("Сорок"));
  QCOMPARE(intToStr(41), QString("Сорок один"));
  QCOMPARE(intToStr(52), QString("Пятьдесят два"));
  QCOMPARE(intToStr(63), QString("Шестьдесят три"));
  QCOMPARE(intToStr(74), QString("Семьдесят четыре"));
  QCOMPARE(intToStr(80), QString("Восемьдесят"));
  QCOMPARE(intToStr(90), QString("Девяносто"));
  QCOMPARE(intToStr(91), QString("Девяносто один"));
  QCOMPARE(intToStr(92), QString("Девяносто два"));
}

void AllTests::intToStr_100_to_199() {
  QCOMPARE(intToStr(100), QString("Сто"));
  QCOMPARE(intToStr(101), QString("Сто один"));
  QCOMPARE(intToStr(102), QString("Сто два"));
  QCOMPARE(intToStr(111), QString("Сто одиннадцать"));
  QCOMPARE(intToStr(120), QString("Сто двадцать"));
  QCOMPARE(intToStr(121), QString("Сто двадцать один"));
  QCOMPARE(intToStr(122), QString("Сто двадцать два"));
  QCOMPARE(intToStr(140), QString("Сто сорок"));
  QCOMPARE(intToStr(141), QString("Сто сорок один"));
}

void AllTests::intToStr_200_to_999() {
  QCOMPARE(intToStr(200), QString("Двести"));
  QCOMPARE(intToStr(201), QString("Двести один"));
  QCOMPARE(intToStr(202), QString("Двести два"));
  QCOMPARE(intToStr(211), QString("Двести одиннадцать"));
  QCOMPARE(intToStr(220), QString("Двести двадцать"));
  QCOMPARE(intToStr(221), QString("Двести двадцать один"));
  QCOMPARE(intToStr(222), QString("Двести двадцать два"));
  QCOMPARE(intToStr(240), QString("Двести сорок"));
  QCOMPARE(intToStr(241), QString("Двести сорок один"));
  QCOMPARE(intToStr(245), QString("Двести сорок пять"));
  QCOMPARE(intToStr(999),
           QString("Девятьсот девяносто девять"));
}

void AllTests::intToStr_1000_to_999999() {
  QCOMPARE(intToStr(1000),
           QString("Одна тысяча"));
  QCOMPARE(intToStr(2000),
           QString("Две тысячи"));
  QCOMPARE(intToStr(3000),
           QString("Три тысячи"));
  QCOMPARE(intToStr(4000),
           QString("Четыре тысячи"));
  QCOMPARE(intToStr(5000),
           QString("Пять тысяч"));
  QCOMPARE(intToStr(10000),
           QString("Десять тысяч"));
  QCOMPARE(intToStr(20000),
           QString("Двадцать тысяч"));
  QCOMPARE(intToStr(99912),
           QString("Девяносто девять тысяч девятьсот двенадцать"));
  QCOMPARE(intToStr(920912),
           QString("Девятьсот двадцать тысяч девятьсот двенадцать"));
  QCOMPARE(intToStr(911912),
           QString("Девятьсот одиннадцать тысяч девятьсот двенадцать"));
}

void AllTests::testSum() {
  QCOMPARE(sum(2, 2), 4);
  QCOMPARE(sum(2, 3), 5);
}
