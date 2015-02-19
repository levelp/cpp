#include <iostream>
#include <set>
#include <cassert>

using namespace std;

struct S {
  int i, j;
  bool operator <(const S right) const {
    return (i < right.i) || (j < right.j);
  }
  bool operator ()(S& left, S& right) const {
    return left < right;
  }
};

int test_set_find() {
  set<S> s;
  S s1 = {1, 2};
  S s2 = {1, 3};
  s.insert(s1);
  s.insert(s2);
  assert(s.size() == 2);
  S f = *(s.find(s2));
  cout << f.i << " "
       << f.j << endl;

  return 0;
}
