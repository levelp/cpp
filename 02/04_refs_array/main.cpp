// Указатели, ссылки и массивы
// ---------------------------
#include <iostream>
#include <cassert>

using namespace std;

#define SHOW(x) cout << #x << " = " << x << endl;

//-->
int main() {
  int A[100];
  A[0] = 42;
  A[1] = 56;
  SHOW(A[0])
  SHOW(*A + 10);

  int* X;

  int* B = A; // B - второе имя для массива A
  SHOW(B[0]);
  B[1] = 99;
  SHOW(A[1]); // 99

  A[1] = 101;
  B = A + 1; // Сдвиг на один элемент
  SHOW(A[1]) // 101
  SHOW(B[0]) // 101

  int*& Y = X; // Y - второй имя для переменной X
  X = new int[100];
  int* Z = X;
  X[10] = 55;
  assert(Y[10] == X[10]);
  assert(Z[10] == X[10]);

  X = new int[100];
  X[10] = 56;
  assert(Y[10] == X[10]);
  // Не работает: assert(Z[10] == X[10]);

  int a1 = 10, a2 = 4;
  //  int& BB[] = { &a1, &a2 };
  // TODO: разобраться

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
//<--
