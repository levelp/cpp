#include <iostream>
#include <string> // string

using namespace std;

struct List2 {
  string value; // Значение элемента списка
  List2* prev; // Предыдущий элемент
  List2* next; // Следующий элемент
};

List2* root = NULL; // Пустой список

// Добавить элемент в начало списка
void addToBegin(string value) {
  List2* e = new List2;
  e->value = value;
  e->next = root;
  e->prev = NULL;

  // Тот элемент, который раньше был первым
  // теперь должен ссылаться на новый первый элемент
  if(root != NULL)
    root->prev = e;

  root = e;
}

// Добавляем элемент в конец списка
void addToEnd(string value) {
  if(root == NULL) {
    addToBegin(value);
    return;
  }

  // Список не пустой
  List2* e = new List2;
  e->value = value;
  e->next = NULL;

  // Идея: найти последний элемент списка
  List2* last = root;

  while(last->next != NULL)
    last = last->next;

  // Для "старого" последнего элемента
  // следующий элемент - новый элемент
  last->next = e;

  // Для нового элемента: предыдущий -
  // "старый" последний элемент
  e->prev = last;
}

// Удалить первый элемент списка
void deleteFirst() {
  List2* first = root;
  root = first->next;
  // Мы удаляем первый элемент, поэтому
  // предыдущего элемента нет
  root->prev = NULL;

  // Удаляем из памяти
  delete first;
}

void deleteByValue(string value) {
  // Ищем элемент по значению
  for(List2* cur = root;
      cur != NULL;
      cur = cur->next) {
    if(cur->value == value) {
      // Нашли элемент с заданным значением!
      cout << "Found: " << value << endl;

      // Если есть следующий
      if(cur->next != NULL) {
        cout << "Next: " << cur->next->value << endl;
        // У следующего prev заменяем на на prev
        cur->next->prev = cur->prev;
      }

      // Если есть предыдущий
      if(cur->prev != NULL) {
        cout << "Prev: " << cur->prev->value << endl;
        // У предыдущего next заменяем на наш next
        cur->prev->next = cur->next;
      } else {
        // Мы удаляем первый элемент, поэтому
        // root должен указывать на второй
        root = cur->next;
      }

      delete cur;
      return;
    }
  }

  cout << value << " - not found!" << endl;
}

// Удалить по индексу
void deleteByIndex(int index) {

}

void showList() {
  cout << endl << "List: " << endl;
  List2* curElement = root;

  while(curElement != NULL) {
    cout << curElement->value << endl;
    curElement = curElement->next;
  }
}

int main() {
  addToEnd("Apple");
  addToEnd("Banana");
  addToEnd("Orange");

  showList();

  addToBegin("New first");

  showList();

  // Удалим первый элемент
  deleteFirst();

  // Снова посмотрим список
  showList();

  // Удаляем средний
  deleteByValue("Banana");

  showList();

  // Удаляем первый элемент
  deleteByValue("Orange");
  showList();

  // Удаляем единственный элемент
  deleteByValue("Apple");
  showList();

  addToBegin("Apple1");
  addToBegin("Apple2");
  addToBegin("Apple3");
  // Удаляем последний элемент
  deleteByValue("Apple1");
  showList();

  return 0;
}
