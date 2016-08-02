#include <iostream>

using namespace std;

const int arraySize = 3;

int a[] = { 3, 10, 7 },
b[arraySize][arraySize] = {
  { 1, 2, 3 },
  { 4, 5, 6 },
  { 7, 8, 9 }
};

void sumExample() {
  int sum = 0; // В стеке

  for(int i = 0; i < arraySize; ++i) {
    cout << "sum = " << sum;
    sum += a[i];
    cout << " + " << a[i];
    cout << " -> " << sum;
    cout << endl;
  }

  cout << "sum = " << sum << endl;
}

void f() {
  static int calls = 0; // Статические переменные храняться в
  // статической памяти и сохраняют своё значение между вызовами
  calls++;
  int localVar = 3;
  cout << "f -> " << calls << endl;
}

int main() {
  static int ii = 3; // В Статической области памяти
  int hh = 10; // В Стеке

  f();
  f();
  f();
  f();
  f();
  f();

  cout << "a[0] = " << a[0] << endl;
  cout << "b[2][2] = " << b[2][2] << endl;

  sumExample();

  int myArray[] = {3, 10, 20, 43};

  for(int i = 0; i < 4; ++i)
    cout << "myArray[" << i << "] = " << myArray[i] << endl;

  // myArray[0] = 3
  // myArray[1] = 10
  // myArray[2] = 20
  // myArray[3] = 43

  return 0;
}
