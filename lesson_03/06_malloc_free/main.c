// Динамическая память: malloc / free
// ----------------------------------
#include <stdio.h>
#include <stdlib.h>

int main() {
  //-->
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
  //<--

  return 0;
}
