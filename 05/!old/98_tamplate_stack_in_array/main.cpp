#include <iostream>

using namespace std;

#define S(x) { cout << #x << " = " << x << endl; }
#define DO(x) { cout << #x << endl; x; }

const int ERROR = -100500;

// T - тип значений
// size - размер стека
template <class T, int size>
class Stack {
  T d[size];
  int N;
 public:
  Stack() : N(0) {}
  void push(T value) {
    if(isFull()) throw string("Stack is full");

    d[N++] = value;
  }
  T pop() {
    if(isEmpty()) throw string("Stack is empty");

    // if(isEmpty()) return ERROR;
    return d[--N];
  }
  bool isEmpty() {
    return N == 0;
  }
  bool isFull() {
    return N == size;
  }
};

int main() {
  const int N = 5;
  Stack<int, N> s;
  S(s.isFull());
  S(s.isEmpty());

  for(int i = 1; i <= 5; i++)
    DO(s.push(i));

  S(s.isFull());
  S(s.pop());
  S(s.pop());
  S(s.pop());
  S(s.pop());
  S(s.pop());

  try {
    s.pop();
  } catch(string error) {
    S(error);
  }

  S(s.isFull());
  return 0;
}
