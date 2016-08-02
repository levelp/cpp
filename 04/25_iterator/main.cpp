#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
  set<int> s; // множество элементов без учёта повторов (уникальных)
  s.insert(1); // -> 1
  s.insert(5); // -> 1,5
  s.insert(5); // -> 1,5
  s.insert(1); // -> 1,5

  // Итерируемся по set
  for(set<int>::iterator i = s.begin(); i != s.end(); i++) {
    cout << *i << endl;
    s.erase(*i);
    cout << "2 " << *i << endl;
  }

  cout << s.size() << endl;

  vector<int> v(10, 0);
  //    for(vector<int>)

  return 0;
}
