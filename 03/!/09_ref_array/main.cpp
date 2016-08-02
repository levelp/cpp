#include <iostream>

using namespace std;

int main() {
  int A[100];
  int* X;
  A[0] = 42;
  A[1] = 56;

  int* B = A; // B - второе имя для массива A
  // int& B[100] = A;
  int*& Y = X;  // Y - второй имя для переменной X

  int K = 10;

  //cout << &*Y /* <=> */ Y

  cout << A[0] << endl;
  cout << *A << endl;

  cout << A[1] << endl;
  cout << *(A + 1) << endl;

  cout << B[0] << endl;
  cout << *B << endl;

  cout << B[1] << endl;
  cout << *(B + 1) << endl;



  return 0;
}
