// Поиск минимума в двухмерном массиве
#include <QCoreApplication>
#include <iostream>
#include <limits>

using namespace std;

int main() {
  int i;
  int j;
  int arraySize = 3;
  int num[arraySize][arraySize];
  // Инициализируем максимальным числом для типа int
  int min = 1 << 31; //num[0][0];
  cout << min << endl;

  for(i = 0; i < arraySize; i++) {
    for(j = 0; j < arraySize; j++) {
      cout << "num [" << i << "][" << j << "] = ";
      cin >> num[i][j];

      if(num[i][j] < min)
        min = num[i][j];
    }
  }

  cout << min << endl;


  return 0;
}
