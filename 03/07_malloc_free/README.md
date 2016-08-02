Динамическая память: malloc / free
----------------------------------
``` cpp
  int* intArray;
  intArray = malloc(100); // Отводим память - 100 байт
  intArray = malloc(70 * sizeof(int)); // 70 целых чисел

  if(intArray == NULL) {
    // Памяти не хватило
    printf("No memory :(");
    return;
  }

  intArray[0] = 10;

  // Освобождение памяти
  free(intArray);
```

[main.c](main.c)

