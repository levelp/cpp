#include <iostream>
#include "module1.h"
#include "vars.h"

using namespace std;

/// Определение глобальной переменной
/// в **module1.cpp**
///-->
int globalVar = 2;
///<--

void v1() {
  D(globalVar = 1);
  SHOW(globalVar);
}

void show1() {
  SHOW(globalVar);
}


