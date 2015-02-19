#include <cstdio>
#include <map>

using namespace std;

int main() {
  map<int, int> a;
  a[2] = a.size();
  a.insert(make_pair(3, a.size()));
  printf("%d %d\n", a[2], a[3]);
}
