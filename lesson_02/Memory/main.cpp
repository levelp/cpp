#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// Статическая память
int globalVar = 2;

void myFunc() {
  int localVar = 3; // Стек
  static int staticVar = 10; // Статическая память
}

using namespace std;

int a; // статическая память
int* aa;

void func() {
  char buf[10000]; // Стек
  static char bufs[10000]; // Статическая область памяти
}

const int SIZE = 200000000;

int veryBigArray[SIZE];

int main() {
  cout << "sizeof(veryBigArray) = " <<  sizeof(veryBigArray) << endl;

  for(int i = 0; i < SIZE; ++i)
    veryBigArray[i] = i;

  cout << "before" << endl;
  {
    //   int veryBigArray[SIZE];
  }
  cout << "after" << endl;

  int varInMain = 22; // Стек
  int* intArray; // Стек
  intArray = (int*)malloc(100); // Дин. память
  intArray[0] = 10;
  printf("intArray[0] = %d\n", intArray[0]);
  free(intArray);

  int* a, b; // a - указатель, b - значение
  // int *a,b;
  // int *a; int b;
  // int *a,*b; - теперь оба указателя
  a = (int*)malloc(sizeof(int));
  // a = (int *)12312;
  *a = 2;
  printf("a = %d\n", a);
  printf("*a = %d\n", *a);
  b = 3;

  return 0;
}
