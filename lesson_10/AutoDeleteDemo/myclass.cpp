#include <iostream>
#include "myclass.h"

using namespace std;

MyClass::MyClass(QObject* parent) :
  QObject(parent) {
  cout << "MyClass constructor" << endl;
}

// Деструктор
MyClass::~MyClass() {
  cout << "MyClass destructor" << endl;
}
