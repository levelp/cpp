// Реализовать Стек
// ================
#include <iostream>

using namespace std;

// Стек
// FIFO
//           3 ->   ->4 ->
//       2   2    2   2  2
//   1   1   1    1   1  1

int myStack[1000]; // Данные
int stackTop = 0; // Вершина стека

// Добавить значение на вершину
void push(int value) {
  // TODO: реализовать
}

// Забрать значение с вершины стека и вернуть его
int pop() {
  // TODO: реализовать
}

int main() {
  push(3);
  push(4);
  cout << "4 = " << pop() << endl;
  cout << "3 = " << pop() << endl;

  push(10);
  push(12);
  push(-10);
  cout << "-10 = " << pop() << endl;
  cout << "12 = " << pop() << endl;
  cout << "10 = " << pop() << endl;

  return 0;
}
