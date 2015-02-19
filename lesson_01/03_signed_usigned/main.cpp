#include <iostream>

using namespace std;

int main() {
  unsigned long ul = -1;
  signed long sl = -1;
  //cout << "ul = " << (signed long)ul << endl;
  cout << "ul = " << ul << endl;
  cout << "sl = " << sl << endl;

  cout << "ul + sl = " << ul + sl << endl;
  cout << "ul + sl = " <<
       (signed long)(ul + sl) << endl;
  return 0;
}
