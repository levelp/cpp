<!-- doc.py -->
Работа с указателями: реализация односвязанного списка в динамической памяти
============================================================================
Один элемент списка:
``` cpp
struct ListElement {
  int value; // Значение элемента списка
  ListElement* next; // Указатель на
  // следующий элемент списка
};
```

Нужно реализовать список целиком, со всеми операциями:
``` cpp
struct List {
  // Указатель на первый элемент списка
  // ListElement *root = NULL;
  ListElement* root;
  // Конструктор - метод, который вызывается
  // при создании объекта (экземпляра класса)
  List() : root(NULL)  { // Указатель на первый элемент
    // NULL - означает что нет ни одного элемента в списке
  }
  // Деструктор (очистка памяти)
  ~List() {
```

``` cpp
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
```

[main.cpp](main.cpp)

