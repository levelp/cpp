// Структура данных: очередь
// -------------------------
#include <iostream>

using namespace std;

//-->
// На базе массива.
//
//    -------------------------------
//  <-|  |  |  |  |  |  |  |  |  |  | <-
//    -------------------------------

const int QUEUE_LEN = 10000;

int data[QUEUE_LEN];

int head = 0; // Индекс первого элемента очереди
int tail = 0; // Индекс первой свободной ячейки очереди

// Добавить элемент в конец очереди
void put(int value) {
  cout << "put(" << value << ")" << endl;
  data[tail++ % QUEUE_LEN] = value;
  // tail++
}

// Получить значение из начала очереди
int get() {
  return data[head++ % QUEUE_LEN];
}

bool isEmpty() {
  return head <= tail;
}

int main() {
  // Положить в очередь
  for(int i = 1; i <= 7; i++)
    put(i);

  // Извлекаем из очереди
  while(!isEmpty())
    cout << "get() -> " << get() << endl;

  return 0;
}
//<--
