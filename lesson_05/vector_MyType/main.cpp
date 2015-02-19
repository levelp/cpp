#include <iostream>
#include <vector> // vector

using namespace std;

class MyClass {
} __attribute__((packed));

struct MyStruct {
};

int main() {
  vector<MyClass> v;
  MyClass m1, m2;
  v.push_back(m1);
  v.push_back(m2);
  cout << "size = " << v.size() << endl;

  v.pop_back();
  cout << "size = " << v.size() << endl;

  cout << "sizeof(MyClass) = " << sizeof(MyClass) << endl;
  cout << "sizeof(MyStruct) = " << sizeof(MyStruct) << endl;

  return 0;
}
