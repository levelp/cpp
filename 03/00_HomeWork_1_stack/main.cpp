/// Реализовать Стек
/// ================
#include <iostream>

using namespace std;

// Стек
// FIFO
//           3 ->   ->4 ->
//       2   2    2   2  2
//   1   1   1    1   1  1

const int STACK_SIZE = 1000;
int data[STACK_SIZE]; // Данные
int elements = 0; // Кол-во элементов в стеке

// Добавить значение на вершину
void push(int value) {
  if(elements >= STACK_SIZE) {
    cout << "Stack is Full!" << endl;
    return;
  }

  data[elements++] = value;
  // Либо: elements++;
}

// Забрать значение с вершины стека и вернуть его
int pop() {
  if(elements <= 0) {
    cout << "Stack is Empty!" << endl;
    return -1;
  }

  return data[--elements];
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
