/// Домашнее задание: Реализовать стек и очередь
/// --------------------------------------------
/// Разбор домашнего задания
#include <iostream>
#include <cassert>

using namespace std;

/// Полезные макросы для отладки
//-->
#define D(x) cout << #x << endl; x;
#define SHOW(x) cout << #x << " = " << x << endl;
//<--

/// Элемент стека и очереди
//-->
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};

// Стек
struct Stack {
  E* top = NULL; // Вершина стека
};

// Значение поместить на вершину стека
void push(Stack& s, int value) {
  // newElement - переменная в стеке
  //  - указатель на новый элемент стека
  E* newElement = new E;

  // Записываем значение,
  // которое надо поместить
  // на вершину стека
  (*newElement).value = value;
  // второй вариант:
  newElement->value = value;

  // Новый элемент на вершине стека
  // поэтому все остальные следуют за ним
  newElement->next = s.top;

  // Ставим новый элемент в начало списка
  s.top = newElement;
}
// Взять значение с вершины стека
int pop(Stack& s) {
  // Стек не пуст
  assert(s.top != NULL);

  // Запоминаем результат
  // - значение элемента-"вершины" стека
  // 1-A
  int result = s.top->value;

  // Запоминаем ссылку на удаляемый
  // элемент
  // 1-B
  E* toDelete = s.top;

  // 2. Перемещаем вершину на следующий
  s.top = s.top->next;

  // 3. Реально удаляем элемент
  delete toDelete;

  // 4. Возвращаем результат
  return result;
}

struct Queue {
  E* head = NULL; // "Голова" - начало очереди
  E* tail = NULL; // "Хвост" - конец очереди
};

// В конец очереди
void put(Queue& q, int value) {
  // Создаём новый элемент
  E* e = new E;
  e->value = value;
  e->next = NULL;

  // Если очередь пуста
  if(q.head == NULL) {
    q.head = e;
    q.tail = e;
  } else {
    // Если в очереди уже есть элементы
    // "Присоединяем" элемент к последнему
    // элементу в очереди
    q.tail->next = e;
  }
}
// Забрать первый элемент из очереди
int get(Queue& q) {
  // Запоминаем первый элемент
  E* firstElement = q.head;
  // Значение, которое мы в конце вернём
  int value = firstElement->value;
  // Передвигаем указатель на начало
  // очереди на следующий элемент
  q.head = q.head->next;

  // Если очередь пуста, то
  // хвост очереди не указывает ни на
  // какой элемент
  if(q.head == NULL)
    q.tail = NULL;

  // Удаляем первый элемент из
  // динамической памяти
  delete firstElement;

  // Возвращаем его значение
  return value;
}
//<--

int main() {
  D(Stack s);
  SHOW(s.top);
  D(push(s, 2));
  SHOW(s.top->value);
  SHOW(s.top->next);

  D(push(s, 3));
  SHOW(s.top->value);
  SHOW(s.top->next);
  SHOW(s.top->next->value);
  SHOW(s.top->next->next);

  SHOW(pop(s));
  SHOW(pop(s));

  D(Stack s2);
  D(push(s2, 10));
  D(push(s2, 11));
  SHOW(pop(s2));
  SHOW(pop(s2));

  D(Queue q);
  D(put(q, 10));
  D(put(q, 14));
  SHOW(get(q));
  SHOW(get(q));

  return 0;
}
