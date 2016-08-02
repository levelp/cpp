void dyn_array() {
  int x = 5;  // x целого типа, инициализируем значением 5
  int *y;     // y - указатель на переменную целого типа
  int *array,
      intVar = 1;  // array - указатель на int, intVar - просто переменная int
  int N = 10;      // Количество элементов
  array = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    array[i] = i * i;  // 100...109
  }
  // 3.14f-float  3.14-double
  for (int i = 0; i < N; i++) {
    printf("array[%d] = %d %s %f\n", i, array[i], "Hi!",
           3.14);  // %d - целые числа
    // \n - перевод строки
  }
  free(array);  // Очистка памяти
}
