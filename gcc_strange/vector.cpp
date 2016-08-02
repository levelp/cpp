#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int f() {
  v.push_back(0);
  return 2;
}

int main() {
  v.push_back(1);
  v[1] = f();
  cout << v[0] << " " << v[1] << endl;
  return 0;
}