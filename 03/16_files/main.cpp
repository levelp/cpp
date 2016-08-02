#include <iostream>
#include <cstdlib>
#include <cstdio>

// boost

using namespace std;

int main() {
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  int a, b;

  while(!cin.eof()) {
    cin >> a >> b;

    if(cin.good())
      cout << (a * b) << endl;
  }

  return 0;
}
