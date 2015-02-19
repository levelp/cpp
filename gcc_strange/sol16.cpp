#include <vector>
#include <iostream>

using namespace std;

vector<int> v;

int f() {
  v.push_back(1);
  return 2;
}

int main() {
  v.push_back(0);
  v[0] = f();
  cout << v[0] << " " << v[1] << endl;
  return 0;
}