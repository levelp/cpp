#include <iostream>

#define SHOW(x) { cout << #x << " = " << x << endl; };
using namespace std;

int main() {
  // int i = 3;
  // for(int i = 2; i < 10; i++)
  //     cout << i << endl;
  // cout << i << endl;
  int i = 2;
  int j = i++ + i++;
  SHOW(i);
  SHOW(j);
  return 0;
}
