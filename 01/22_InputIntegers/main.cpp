// Ввод целых чисел
// ----------------
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  char s[100];
  cin >> s;
  cout << "s = " << s << endl;
  int i;
  // cout - объект C++
  cout << i << endl;
  // printf - функция C
  printf("%d\n", i);

  int value = atoi(s);
  cout << "value = " << value << endl;
  return 0;
}
