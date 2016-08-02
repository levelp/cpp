Элемент стека
``` cpp
struct StackElement {
  int value; // Значение элемента стека
  StackElement* next; // Указатель на следующий элемент стека
};
```

``` cpp
class Stack { // Можно использовать struct
  StackElement* root;
```

Конструктор:
------------
* называется так же как класс
* нет возвращаемого значения
* параметры как у обычных методов
* цель - инициализация объекта
``` cpp
  Stack() : root(NULL) { }
```

Деструктор
----------
Очистка памяти, освобождение ресурсов
``` cpp
  ~Stack() {
    while(root != NULL) {
      StackElement* saveForDelete = root;
      root = root->next;
      delete saveForDelete;
    }
  }
```

Поместить значение на вершину стека
``` cpp
  void push(int newValue) {
    // Создали новый элемент стека с новым значением
    StackElement* newElement = new StackElement;
    newElement->value = newValue;
    // "Подвешиваем" root к новому элементу
    newElement->next = root;
    // Делаем новый элемент первым в списке
    root = newElement;
  }
```

Получить значение с вершины стека
``` cpp
  int pop() {
    if(root == NULL) {
      cout << "Stack is empty!" << endl;
      return 0;
    }

    // Получаем верхний элемент
    StackElement* topElement = root;
    // Получаем значение верхнего элемента
    int value = topElement->value;
    // Переставим корень списка на след. элемент
    root = topElement->next;
    // Очистим память
    delete topElement;
    // Вернём значение
    return value;
  }
```

Показать все элементы
``` cpp
  void show() {
    for(StackElement* cur = root;
        cur != NULL;
        cur = cur->next)
      cout << cur->value << endl;
  }
```

Использование стека
``` cpp
  Stack s;
  s.push(2);
  s.push(4);
  s.push(5);
  s.show();
  cout << "pop result = " << s.pop() << endl;
  s.show();
```

Д.з. однонаправленный список
----------------------------
[main.cpp](main.cpp)

