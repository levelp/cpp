#include "simpletests.h"
#include <iostream>
#include <QtTest/QTest>

using namespace std;

SimpleTests::SimpleTests(QObject* parent) :
  QObject(parent) {
}


// И
void SimpleTests::initTestCase() {
  cout << "All tests initialization" << endl;
}

void SimpleTests::integerOperations() {
  QCOMPARE(2 * 2, 4);
  // QCOMPARE(2 * 2 + 1, 4);
  QCOMPARE(QString("Hello, ").append("World!"),
           QString("Hello, World!"));
}
