#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  v.push_back(0);

  for (int i = 0; i <= v.size() - 2; i++)
    cout << v[i] << " ";

  return 0;
}