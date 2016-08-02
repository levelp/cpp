#include <iostream>

using namespace std;

// Чтобы понять рекурсию,
// надо понять рекурсию.
// Рекурсивная функция f
long long f(int N) {
  //if(N == 0)
  //  return 1;
  //else
  //  return N * f(N-1);
  return (N == 0) ? 1 : N * f(N - 1);
}

int main() {
  int N;
  cout << "Enter N = ";
  cin >> N;
  cout << f(N) << endl;
  return 0;
}
