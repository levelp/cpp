// Тернарный оператор слева от присваивания
#include <iostream>

using namespace std;

int main() {
  int a = 0, b = 0, x = 13;

  //const - может быть константой
  bool cond = true;

  // Куда записываем   Значение
  int res = ((x < 10) ? a : b) = 1;

  // Аналогично:
  /*if(b < 10){
    a = 1;
  } else {
    b = 1;
  }*/

  cout << "a = " << a << "  b = " << b << endl;
  return 0;
}
