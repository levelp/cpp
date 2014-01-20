#include <iostream>

using namespace std;

class A {
public:
  int a;
  virtual void show(){
    cout << " a = " << a << endl;
  }
  A(){ a = 1; }
};

class A2 {
public:
  int a;
  void show(){
    cout << " a = " << a << endl;
  }
  A2(){ a = 3; }
};

class B : public A, public A2 {
public:
  int a;
  virtual void show(){
    cout << " a = " << a <<
      "  A::a = " << A::a <<
      "  A2::a = " << A2::a <<
      endl;
  }
  B(){ a = 2; }
};

int main()
{
  A* a[2] = { new A(), new B() };
  a[0]->show();
  a[1]->show();
  cout << "a = " << a[0]->a << endl;
  cout << "a = " << a[1]->a << endl;
  cout << "sizeof(A) = " << sizeof(A) << endl;
  cout << "sizeof(B) = " << sizeof(B) << endl;
  return 0;
}
