#include <iostream>
#include "module1.h"
#include "vars.h"

using namespace std;

/// Глобальная переменная в **vars.h**
///-->
extern int globalVar;
///<--

void v1() {
  D(globalVar = 1);
  SHOW(globalVar);
}

void show1() {
  SHOW(globalVar);
}


