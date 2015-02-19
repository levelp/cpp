// Домашняя работа
// ---------------
#include <iostream>
#include <cstdlib>

using namespace std;

//-->
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
    // TODO: реализовать
  }
  // Взять значение с вершины стека
  int pop() {
    // TODO: реализовать
  }
};

// Очередь
struct Queue {
  E* head; // "Голова" - начало очереди
  E* tail; // "Хвост" - конец очереди
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};
  // В конец очереди
  void put(int value) {
    // TODO: реализовать
  }
  // Забрать первый элемент из очереди
  int get() {
    // TODO: реализовать
  }
};
//<--

int main() {
  // Пример использования
  //-->
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
  q.put(99);
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;
  cout << "99 - " << q.get() << endl;
  //<--

  return 0;
}
