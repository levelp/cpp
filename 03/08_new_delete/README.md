Динамическая память new / delete
--------------------------------
``` cpp
struct MyStruct {
  int a, b;
  double d;
};

int main() {
  // Отводим динамическую память
  MyStruct* p = new MyStruct;
  // p - указатель на динамическую память

  // Освобождаем динамическую память
  delete p; // new без скобок, delete без скобок

  // "Заводим" массив в динамической памяти
  int* intArray = new int[1000];

  // Освобождаем память
  delete[] intArray; // освобождаем со []

  int** array2D = new int* [100];

  for(int i = 0; i < 100; ++i)
    array2D[i] = new int[100];

  // Используем
  array2D[1][3] = 100;

  for(int i = 0; i < 100; ++i)
    delete[] array2D[i];

  delete[] array2D;

  int* array2Dx[100];

  for(int i = 0; i < 100; ++i)
    array2Dx[i] = new int[100];

  // Используем
  array2Dx[1][3] = 100;

  // Очищаем память
  for(int i = 0; i < 100; ++i)
    delete[] array2Dx[i];

  return 0;
}
```

[main.cpp](main.cpp)

