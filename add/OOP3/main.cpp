#include <iostream>

using namespace std;

#define S(x) cout << __FUNCTION__ << ": " << #x << " = " << x << endl;

class A {
 public:
  bool f1() {
    cout << "f1()" << endl;
    return false;
  }
  void f2() {
    cout << "f2()" << endl;
  }
  void f3() {
    cout << "f3()" << endl;
  }
  void main() {
    if(f1()) {
      f2();
      f3();
    }
  }
};

int main() {
  A a;
  a.main();
  return 0;
}
