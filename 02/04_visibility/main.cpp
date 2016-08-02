#include <iostream>

using namespace std;

int globalVar = 10;

double* x;

int main() {
  int i = 10;
  {
    int j = 120;
    j++;
    i++;

    for(int k = 10; k < 100; ++k) {
      k += 10;
      double k = 100;
    }

    globalVar = i + j;
  }
  {
    double j = 11;
    double array[100];

    double* array1 = new double[100];

    x = array1;
  }
  //x[0]
  return 0;
}
