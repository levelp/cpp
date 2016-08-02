// Консольное приложение на Qt для
// вычисления факториала
#include <iostream>

using namespace std;

long factorial(int n) {
  if(n == 1)
    return 1;

  return n * factorial(n - 1);
}

int main() {
  cout << "Hello world!" << endl;
  cout << factorial(10) << endl;
  return 0;
}
