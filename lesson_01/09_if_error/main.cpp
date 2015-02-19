// Самая характерная (распространённая) ошибка при применении if
// -------------------------------------------------------------
#include <iostream>

using namespace std;

#define MY_CONST 3

int main() {
  int a = 0;

  if(a == 0)  /*=*/
    cout << "a = 0" << endl;
  else
    cout << "a != 0" << endl;

  if((3 >= 2) && (10 > 7))
    cout << "TRUE" << endl;
  else
    cout << "FALSE" << endl;

  a = 2;
  int b = 3;

  if(MY_CONST == a)
    cout << "a == b" << endl;
  else
    cout << "a != b" << endl;

  int i = 0, j;

  if(i == 0)
    cout << "True! i = 0" << endl;
  else
    cout << "False! i != 0" << endl;

  if(j = (i = 5))   // Использование присваивания "=" вместо "=="
    cout << "True!" << endl;
  else
    cout << "False!" << endl;

  cout << "j = " << j << endl;

  return 0;
}
