// Домашнее задание:
//   Реализовать стек и очередь
#include <iostream>

using namespace std;

// Элемент стека и очереди
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};

// Стек
struct Stack {
  E* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) {}
  // Значение поместить на вершину стека
  void push(int value) {

  }
  // Взять значение с вершины стека
  int pop() {

  }
};

struct Queue {
  E* start;
  // Конструктор
  Queue() : start(NULL) {};
  // В конец очереди
  void put(int value) {

  }
  // Забрать первый элемент из очереди
  int get() {

  }
};

int main_example() {
  Stack s;
  s.push(2);
  s.push(3);
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  Stack s2;
  s2.push(10);
  s.push(11);
  cout << "11 - " << s.pop() << endl;
  cout << "10 - " << s2.pop() << endl;

  Queue q;
  q.put(10);
  q.put(14);
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;

  return 0;
}
