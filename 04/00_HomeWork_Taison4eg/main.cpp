/// Домашнее задание: Реализовать стек и очередь - разбор
/// -----------------------------------------------------
/// * FIFO - очередь - First Input First Output
/// * LIFO - стек - Last Input First Output
///
/// Средства отладки:
/// * Отладчик (пошаговое выполнение,
///   точки останова, просмотр переменных и т.д.)
/// * Модульные тесты (проверять утверждения)
/// * Писать лог/протокол работы
/// * Ручное тестирование

#include <iostream>
#include <assert.h>
#include <cstdio>
#include <cstring>

using namespace std;

#define ERROR
#define WARNING
#define INFO
#define DEBUG

#define DEBUG
#ifdef DEBUG
#define D(x) cout << #x << endl; x;
#else
#define D(x) x;
#endif

// Элемент стека и очереди
struct E {
  int value; // Значение элемента
  E* next; // Указатель на следующий элемент
};

// Стек
struct Stack {
  E* top; // Вершина стека
  // Конструктор
  Stack() : top(NULL) { };
  // Значение поместить на вершину стека
  void push(int value) {
    E* temp = new E(); // Создаем временный элемент, который будет помещен на вершину
    temp->value = value ; // Заносим в него значение
    temp->next = top; // Даем ссылку на "бывший" верхний элемент, сохраняя ее в поле адреса
    top = temp; // далее тесповый элемент становится вершиной
  }
  // Взять значение с вершины стека
  int pop() {
    E* temp = new E(); // Создаем временную переменную нашей структуры
    temp = top ; // копируем в нее вершину
    top = top->next ; // далее возвращаемся к более низкому элементу
    return temp->value; // выводим значение "бывшей" вершины
  }
};

struct Queue {
  E* start; // необходимо для сохранения начала отчета
  // Конструктор
  Queue() : start(NULL) {
  };
  // Функция, которая вернет
  // последний элемент,
  // не работает...
  // Контракт: очередь не пуста
  E* getLast() {
    assert(start != NULL);

    E* temp = start;

    assert(temp != NULL);

    // Элемент у которого
    // ссылка на следующий отсутствует
    while(temp->next != NULL) // здесь не выходит ничего
      temp = temp->next;

    return temp;
  }
  // Очередь пуста?
  bool isEmpty() {
    return start == NULL;
  }
  // Положить значение
  // в конец очереди
  void put(int value) {
    E* local = new E();
    local->value = value;
    local->next = NULL;

    if(isEmpty())
      start = local;
    else
      getLast()->next = local;
  }
  // Забрать первый элемент из очереди
  int get() {
    E* temp = new E();
    temp = start;
    start = start->next;
    return temp->value ;
  }
};

/// Конфигурирование
//-->
namespace config {
// Выводить ли сообщения на консоль
bool console = false;
}
//<--

// argc - количество аргументов командной
//  строки
// argv - аргументы командной строки
int main(int argc, char** argv) {
  // Выводим все аргументы командной строки
  for(int i = 0; i < argc; ++i) {
    cout << i << ". " << argv[i] << endl;

    if(!strcmp(argv[i], "console"))
      config::console = true;
  }

  // Перенаправляем вывод в файл
  if(!config::console)
    freopen("main.txt", "w", stdout);

  D(Stack s);
  D(s.push(2));
  D(s.push(3));
  // assert(s.pop()==3);
  cout << "3 - " << s.pop() << endl;
  cout << "2 - " << s.pop() << endl;

  D(Stack s2);
  D(s2.push(10));
  D(s.push(11));
  D(cout << "11 - " << s.pop() << endl);
  D(cout << "10 - " << s2.pop() << endl);

  D(Queue q);
  D(q.put(10));
  D(q.put(14));
  cout << "10 - " << q.get() << endl;
  cout << "14 - " << q.get() << endl;

  return 0;
}
