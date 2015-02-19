#include <iostream>
#include "module2.h"
#include "vars.h"

using namespace std;

/// В **module2.cpp** тоже можно
/// использовать **globalVar**
///-->
void v2() {
  D(globalVar = 2);
  SHOW(globalVar);
}

void show2() {
  D(SHOW(globalVar));
}
///<--




