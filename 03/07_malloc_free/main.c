/// Динамическая память: malloc / free
/// ----------------------------------
#include <stdio.h>
#include <stdlib.h>

int intStatic[100]; // Статическая память

int main() {
  static int intStatic2[100]; // Статическая память
  int intStack[100]; // Стек
  //-->
  int stackArray[100]; // Массив в стеке
  int* intArray; // Стек
  intArray = 10; // Стек
  // Получение области динамической памяти
  intArray = malloc(100); // Отводим память - 100 байт
  intArray = malloc(70 * sizeof(int)); // 70 целых чисел

  if(intArray == NULL) { // Памяти не хватило
    printf("No memory :(");
    return;
  }

  // Пользуемся как обычным массивом
  intArray[0] = 10;

  // Освобождение памяти
  free(intArray);
  intArray = NULL;
  //<--

  // Сумма элементов массива
  int N, i;
  printf("N = ");
  scanf("%d", &N);
  // Заводим в динамической памяти массив целых
  // чисел размером N
  int* A = malloc(N * sizeof(int));

  // Вводим элементы массива с клавиатуры
  for(i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    //scanf("%d", A+i );
  }

  // Считаем сумму
  int sum = 0;

  for(i = 0; i < N; i++)
    sum += A[i];

  printf("sum = %d\n", sum);
  // Освобождаем память
  free(A);

  return 0;
}
