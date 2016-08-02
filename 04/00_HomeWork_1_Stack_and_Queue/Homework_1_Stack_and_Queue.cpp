#include <iostream>

using namespace std;

template <class T> struct Element {
  Element(): next(NULL) {}
  T value; // Значение
  Element* next; // Следующий элемент
};

template <class T> class StackAsList {
 public:
  // Конструктор
  StackAsList(): top_ptr(NULL), stack_size(0) {}
  ~StackAsList() {
    Element<T>* cur = top_ptr;

    while(cur != NULL) {
      Element<T>* temp = cur;
      cur = cur->next;
      delete temp;
    }
  }

  bool IsEmpty() const {
    return top_ptr == NULL;
    //return stack_size == 0;
  }

  void push(const T& new_element) {
    Element<T>* new_stack_element = new Element<T>;
    new_stack_element->next = top_ptr;
    new_stack_element->value = new_element;

    top_ptr = new_stack_element;
    ++stack_size;
  }

  T pop() {
    T ret = top_ptr->value;
    Element<T>* temp = top_ptr;

    top_ptr = top_ptr->next;

    delete temp;
    --stack_size;
    return ret;
  }

  unsigned size() const {
    return stack_size;
  }

  T& Top() {
    return top_ptr->value;
  }

  const T& Top() const {
    return top_ptr->value;
  }
 private:
  Element<T>* top_ptr; // Указатель на вершину
  unsigned stack_size; // Количество элементов (размер) стека
};

template<class T> class Queue_ {
 public:
  Queue_(): queue_size(0) {
    head_ptr = NULL;
    tail_ptr = NULL;
  }
  ~Queue_() {
    Element<T>* cur = head_ptr;

    while(cur != NULL ) {
      Element<T>* temp = cur;
      cur = cur->next;
      delete temp;
    }
  }
  bool IsEmpty() const {
    return (head_ptr == NULL);
  }

  unsigned size() const {
    return queue_size;
  }
  //put to tail
  void put( const T& new_element ) {
    Element<T>* new_queue_element = new Element<T>;
    new_queue_element->value = new_element;

    if( tail_ptr != NULL )
      tail_ptr->next = new_queue_element;

    tail_ptr = new_queue_element;

    ++queue_size;

    if(head_ptr == NULL)
      head_ptr = tail_ptr;
  }
  //get from head
  T get() {
    if( head_ptr != NULL ) {
      //T ret = head_ptr->value;
      T ret = (*head_ptr).value;

      Element<T>* temp = head_ptr;
      head_ptr = head_ptr->next;
      delete temp;

      if( head_ptr == NULL )
        tail_ptr = NULL;

      --queue_size;
      return ret;
    }

    throw string("Get from empty queue");
    //return T();
  }
 private:
  Element<T>* head_ptr;
  Element<T>* tail_ptr;
  unsigned queue_size;

};

typedef StackAsList<int> Stack;
typedef Queue_<int> Queue;

int main() {
  Stack s;
  s.push(2);
  s.push(3);
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  Stack s2;
  s2.push(10);
  s.push(11);
  s.push(12);
  cout << "12 - " << s.pop() << endl;
  cout << "11 - " << s.pop() << endl;
  cout << "10 - " << s2.pop() << endl;

  Queue q;
  q.put(10);
  q.put(14);
  q.put(99);
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;
  cout << "99 - " << q.get() << endl;
  return 0;
}
