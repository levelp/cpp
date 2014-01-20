#include <iostream>

using namespace std;

// Реализация структуры данных "Список"

// Элемент списка
struct ListElement {
  int value; // Значение элемента списка
  ListElement *next; // Указатель на следующий элемент списка
};

struct List {
  ListElement *root; // Указатель на первый элемент

  // Конструктор
  List(){
    cout << "Constructor" << endl;
    root = NULL;
    // Так нельзя (!!!):
    // root->next = NULL;
  }

  // Деструктор - метод, который вызывается при
  // уничтожении объекта
  ~List(){
    cout << "Destructor" << endl;
    ListElement *cur = root;
    while(cur != NULL){
      root = cur->next;
      delete cur;
      cur = root;
    }
  }

  // Добавить в начало списка
  void addToBegin(int newValue){
    // Заводим новый элемент списка в динамической памяти
    ListElement *newElement = new ListElement;
    // Записываем в него новое значение
    newElement->value = newValue;
    // (*newElement).value = newValue;
    // Этот элемент должен встать в начало списка,
    // т.е. все остальные элементы будут после него.
    newElement->next = root;
    root = newElement;
  }

  // Показать список
  void show(){
    // Текущий элемент - сначала 1-ый
    int No = 0;
    for(ListElement *cur = root;
          cur != NULL; cur = cur->next){
      cout << ++No << ". " << cur->value << endl;
    }
  }

  // Добавить элемент в конец списка
  void addToEnd(int newValue){
    if(root == NULL){
      addToBegin(newValue);
      return;
    }

    // Идём до последнего элемента
    ListElement *cur = root;
    while(cur->next != NULL){
      cur = cur->next;
    }
    //for(ListElement* cur = root;
    //    cur->next != NULL; cur = cur->next)
    //    /* Ничего не надо делать :) */;

    // Создаём новый элемент
    ListElement *newElement = new ListElement;
    newElement->value = newValue;
    newElement->next = NULL;

    // Новый элемент ставим в конец списка
    cur->next = newElement;
  }
};

int main()
{
    List list; // Создали список
      // List - класс
      // list - объект этого класса
    list.addToBegin(5); // Добавляем 5 в начало
    list.addToBegin(3);
    list.addToBegin(43);
    list.addToBegin(56);
    list.addToEnd(111);
    list.show();

    int *a, b;

    return 0;
}
