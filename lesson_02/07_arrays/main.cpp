#include <iostream>

using namespace std;

int main() {
  // Массивы
  // Одномерные
  //-->
  int intArray[10];
  // int - тип элементов массива
  // intArray - название массива
  // 10 - количество элементов
  // Нумерация элементов: 0..9

  // Записываем 23 в первый элемент массива
  intArray[0] = 23;
  intArray[1] = 10; // Второй элемент массива

  cout << intArray[0] + intArray[1] << endl;

  // Увеличить каждый элемент массива на 10
  for(int i = 0; i < 10; ++i)
    intArray[i] += 10;

  // Поиск минимума в массиве
  int minValue = intValue[0];

  for(int i = 1; i < 10; ++i)
    if(intArray[i] < minValue)
      minValue = intArray[i];

  // Поиск максимума в массиве
  int maxValue = intValue[0];

  for(int i = 1; i < 10; ++i)
    if(intArray[i] > maxValue)
      maxValue = intArray[i];

  //<--

  return 0;
}
