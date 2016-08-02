Реализация структуры данных "Список"
------------------------------------
Элемент списка
``` cpp
struct ListElement {
  int value; // Значение элемента списка
  ListElement* next; // Указатель на следующий элемент списка
};
```

Список целиком
``` cpp
struct List {
  ListElement* root; // Указатель на первый элемент

  // Конструктор
  List() {
    cout << "Constructor" << endl;
    root = NULL;
    // Так нельзя (!!!):
    // root->next = NULL;
  }

  // Деструктор - метод, который вызывается при
  // уничтожении объекта
  ~List() {
    cout << "Destructor" << endl;
    ListElement* cur = root;

    while(cur != NULL) {
      cur = cur->next;
      delete root;
      root = cur;
    }
  }

  // Добавить в начало списка
  void addToBegin(int newValue) {
    // Заводим новый элемент списка в динамической памяти
    ListElement* newElement = new ListElement;
    // Записываем в него новое значение
    newElement->value = newValue;
    // (*newElement).value = newValue;
    // Этот элемент должен встать в начало списка,
    // т.е. все остальные элементы будут после него.
    newElement->next = root;
    root = newElement;
  }

  // Показать список
  void show() {
    // Текущий элемент - сначала 1-ый
    int No = 0;

    for(ListElement* cur = root;
        cur != NULL; cur = cur->next)
      cout << ++No << ". " << cur->value << endl;
  }

  // Добавить элемент в конец списка
  void addToEnd(int newValue) {
    if(root == NULL) {
      addToBegin(newValue);
      return;
    }

    // Идём до последнего элемента
    ListElement* cur = root;

    while(cur->next != NULL)
      cur = cur->next;

    //for(ListElement* cur = root;
    //    cur->next != NULL; cur = cur->next)
    //    /* Ничего не надо делать :) */;

    // Создаём новый элемент
    ListElement* newElement = new ListElement;
    newElement->value = newValue;
    newElement->next = NULL;

    // Новый элемент ставим в конец списка
    cur->next = newElement;
  }

  // Удаляем элемент списка по значению
  void deleteByValue(int value) {
    cout << "deleteByValue(" << value << ")" << endl;

    // Если список пуст, то искать в нём нечего
    if(root == NULL)
      return;

    // Если первое значение подходит, то удаляем первый элемент
    if(root->value == value) {
      ListElement* toDelete = root;
      root = root->next;
      delete toDelete;
      return;
    }

    ListElement* cur = root;

    // Ищем значение
    while((cur->next != NULL) &&
          (cur->next->value != value))
      cur = cur->next;

    // Ничего не нашли
    if(cur->next == NULL) {
      cout << value << " not found!" << endl;
      return;
    }

    // Мы нашли элемент, который хотим удалить и это
    ListElement* toDelete = cur->next;
    // Соединяем "концы" цепочки
    cur->next = toDelete->next;

    delete toDelete;
  }

  // Удаляем элемент с заданным индексом
  void deleteAt(int index) {
    cout << "deleteAt(" << index << ")" << endl;

    // Если список пуст, то искать в нём нечего
    if(root == NULL)
      return;

    // Если первое значение подходит, то удаляем первый элемент
    if(index == 0) {
      ListElement* toDelete = root;
      root = root->next;
      delete toDelete;
      return;
    }

    ListElement* cur = root;
    // Ищем значение
    int curIndex = 1;

    while((cur->next != NULL) &&
          (curIndex != index)) {
      cur = cur->next;
      curIndex++;
    }

    // Ничего не нашли
    if(cur->next == NULL) {
      cout << "Index " << index << " not found :)" << endl;
      return;
    }

    // Мы нашли элемент, который хотим удалить и это
    ListElement* toDelete = cur->next;
    // Соединяем "концы" цепочки
    cur->next = toDelete->next;

    delete toDelete;
  }
};
```

Тестирование
``` cpp
  List list; // Создали список
  // List - класс
  // list - объект этого класса
  list.addToBegin(5); // Добавляем 5 в начало
  list.addToBegin(3);
  list.addToBegin(43);
  list.addToBegin(56);
  list.addToEnd(111);
  list.show();

  list.deleteByValue(43);
  list.show();

  list.deleteByValue(102);
  list.show();

  cout << "Delete from begining" << endl;
  list.deleteByValue(56);
  list.show();

  cout << "Delete from end of list" << endl;
  list.deleteByValue(111);
  list.show();

  cout << "-- Delete by index tests --" << endl;
  list.addToBegin(5);
  list.addToEnd(8);
  list.show();
  cout << "Delete from begining" << endl;
  list.deleteAt(0);
  list.show();
  cout << "Delete from end of list" << endl;
  list.deleteAt(2);
  list.show();

  list.deleteAt(2);
  list.show();
```

[main.cpp](main.cpp)

