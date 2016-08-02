// Утечки памяти
// -------------
#include <iostream>

using namespace std;

// TODO: SmartPtr для обработки этой ситуации
struct SmartPtr {
}

int main() {
  int* intArray = new int[100];

  for(int i = 0; i < 10; i++) {
    SmartPtr<int[]> intArray = new int[100];

    //delete intArray;
  }

  //delete[] intArray;

  return 0;
}

