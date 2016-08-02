#include <iostream>
#include "module2.h"
#include "vars.h"

using namespace std;

/// Определение глобальной переменной
/// в **module1.cpp**
///-->
int globalVar = 2;
///<--

/// В **module2.cpp** тоже можно
/// использовать **globalVar**
///-->
void v2() {
  D(globalVar = 2);
  SHOW(globalVar);
}

void show2() {
  SHOW(globalVar);
}
///<--




