<!-- doc.py -->
Очередь на основе массива
-------------------------
Хранение:
``` cpp
int data[QUEUE_LEN]; // Массив для элементов
int head = 0; // Индекс первого элемента очереди
int tail = 0; // Индекс первой свободной ячейки очереди
```

Добавить элемент в конец очереди:
``` cpp
void put(int value) {
  data[tail++ % QUEUE_LEN] = value;
}
```

Получить значение из начала очереди:
``` cpp
int get() {
  return data[head++ % QUEUE_LEN];
}
```

Тестирование:
``` cpp
  put(3);
  cout << get() << endl;
```

[main.cpp](main.cpp)

