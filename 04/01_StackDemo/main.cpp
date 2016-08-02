#include <iostream>

using namespace std;

//-->
class Stack {
  const static int STACK_SIZE = 100;
  int data[STACK_SIZE];
  // Текущий размер стека
  int count = 0;
 public:
  // Положить данные на вершину стека
  void push(int value) {
    if(count == STACK_SIZE) {
      cout << "Stack is full!" << endl;
      return;
    }

    data[count++] = value;
  }
  // Забрать данные с вершины стека
  int pop() {
    if(count == 0) {
      cout << "Stack is empty!" << endl;
      return -1;
    }

    return data[--count];
  }
};
//<--

int main() {
  Stack s;
  s.push(2); // 2
  s.push(3); // 2 3
  cout << s.pop() << endl;
  s.push(6); // 2 6
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  return 0;
}
