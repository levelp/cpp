delete и delete[]
-----------------
Пусть у нас есть структура
``` cpp
struct Point {
  double x, y;
};
```

``` cpp
  // Заводим массив в динамической памяти
  int* intArray;
  intArray = new int[1000]; // new со скобками []
  intArray[0] = 10;
  intArray[1] = 23;
  delete[] intArray; // И delete должен быть со скобками

  Point* p = new Point;
  delete p; // delete без скобочек []
```

[main.cpp](main.cpp)

