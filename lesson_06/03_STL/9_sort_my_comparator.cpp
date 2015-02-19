// sort algorithm example
#include <iostream>     // cout
#include <algorithm>    // sort
#include <vector>       // vector

using namespace std;

bool myfunction (int i, int j) {
  return (i < j);
}

bool myfunction2 (int i, int j) {
  return i > j;
}

struct myclass {
  bool operator() (int i, int j) {
    return (i < j);
  }
} myobject;

void sort_my_comparator () {
  int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
  sort(myints, myints + 8);

  vector<int> myvector (myints, myints + 8);             // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  sort (myvector.begin(), myvector.begin() + 4);     //(12 32 45 71)26 80 53 33
  // myvector.size()

  // using function as comp
  sort (myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // Сортировка в обратном порядке
  sort (myvector.begin(), myvector.end(), myfunction2); // 12 32 45 71(26 33 53 80)

  for(vector<int>::iterator i = myvector.begin(); i != myvector.end();
      ++i)
    cout << *i << " ";

  cout << endl;

  // using object as comp
  sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  cout << "myvector contains:";

  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    cout << ' ' << *it;

  cout << '\n';
}
