#include <iostream>
#include <iomanip> // [I]nput-[O]utput [MANIP]ulations
//#define _USE_MATH_DEFINES
#undef __STRICT_ANSI__
#include <math.h>
using namespace std;

typedef unsigned long long myInt;

// Функция
// unsigned long long = myInt - тип возвращаемого значения
// fact - имя функции
// n - аргумент функции
myInt fact(int n) {
  // Рекурсия
  if(n <= 1)
    return 1;
  else
    return n * fact(n - 1);
}

double fact2(int n) {
  // Рекурсия
  if(n <= 1)
    return 1;
  else
    return n * fact2(n - 1);
}

int main() {
  const int c1 = 4, c2 = 21, c3 = 28;
  cout << setw(4) << " n! = "
       << setw(c2 + 1) << " unsigned long long |"
       << setw(c3 + 1) << " double |"
       << endl;

  for(int i = 0; i < 57; i++)
    cout << "=";

  cout << endl;

  for (int n = 1; n <= 19; n++) {
    //n = 0;
    //cout << "Enter a value n > 0 " << i << endl;
    //cin >> n;
    cout <<
         setw(2) << n <<
         setw(1) << "! = " <<
         setw(c2) << fact(n) <<
         setw(1) << "|" <<
         setprecision(20) << setw(c3) << fact2(n) <<
         setw(1) << "|" << endl;
  }

  /*const double PI = 4.0*atan(1);
  for(int i = 1; i < 10; i++){
    cout << "setprecision(" << i << ") " <<
      setprecision(i) << M_PI << endl;
  } */

  return 0;
}
