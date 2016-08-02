/// Вывод побитовый числа из памяти
/// -------------------------------
#include <iostream>

using namespace std;

void showBinary(unsigned int n) {
  char c[32];
  int i;

  for(i = 0; n; i++) {
    c[i] = '0' + (n & 1);
    n >>= 1;
  }

  if(i > 8)
    i = 8;

  for(int j = 0; j < 8 - i; j++)
    cout << " ";

  for(i--; i >= 0; i--)
    cout << c[i];

  cout << endl;
}

int main() {
  int a = 19;
  int b = 5 + 16;
  int c = a & b;
  cout << "& - AND" << endl;
  showBinary(a);
  showBinary(b);
  showBinary(a & b);
  // & - И
  cout << "| - OR" << endl;
  showBinary(a);
  showBinary(b);
  showBinary(a | b);
  // | - ИЛИ
  // ~ - НЕ
  cout << "~ - NOT" << endl;
  showBinary(a);
  showBinary(~a);

  cout << "^ - XOR" << endl;
  showBinary(a);
  showBinary(b);
  showBinary(a ^ b);

  //cout
  return 0;
}
