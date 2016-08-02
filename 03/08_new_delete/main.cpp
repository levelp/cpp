/// Динамическая память new / delete
/// --------------------------------
#include <iostream>

using namespace std;

//-->
struct MyStruct {
  int a, b;
  double d;
};

int main() {
  // Отводим динамическую память
  MyStruct* p = new MyStruct;
  // p - указатель на динамическую память
  p->a = 10;
  p->b = 20;
  p->d = 10;

  // Освобождаем динамическую память
  delete p; // new без скобок [], delete без скобок []

  // "Заводим" массив в динамической памяти
  int* intArray = new int[1000]; // new со []

  // Освобождаем память
  delete[] intArray; // освобождаем со []

  // 2D массив
  int** array2D = new int* [100];

  for(int i = 0; i < 100; ++i)
    array2D[i] = new int[100];

  // Используем
  array2D[1][3] = 100;

  // Удаляем в цикле все строки массива
  for(int i = 0; i < 100; ++i)
    delete[] array2D[i];

  // Удаляем массив строк
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
//<--
