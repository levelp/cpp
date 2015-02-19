#include <iostream>

using namespace std;

void showBinary(int n) {
  char c[32];
  int i;

  for(i = 0; n; i++) {
    c[i] = '0' + (n & 1);
    n >>= 1;
  }

  for(i--; i >= 0; i--)
    cout << c[i];

  cout << endl;
}

int main() {
  int a = 3;
  int b = 5;
  int c = a & b;
  showBinary(4);


  //cout
  cout << "Hello world!" << endl;
  return 0;
}
