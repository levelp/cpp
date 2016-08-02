#include <iostream>

using namespace std;

const int STATIC_SIZE = 300000000;
const int STACK_SIZE = 520000;

int staticArray[STATIC_SIZE];

int main() {
  // Заполняем статический массив значениями
  for(int i = 0; i < STATIC_SIZE; i++)
    staticArray[i] = i;

  cout << "static " << sizeof(staticArray) << endl;

  // Создаём массив в стеке и заполняем значениями
  int stackArray[STACK_SIZE];

  for(int i = 0; i < STACK_SIZE; i++)
    stackArray[i] = i;

  cout << "stack " << sizeof(stackArray) << endl;

  cout << "static / stack = " <<
       (sizeof(staticArray) / sizeof(stackArray)) << endl;
  return 0;
}
