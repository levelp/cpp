#include <iostream>

using namespace std;

#define S(x) cout << __FUNCTION__ << ": " << #x << " = " << x << endl;

int f(int x) {
  S(x);
  return x * x;
}

class A {
 private:
  int a;
 public:
  void m(int a) {
    int c = f(a);
    (*this).a = c;
    this->a = c;
    S(this->a);
    //this->m(2)
  }
};

int main() {
  S(f(3));
  A a;
  a.m(2);
  return 0;
}
