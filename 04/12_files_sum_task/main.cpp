#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream in("in.txt");
  ofstream out("out.txt");

  int N;
  // 1. Ввести N
  in >> N;
  // 2. Ввести A[0]..A[N-1]
  int sum = 0;

  for(int i = 0; i < N; i++) {
    int x;
    in >> x;
    sum += x;
  }

  cout << "N = " << N << endl;

  // Вывести сумму всех A
  out << sum << endl;

  return 0;
}
