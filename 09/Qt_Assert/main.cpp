#include <iostream>
#include <assert.h>

using namespace std;

int fact(int n) {
  assert(n >= 1);

  if(n >= 3)
    return n * fact(n - 1);

  return n;
}


int main() {
  assert( fact(1) == 1 );
  assert( fact(2) == 2 );
  assert( fact(3) == 1 * 2 * 3 );
  assert( fact(4) == 1 * 2 * 3 * 4 );
  assert( fact(5) == 1 * 2 * 3 * 4 * 5 );
  //fact(0);
  cout << "Hello world!" << endl;
  return 0;
}
