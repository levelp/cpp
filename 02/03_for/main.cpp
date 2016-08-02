#include <iostream>
//#include <stdio.h> // C
#include <cstdio> // C++

using namespace std;

int main() {
  const int MAX = 10;

  for(int i = 1; i <= MAX; ++i) {
    for(int j = 1; j <= MAX; ++j)
      printf("%4d", (i * j));

    printf("\n");
  }

  for(int i = 0, j = 10;
      i < 100 && j < 30;
      i += 5, j += 7, ++i, i += 3)
    cout << "i = " << i << "  j = " << j << endl;

  return 0;
}
