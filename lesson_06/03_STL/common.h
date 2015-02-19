#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <iostream>

//-->
#define SHOW(x) cout << #x << " = " << x << endl;
#define X(a,b) ((a == b) ? (void)0 : _assert(#a" != "#b, __FILE__, __LINE__))
//<--

using namespace std;

//-->
template <class T>
void showCollection(T v) {
  for(size_t i = 0; i < v.size(); ++i)
    cout << v[i] << " ";

  cout << endl;
}
//<--

void test_vector();
void test_set_find();

#endif // COMMON_H_INCLUDED
