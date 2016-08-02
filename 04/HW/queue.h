#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>

// Очередь, реализованная через
// динамический список
template <class T> // T - тип элементов в стеке
class Queue {
  struct Element {
    T value; // Значение
    Element* next; // Следующий элемент
    Element() : next(NULL) {}
  };
  Element* head,// Начало очереди
           *tail; // Конец (хвост) очереди
 public:
  Queue() : head(NULL), tail(NULL) {}
  // Добавить в конец очереди
  void put(T v) {
    Element* x = new Element;
    x->value = v;

    if(head == NULL) {
      x->next = tail;
      head = x;
    } else {
      x->next = tail;
      tail = x;
    }

  }
  // Получить из начала очереди
  T get() {
    if(head == NULL && tail == NULL) {
      std::cout << "Queue is empty!" << std::endl;
      throw "Queue is empty!";
    }

    if(head != tail->next) {
      Element* y = head;
      T value = y->value;
      head = tail->next;
      delete y;
      return value;
    } else {
      Element* y = tail;
      T value = y->value;
      tail = tail->next;
      delete y;
      return value;
    }


  }

};

#endif // QUEUE_H_INCLUDED

