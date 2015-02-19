#include <QtTest/QTest>
#include "tests.h"
#include "divisors.h"

Tests::Tests(QObject* parent) :
  QObject(parent) {
}

void Tests::testDivisors() {
  ///-->
  QCOMPARE( calcDiv(1), 1 );
  // 2 -> {1, 2}
  QCOMPARE( calcDiv(2), 2 );
  // 3 -> {1, 3}
  QCOMPARE( calcDiv(3), 2 );
  // 4 -> {1, 2, 4}
  QCOMPARE( calcDiv(4), 3 );
  // 11 -> {1, 11}
  QCOMPARE( calcDiv(11), 2 );

  QCOMPARE( calcDiv(1000), 16 );

  // 1000000000 -> {1, ..???., 1000000000}
  QCOMPARE( calcDiv(1000000000), 100 );

  QCOMPARE( calcDiv(1234567890), 48 );
  ///<--

  /// Регрессионное тестирование
  ///-->
  for(int N = 1; N < 10000; ++N)
    QCOMPARE( calcDiv(N), calcDivSlow(N) );

  ///<--

  QCOMPARE( calcDiv(-2), 2 );
}