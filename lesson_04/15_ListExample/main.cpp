#include <iostream>
#include <assert.h>

using namespace std;

/// Один элемент списка
//-->
struct ListElement {
  int value; // Значение элемента списка
  ListElement* next; // Указатель на
  // следующий элемент списка
};
//<--

/// Список целиком, со всеми операциями
//-->
struct List {
  // Указатель на первый элемент списка
  // ListElement *root = NULL;
  ListElement* root;
  // Конструктор - метод, который вызывается
  // при создании объекта (экземпляра класса)
  List() { /*: root(NULL)*/
    root = NULL; // Указатель на первый элемент
    // NULL - означает что нет ни одного элемента в списке
  }
  // Деструктор (очистка памяти)
  ~List() {
    while(root != NULL) { // Пока список не пуст
      // Запоминаем 2-ой элемент списка
      // (следующий после первого элемента)
      ListElement* second = root->next;
      // Удаляем первый элемент списка
      delete root;
      // delete:
      //  1. Вызывается деструктор (если есть)
      //  2. Освобождается динамическая память
      root = second;
    }
  }
  // Показать список
  void show() {
    for(ListElement* cur = root;
        cur != NULL;
        cur = cur->next) {
      // cur->value <-> (*cur).value
      cout << cur->value << endl;
    }
  }
  // Добавить элемент в начало
  void addToBegin(int value) {
    // Заводим новый элемент в динамической памяти
    ListElement* e = new ListElement;
    // Заполняем новый элемент
    e->value = value;
    // Подвешиваем к новому элементу старый список
    e->next = root;
    // Теперь root должен ссылаться на новый элемент
    root = e;
  }
  // Добавить элемент в конец
  void addToEnd(int value) {
    // Если список пуст, то добавить в конец
    // это то же что и добавить в начало
    if(root == NULL) {
      addToBegin(value);
      return;
    }

    // Ищем последний элемент
    ListElement* cur = root;

    while(cur->next != NULL)
      cur = cur->next;

    // Убеждаемся в том, что это последний элемент
    // списка
    assert(cur->next == NULL);

    // Заводим новый элемент
    ListElement* newElement = new ListElement;
    newElement->value = value;
    newElement->next = NULL;

    // Подвешиваем новый элемент в конец списка
    cur->next = newElement;
  }
};
//<--

int main() {
  List l, list2;
  l.addToBegin(2);
  l.addToBegin(10);
  l.addToBegin(-1);
  l.addToEnd(33);
  l.show();
  return 0;
}
