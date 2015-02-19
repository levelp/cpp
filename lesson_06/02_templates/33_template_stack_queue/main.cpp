#include <iostream>
#include <string>

using namespace std;

/// Шаблон:
/// * template <class T>
/// * template <typename T>

/// Элемент стека и очереди:
//-->
template <typename T>
struct E {
  T value; // Значение элемента
  E<T>* next; // Указатель на следующий элемент
};
//<--

/// Стек
//-->
template <typename T = int> // Значение по-умолчанию int
struct Stack {
  E<T>* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) {}
  // Значение поместить на вершину стека
  void push(T value) {
    E<T>* newElement = new E<T>;
    // Записываем значение,
    // которое надо поместить
    // на вершину стека
    newElement->value = value;
    // Новый элемент на вершине стека
    // поэтому все остальные следуют за ним
    newElement->next = top;

    // Ставим новый элемент в начало списка
    top = newElement;
  }
  // Взять значение с вершины стека
  T pop() {
    // Запоминаем результат
    // - значение элемента-"вершины" стека
    // 1-A
    T result = top->value;

    // Запоминаем ссылку на удаляемый
    // элемент
    // 1-B
    E<T>* e = top;

    // 2. Перемещаем вершину на следующий
    top = top->next;

    // 3. Реально удаляем элемент
    delete e;

    // 4. Возвращаем результат
    return result;
  }
};
//<--

//-->
template <typename T>
struct Queue {
  E<T>* head; // "Голова" - начало очереди
  E<T>* tail; // "Хвост" - конец очереди
  // Конструктор
  Queue() : head(NULL), tail(NULL) {};
  // В конец очереди
  void put(T value) {
    // Создаём новый элемент
    E<T>* e = new E<T>;
    e->value = value;
    e->next = NULL;

    // Если очередь пуста
    if(head == NULL) {
      head = e;
      tail = e;
    } else {
      // Если в очереди уже есть элементы
      // "Присоединяем" элемент к последнему
      // элементу в очереди
      tail->next = e;
    }
  }
  // Забрать первый элемент из очереди
  T get() {
    // Запоминаем первый элемент
    E<T>* firstElement = head;
    // Значение, которое мы в конце вернём
    T value = firstElement->value;
    // Передвигаем указатель на начало
    // очереди на следующий элемент
    head = head->next;

    // Если очередь пуста, то
    // хвост очереди не указывает ни на
    // какой элемент
    if(head == NULL)
      tail = NULL;

    // Удаляем первый элемент из
    // динамической памяти
    delete firstElement;

    // Возвращаем его значение
    return value;
  }
};
//<--

int main() {
  Stack<> s;
  s.push(2);
  s.push(3);
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  Stack<int> s2;
  s2.push(10);
  s.push(11);
  cout << "11 - " << s.pop() << endl;
  cout << "10 - " << s2.pop() << endl;

  Queue<int> q;
  q.put(10);
  q.put(14);
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;

  Stack<string> strStack;
  strStack.push(string("test"));
  strStack.push("test2");

  cout << strStack.pop() << endl;
  cout << strStack.pop() << endl;

  return 0;
}
