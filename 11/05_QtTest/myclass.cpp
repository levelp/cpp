#include <QString>
#include <cmath>
#include <iostream>
#include "myclass.h"

using namespace std;


MyClass::MyClass(QObject* parent) :
  QObject(parent) {
}

int MyClass::max(int a, int b) {
  // return 10;
  if(a > b)
    return a;

  return b; // Stub / "заглушка"
}

int MyClass::min(int a, int b) {
  if(a < b)
    return a;

  return b;
}
