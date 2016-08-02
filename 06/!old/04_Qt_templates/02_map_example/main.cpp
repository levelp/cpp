#include <QCoreApplication>
#include <map>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  // map<ключ, значение>
  map<int, int> m;
  // m[ключ] = значение;
  m[2] = 1;
  m[3] = 2;
  m[5] = 3;
  m[7] = 4;
  m[11] = 5;
  // ...
  cout << m[7] << endl;

  int N;
  cout << "Enter integer number N = ";
  cin >> N;

  if(m.count(N))
    cout << N << " is prime number #" << m[N] << endl;
  else

    cout << N << " isn't prime number" << endl;

  return 0;
}
