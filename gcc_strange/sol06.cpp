#include <iostream>

using namespace std;

int main() {
  // Проверяем ассоциативность
  int res1 = (1 <= 2);
  int res2 = 2 <= res1;
  cout << res1 << " " << res2 << endl;
  cout << "(2 <= (1 <= 2)) " << (2 <= (1 <= 2)) << endl;
  cout << "((2 <= 1) <= 2) " << ((2 <= 1) <= 2) << endl;
  cout << "(2 <= 1 <= 2) " << (2 <= 1 <= 2) << endl;
  cout << (0 <= 1 <= 2) << endl;
  cout << (-5 <= -4 <= -3) << endl;
  cout << (10 <= 5 <= 3) << endl;
  return 0;
}