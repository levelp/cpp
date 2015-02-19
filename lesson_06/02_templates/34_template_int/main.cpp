#include <iostream>

using namespace std;

template <typename T, int size = 10>
struct Stack {
  T data[size];
  int count = 0;
  void push(T value) {
    if(count >= size) {
      cout << "Stack full!" << endl;
      return;
    }

    data[count++] = value;
  }
  T pop() {
    if(count <= 0) {
      cout << "Stack empty!" << endl;
      exit(0);
    }

    return data[--count];
  }
};

int main() {
  Stack<int> s;

  Stack<double> s2;
  s2.push(2.2);

  cout << "Hello world!" << endl;
  return 0;
}
